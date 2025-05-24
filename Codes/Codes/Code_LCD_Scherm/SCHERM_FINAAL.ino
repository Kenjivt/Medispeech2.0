#include <SPI.h>
#include <TFT_eSPI.h>

#define RX_PIN D7
#define TX_PIN D6
#define BAUD 115200

TFT_eSPI tft = TFT_eSPI();

const float R1 = 100000.0;
const float R2 = 47000.0;
const float refVoltage = 5.0;
const float maxVoltage = 9.0;
const float minVoltage = 6.0;

const int buttonPin = D3;
const int verwijderpin = D5;
const int batteryPin = A0;

int lastState = HIGH;
int lastState2 = HIGH;

bool isOpname = false;
bool toonBatterij = false;
bool batterijTonenActief = false;
bool blauwActief = false;

unsigned long stopMoment = 0;
unsigned long blauwMoment = 0;
const unsigned long schermDuur = 3000;

void setup() {
  digitalWrite(LED_BUILTIN, HIGH);
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_GREEN);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(verwijderpin, INPUT_PULLUP);
  pinMode(batteryPin, INPUT);

  Serial.begin(115200);      // Debug
  Serial1.begin(BAUD, SERIAL_8N1, RX_PIN, TX_PIN);
}

void loop() {
  int knop = digitalRead(buttonPin);
  int verwijder = digitalRead(verwijderpin);

  int rawValue = analogRead(batteryPin);      
  float voltage = rawValue * (refVoltage / 1023.0) * ((R1 + R2) / R2);
  int batteryPercentage = constrain(map(voltage, minVoltage, maxVoltage, 0, 100), 0, 100);

  // Hoofdknop gedrukt
  if (knop == LOW && lastState == HIGH && !blauwActief) {
    batterijTonenActief = false;

    if (!isOpname) {
      isOpname = true;
      toonBatterij = false;
      Serial.println("STUUR START");
      Serial1.println("START");

      tft.fillScreen(TFT_GREEN);
      tekenMicrofoonIcoon(80, 140);
      tft.setTextColor(TFT_BLACK);
      tft.setCursor(10, 30);
      tft.setTextFont(4);
      tft.setTextSize(2);
      tft.print("Opname gestart");

    } else {
      isOpname = false;
      toonBatterij = true;
      stopMoment = millis();
      Serial.println("STUUR STOPT");
      Serial1.println("STOPT");

      tft.fillScreen(TFT_RED);
      tekenGroeneCheckbox(80, 140);
      tft.setTextColor(TFT_BLACK);
      tft.setCursor(10, 30);
      tft.setTextSize(2);
      tft.print("Opname gestopt");
    }

    delay(200);
  }

  // Verwijderknop gedrukt
  if (verwijder == LOW && lastState2 == HIGH) {
    batterijTonenActief = false;

    tft.fillScreen(TFT_BLUE);
    tekenRoodKruis(80, 140);
    tft.setTextColor(TFT_BLACK);
    tft.setCursor(10, 30);
    tft.setTextSize(2);
    tft.println("Opname");
    tft.setCursor(5, 70);
    tft.println("verbroken");

    blauwMoment = millis();
    blauwActief = true;

    isOpname = false;
    toonBatterij = true;
    stopMoment = millis();
  }

  if (blauwActief && millis() - blauwMoment > schermDuur) {
    tft.fillScreen(TFT_BLACK);
    blauwActief = false;
  }

  if (toonBatterij && millis() - stopMoment > schermDuur) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE);
    tft.setCursor(10, 100);
    tft.setTextSize(2);
    tft.print("Batterij:");
    tft.setCursor(10, 140);
    tft.print(batteryPercentage);
    tft.print("%");

    toonBatterij = false;
    batterijTonenActief = true;
  }

  lastState = knop;
  lastState2 = verwijder;
}

// ---------------------- Tekenfuncties ------------------------

void tekenMicrofoonIcoon(int x, int y) {
  tft.drawCircle(x + 40, y + 40, 40, TFT_BLACK);
  tft.fillRoundRect(x + 30, y + 20, 20, 40, 10, TFT_BLACK);
  tft.fillCircle(x + 40, y + 40, 6, TFT_RED);

  for (int r = 18; r <= 21; r++) {
    for (float angle = PI / 2; angle <= PI; angle += 0.05) {
      int x1 = x + 40 + cos(angle) * r;
      int y1 = y + 45 + sin(angle) * r;
      tft.drawPixel(x1, y1, TFT_BLACK);
    }
  }

  for (int r = 18; r <= 21; r++) {
    for (float angle = 0; angle <= PI / 2; angle += 0.05) {
      int x1 = x + 40 + cos(angle) * r;
      int y1 = y + 45 + sin(angle) * r;
      tft.drawPixel(x1, y1, TFT_BLACK);
    }
  }

  tft.fillRect(x + 38, y + 66, 4, 10, TFT_BLACK);
  tft.fillRect(x + 30, y + 75, 20, 3, TFT_BLACK);
}

void tekenGroeneCheckbox(int x, int y) {
  int boxSize = 70;
  int radius = 10;
  tft.fillRoundRect(x, y, boxSize, boxSize, radius, TFT_GREEN);
  tft.drawRoundRect(x, y, boxSize, boxSize, radius, TFT_GREEN);
  for (int i = -1; i <= 1; i++) {
    tft.drawLine(x + 10 + i, y + 30, x + 25 + i, y + 50, TFT_WHITE);
    tft.drawLine(x + 25 + i, y + 50, x + 55 + i, y + 10, TFT_WHITE);
  }
}

void tekenRoodKruis(int x, int y) {
  int grootte = 70;
  int radius = 10;
  int marge = 15;
  tft.fillRoundRect(x, y, grootte, grootte, radius, TFT_RED);
  tft.drawRoundRect(x, y, grootte, grootte, radius, TFT_RED);
  for (int i = -1; i <= 3; i++) {
    tft.drawLine(x + marge + i, y + marge, x + grootte - marge + i, y + grootte - marge, TFT_WHITE);
    tft.drawLine(x + grootte - marge + i, y + marge, x + marge + i, y + grootte - marge, TFT_WHITE);
  }
}
