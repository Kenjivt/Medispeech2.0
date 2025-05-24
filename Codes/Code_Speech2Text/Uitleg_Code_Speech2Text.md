# Uitleg

## WIFI

- Op **lijn 27** vul je de naam van het WiFi-netwerk in (`WIFI_SSID`).
- Op de lijn eronder geef je het wachtwoord in (`WIFI_PASSWORD`).
- Zorg ervoor dat beide waarden tussen dubbele aanhalingstekens staan, bijvoorbeeld:
const char* WIFI_SSID = "mijnNetwerkNaam"
const char* WIFI_PASSWORD = "mijnWachtwoord"

## IP-Adres

De XIAO ESP32 heeft het IP-adres nodig van de computer waarmee hij verbinding maakt.

- Op **lijn 198** in de code staat momenteel een IP-adres ingevuld. Dit moet vervangen worden door het IP-adres van je eigen computer.

### IP-adres opvragen (Windows)

1. Open **Windows PowerShell**.
2. Voer het volgende commando uit:
Get-NetIPAddress

3. Zoek in de lijst naar het IP-adres dat bij je actieve netwerkadapter hoort.
   - Dit staat meestal twee regels onder het kopje `WIFI`.
 
![afbeelding](https://github.com/user-attachments/assets/c5dd5a35-ba1b-4f02-a7bf-768b66dd531a)

### Voorbeeld van gebruik

Kopieer het IP-adres en plak dit na `http://` en vóór `:8888/uploadAudio` in de volgende regel:

client.begin("http://172.168.1.15:8888/uploadAudio");
