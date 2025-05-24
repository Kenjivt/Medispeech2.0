#include <WiFi.h>
#include <HTTPClient.h>
#include <Base64.h>
#include <ESP_I2S.h>
#include <SD.h>
#include <SPI.h>
#include <stdlib.h>
#define RX_PIN D7
#define TX_PIN D6
#define BAUD 115200
#define DEBUG 1

// Opname parameters
#define SAMPLE_RATE 16000U
#define SAMPLE_BITS 16
#define WAV_HEADER_SIZE 44
#define VOLUME_GAIN 2

// I2S en SD
I2SClass I2S;
File file;
const char filename[] = "/recording.wav";
bool isWIFIConnected;
bool isRecording = false;

// WiFi gegevens
const char* WIFI_SSID = "steven_IoT";
const char* WIFI_PASSWORD = "ToIwifi48.";

void debugLog(const char* message) {
  if (DEBUG) {
    Serial.println(message);
    Serial.flush();
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);    // Debug via USB
  Serial1.begin(BAUD, SERIAL_8N1, RX_PIN, TX_PIN); // UART via pinnen

  while (!Serial);
  Serial.print("httpResponseCode||");
  Serial.println("Hallo");

  debugLog("Initializing I2S and SD Card...");

  I2S.setPinsPdmRx(42, 41);

  if (!I2S.begin(I2S_MODE_PDM_RX, SAMPLE_RATE, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO)) {
    debugLog("Failed to initialize I2S!");
    while (1);
  }

  if (!SD.begin(21)) {
    debugLog("Failed to mount SD Card!");
    while (1);
  }

  debugLog("Starting tasks...");
  delay(500);
  xTaskCreate(wifiConnect, "wifi_Connect", 4096, NULL, 1, NULL);
}

void loop() {
  if (Serial1.available()) {
    String received = Serial1.readStringUntil('\n'); // lees tot newline
    received.trim(); // verwijder \r of spaties indien nodig
    Serial.println(received);
  

    if (received == "START" && !isRecording) {
      isRecording = true;
      digitalWrite(LED_BUILTIN, HIGH);
      xTaskCreate(i2s_adc, "i2s_adc", 8192, NULL, 1, NULL);
      debugLog("Opname gestart via UART");
    }

    if (received == "STOPT" && isRecording) {
      isRecording = false; // i2s_adc stopt vanzelf door deze vlag
      digitalWrite(LED_BUILTIN, LOW);
      debugLog("Opname gestopt via UART");
    }
  }
  delay(10);
}

void i2s_adc(void *arg) {
  debugLog("Opname starten...");
  unsigned long startTime = millis();

  file = SD.open(filename, FILE_WRITE);
  if (!file) {
    debugLog("Kan audio-bestand niet openen!");
    vTaskDelete(NULL);
    return;
  }

  writeWavHeader(file, 0);
  int16_t* buffer = (int16_t*)malloc(1024 * sizeof(int16_t));
  if (!buffer) {
    debugLog("Buffer memory allocation failed.");
    file.close();
    vTaskDelete(NULL);
    return;
  }

  uint32_t dataSize = 0;

  while (isRecording) {
    int bytesRead = 0;
    for (int i = 0; i < 1024; i++) {
      buffer[i] = I2S.read();
      bytesRead += sizeof(int16_t);
    }
    if (bytesRead > 0) {
      file.write((uint8_t*)buffer, bytesRead);
      dataSize += bytesRead;
    }
  }

  free(buffer);
  debugLog("Buffer memory freed.");
  writeWavHeader(file, dataSize);
  file.close();

  debugLog("Opname opgeslagen als 'recording.wav'!");

  if (isWIFIConnected) {
    xTaskCreate(uploadFile, "uploadFile", 4096, NULL, 1, NULL);
  }

  vTaskDelete(NULL);
}

void writeWavHeader(File &file, uint32_t dataSize) {
  if (!file) return;
  file.seek(0);
  file.write((const uint8_t*)"RIFF", 4);
  uint32_t chunkSize = 36 + dataSize;
  file.write((uint8_t*)&chunkSize, 4);
  file.write((const uint8_t*)"WAVE", 4);
  file.write((const uint8_t*)"fmt ", 4);
  uint32_t subChunk1Size = 16;
  file.write((uint8_t*)&subChunk1Size, 4);
  uint16_t audioFormat = 1;
  file.write((uint8_t*)&audioFormat, 2);
  uint16_t numChannels = 1;
  file.write((uint8_t*)&numChannels, 2);
  uint32_t sampleRate = SAMPLE_RATE;
  file.write((uint8_t*)&sampleRate, 4);
  uint32_t byteRate = SAMPLE_RATE * numChannels * 2;
  file.write((uint8_t*)&byteRate, 4);
  uint16_t blockAlign = numChannels * 2;
  file.write((uint8_t*)&blockAlign, 2);
  uint16_t bitsPerSample = 16;
  file.write((uint8_t*)&bitsPerSample, 2);
  file.write((const uint8_t*)"data", 4);
  file.write((uint8_t*)&dataSize, 4);
}

void wifiConnect(void *pvParameters) {
  isWIFIConnected = false;
  Serial.println("Disconnecting previous Wi-Fi connection...");
  WiFi.disconnect(true);
  delay(1000);

  Serial.print("Trying to connect to ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  int retryCount = 0;
  while (WiFi.status() != WL_CONNECTED && retryCount < 20) {
    vTaskDelay(500);
    Serial.print(".");
    retryCount++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWi-Fi Connected!");
    isWIFIConnected = true;
  } else {
    Serial.println("\nFailed to connect to Wi-Fi!");
  }
  vTaskDelete(NULL);
}

void uploadFile(void *pvParameters) {
  file = SD.open(filename, FILE_READ);
  if (!file) {
    Serial.println("FILE IS NOT AVAILABLE!");
    vTaskDelete(NULL);
    return;
  }

  Serial.println("===> Uploading FILE to Node.js Server");
  HTTPClient client;
  client.begin("http://192.168.1.15:8888/uploadAudio");
  client.addHeader("Content-Type", "audio/wav");

  int httpResponseCode = client.sendRequest("POST", &file, file.size());
  if (httpResponseCode > 0) {
    Serial.print("httpResponseCode");
    Serial.println(httpResponseCode);

    if (httpResponseCode == 200) {
      String response = client.getString();
      Serial.print("Transcription||");
      for (int i = 0; i < response.length(); i += 256) {
        Serial.println(response.substring(i, i + 256));
        delay(10);
      }
      Serial.println("End");
    } else {
      Serial.println("Server responded with an error!");
    }
  } else {
    Serial.println("Error: Failed to connect to server");
  }

  file.close();
  client.end();
  vTaskDelete(NULL);
}
