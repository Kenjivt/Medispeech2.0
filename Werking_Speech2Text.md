# Werking van Speech-to-Text

Het Medispeech-systeem maakt gebruik van de **XIAO ESP32-Sense** microcontroller – een compacte, energiezuinige module met ingebouwde Wi-Fi en microfoon. Omdat deze microcontroller beperkte rekenkracht heeft, wordt de spraakherkenning extern uitgevoerd via een cloudservice.

---

## Stap-voor-stap werking

1. **Opname starten**  
   Bij een druk op de knop begint de XIAO ESP32-Sense met het opnemen van audio via de ingebouwde microfoon.

2. **Opslag op SD-kaart**  
   De audio-opname wordt opgeslagen als een `.wav`-bestand op de SD-kaart. Dit ongecomprimeerde formaat is ideaal voor nauwkeurige verwerking.

3. **Opname stoppen**  
   Bij een tweede druk op de knop stopt de opname. Het bestand wordt voorbereid voor verzending.

4. **Verzending via Wi-Fi**  
   Via de ingebouwde Wi-Fi wordt het `.wav`-bestand verzonden naar de **Google Cloud Speech-to-Text API**.

5. **Verwerking in de cloud**  
   Google’s AI-gebaseerde service zet de audio om naar tekst. Deze technologie ondersteunt meerdere talen en accenten en is deels gratis te gebruiken (beperkt in tijd en volume).

6. **Ontvangst & weergave van tekst**  
   De herkende tekst wordt teruggestuurd naar de ESP32 en weergegeven via de seriële monitor (bv. in de Arduino IDE). In een uitgebreidere versie kan dit automatisch doorgestuurd worden naar het Medispeech-platform voor verdere verwerking of opslag.

---

## Technische details

- **Beveiliging**: Bestanden worden verzonden via HTTPS-verbindingen.
- **Structuur**: Communicatie gebeurt via JSON-verpakte parameters.
- **Beperkingen**:
  - Maximale bestandsgrootte
  - Maximale opnameduur
  - Snelheid afhankelijk van netwerkverbinding

> Deze beperkingen zijn afhankelijk van de instellingen en limieten van de Google Cloud API.

---

![werking](https://github.com/user-attachments/assets/ab0fabef-1d96-424b-8963-7604f7335b72)
