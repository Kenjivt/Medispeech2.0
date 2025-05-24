# Schema LCD-scherm & Speech-to-Text

## Schema

![Schermafbeelding 2025-05-12 192638](https://github.com/user-attachments/assets/4e8084ab-cb5a-4ada-a3ba-5f778a32077b)

---

## Uitleg

Het schema toont een opstelling met **twee XIAO ESP32-Sense microcontrollers**, elk met een eigen SD-kaart:

- **XIAO B (links)**  
  Verantwoordelijk voor de opname van spraak.

- **XIAO A (rechts)**  
  Stuurt het LCD-scherm aan en verwerkt de feedbackweergave.

De reden voor deze verdeling is dat de **I²C-interface** op de XIAO slechts één taak tegelijk aankan. De microcontroller kan dus **niet gelijktijdig audio opnemen en het scherm aansturen**. Daarom is gekozen voor een **tweede XIAO ESP32-Sense**.

### LCD-scherm
Het weergegeven scherm in het schema is **niet het exacte model** dat in Medispeech wordt gebruikt. Dit alternatief werd gekozen omdat het beschikbare schema via **Wokwi** beperkt is in schermselectie.

### Knoppen
- **Zwarte knop (links)**: Start/stop opname  
- **Witte knop (rechts)**: Onderbreekt de opname

---

## Belangrijke instructies voor gebruik

1. **Sluit alleen XIAO B aan op de computer tijdens het gebruik.**  
   (XIAO A **niet** verbinden met USB, alleen tijdens uploaden)

2. **Upload de LCD-code naar XIAO A.**

3. **Voer stap 7 van de installatie-instructies uit.**

4. **Upload vervolgens de spraakherkenningscode naar XIAO B.**  
   Laat XIAO B **verbonden met de computer** voor communicatie en verwerking.


---

## Xiao A

- 5V naar de 5V van Xiao B
- GND naar GND van het breadboard
- 3,3V naar de VCC van het LCD-scherm
- D10 naar SDA van het LCD-scherm
- D8 naar SCL van het LCD-scherm
- D6 naar D7 van Xiao B
- D5 naar de witte knop
- D4 naar RES van het LCD-scherm
- D3 naar de zwarte knop
- D1 naar DC van het LCD-scherm
- D0 naar CS van het LCD-schermm

  ## Xiao B

  - 5V naar de 5V van Xiao A
  - GND naar de GND van het breadboard
  - D7 naar D6 van Xiao A

  ## LCD-scherm
  - GND naar de GND van het breadboard
  - VCC naar de 3.3V van Xiao A
  - SCL naar D8 van Xiao A
  - SDA naar D10 van Xiao A
  - RES D4 van Xiao A
  - DC naar D1 van Xiao A
  - CS naar D0 van Xiao A
  - BLK wordt niet verbonden
 
  ## Zwarte knop

  - Ene pootje naar D3 van Xiao A
  - Ander pootje naar GND van het breadboard
 
  ## Witte knop

  - Ene pootje naar D5 van Xiao 5
  - Ander pootje naar GND van het breadboard
