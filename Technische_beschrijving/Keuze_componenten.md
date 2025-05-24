
## Keuze componenten


### Vergelijking van Microcontrollers

De onderstaande tabel vergelijkt vijf microcontrollers op basis van relevante selectiecriteria voor draagbare, spraakgestuurde toepassingen binnen een medische context. Belangrijke factoren zijn cloudfunctionaliteit (voor opslag en verwerking), verwerkingssnelheid, nauwkeurigheid, prijs, formaat (draagbaarheid), beschikbaarheid (bij o.a. Gotron Gent, Kiwi Electronics) en gebruiksgemak.

| Microcontroller               | Cloud nodig  | Snelheid    | Nauwkeurigheid | Prijs (€) | Compact       | Beschikbaar  | Gebruiksgemak    |
|-------------------------------|--------------|-------------|----------------|-----------|---------------|--------------|------------------|
| **XIAO ESP32S3**              | Nee / Ja     | Gemiddeld   | Laag           | 10 – 15   | Zeer klein    | Makkelijk    | Gemiddeld        |
| **XIAO ESP32S3 Sense**        | Nee / Ja     | Gemiddeld   | Laag           | 15 – 20   | Zeer klein    | Makkelijk    | Gemiddeld        |
| **Raspberry Pi 4**            | Nee          | Snel        | Goed           | 60 – 80   | Groot         | Makkelijk    | Moeilijk         |
| **Raspberry Pi Zero 2 W (+ Vosk)** | Nee / Ja | Gemiddeld   | Goed           | 20 – 25   | Gemiddeld     | Makkelijk    | Moeilijk         |
| **Jetson Nano**               | Nee          | Zeer snel   | Zeer goed      | 100+      | Groot         | Moeilijk     | Zeer moeilijk     |

---

### Gekozen component: **XIAO ESP32S3 Sense**

Op basis van prijs, formaat en praktische toepasbaarheid werd gekozen voor de **XIAO ESP32S3 Sense**. Deze microcontroller is:

- **Compact en licht**, ideaal voor draagbaar gebruik in zorgcontext.
- **Betaalbaar en goed beschikbaar**, o.a. bij Gotron en Kiwi Electronics.
- **Cloud-compatibel**, wat uitbreidingsmogelijkheden biedt voor toekomstige data-opslag of verwerking.
- **Gebruiksvriendelijk**, geschikt voor snelle implementatie zonder zware technische drempel.

Hoewel de standaard nauwkeurigheid van de ingebouwde microfoon beperkt is, kan dit sterk verbeterd worden door een **INMP441-microfoon** toe te voegen. Deze upgrade verhoogt zowel de **herkenningsnauwkeurigheid** als de **lengte van verwerkbare zinnen**, wat cruciaal is voor medische spraakopnames.

Daarnaast beschikt de **XIAO ESP32S3 Sense** over:

- **Ingebouwde microfoon**: Geen externe hardware nodig.
- **Micro-SD kaartslot**: Voor lokale opslag van data zonder cloudafhankelijkheid.

> Ondanks de iets hogere prijs, biedt de **XIAO ESP32S3 Sense** meer functionaliteit out-of-the-box, waardoor het de meest efficiënte keuze is voor een werkend prototype binnen dit project.

**Netwerkvertraging bij cloudgebruik** blijft minimaal (tussen 0,5 en 3 seconden met stabiele wifi), wat aanvaardbaar is in de meeste zorgsituaties.

---


## Opties voor batterij-indicatie en feedbackcomponenten

In dit overzicht worden verschillende hardware-opties geëvalueerd voor het tonen van het batterijniveau en het geven van statusfeedback (zoals "opname bezig"). De opties variëren van eenvoudige LED's tot geavanceerde displays. Elke component wordt beoordeeld op prijs, gebruiksgemak en toepasbaarheid binnen het ontwerp.

<details>
  <summary>Vergelijking componenten – batterij-indicatie en statusfeedback</summary>

### Batterij-indicatiecomponenten

| Component                | Afbeelding | Prijs        | Voordelen                                                     | Nadelen                                                                 | Gebruiksgemak (1–5) |
|--------------------------|------------|--------------|---------------------------------------------------------------|-------------------------------------------------------------------------|---------------------|
| RGB LED                  | ![link](https://m.media-amazon.com/images/I/614cMy1Ha2L.jpg) | €0,50 – €1   | - Zeer eenvoudig aan te sturen <br> - Lage kostprijs          | - Beperkte informatie <br> - Verwarring bij meervoudig gebruik         | 5                   |
| LED bar graph (10-segment) | ![link](https://ls.codetech.nl/shops/346407/files/420562667/otronic-10-segment-led-bar-groen.jpg) | €1,50        | - Visueel duidelijk <br> - Lage kostprijs                     | - Groter formaat <br> - Complexere bekabeling                          | 4                   |
| RGB OLED display         | ![link](https://shop.mchobby.be/4572-medium_default/graphic-oled-display-128x128-16-bits-colors.jpg) | €7 – €30     | - Compact en visueel aantrekkelijk <br> - Multifunctioneel     | - Hogere kostprijs <br> - Complexere aansturing en stroomverbruik      | 4                   |
| 7-segment display        | ![link](https://cdn.bodanius.com/media/1/7ae103081_7-segment-led-display-blauw-common-cathode_x.png) | €1 – €3 per segment | - Goed leesbaar voor cijfers                                  | - Beperkt tot cijfers <br> - Neemt relatief veel ruimte in             | 3                   |

#### Statusfeedbackcomponenten

| Component                | Afbeelding | Prijs        | Voordelen                                                     | Nadelen                                                                 | Gebruiksgemak (1–5) |
|--------------------------|------------|--------------|---------------------------------------------------------------|-------------------------------------------------------------------------|---------------------|
| RGB LED                  | ![link](https://m.media-amazon.com/images/I/614cMy1Ha2L.jpg) | €0,50 – €1   | - Eenvoudig en goedkoop                                       | - Klein formaat <br> - Kan onduidelijk zijn bij meerdere functies       | 5                   |
| LCD display              | ![link](https://m.media-amazon.com/images/I/51jy8enJluL._AC_UF1000,1000_QL80_.jpg) | €3,50 – €7   | - Goedkoper alternatief voor tekstweergave                   | - Geen kleur of grafieken <br> - Iets complexere aansluiting            | 4                   |
| RGB OLED display         | ![link](https://shop.mchobby.be/4572-medium_default/graphic-oled-display-128x128-16-bits-colors.jpg) | €7 – €30     | - Volledig grafisch, kleuren en tekst <br> - Compact          | - Duurder <br> - Meer stroomverbruik                                   | 4                   |

</details>

## Gekozen oplossing: RGB OLED display

Voor dit project is gekozen voor een **RGB OLED display**, omdat het zowel batterijstatus als systeemfeedback duidelijk en visueel aantrekkelijk kan weergeven. Het combineert functionaliteit en esthetiek, is relatief compact en sluit goed aan bij het beoogde ontwerp. De hogere kost en complexere aansturing worden gecompenseerd door de veelzijdigheid en duidelijke feedback.

---

## Batterijopties voor XIAO ESP32S3

| Batterijtype               | Voltage (V)     | Capaciteit (mAh)     | Prijs (€)   | Voordelen                                  | Nadelen                       | Gebruiksgemak (1–5) |
|----------------------------|------------------|------------------------|-------------|--------------------------------------------|-------------------------------|---------------------|
| LiPo 3.7V                  | 3.7 (max 4.2)     | 350 – 2000             | €10 – €15   | Compact en licht                           | Gevoelig voor schade          | 3                   |
| Li-ion 18650 (1 cel)       | 3.7 (max 4.2)     | 2500 – 3000            | €8 – €15    | Hoge capaciteit, veilig met houder         | Groter formaat, zwaarder      | 4                   |
| 3x AAA (herlaadbaar)       | 3.6 (3x 1.2V)     | (800–1000) x 3         | €5 – €15    | Hoge beschikbaarheid, veilig               | Groot en zwaar                | 4                   |
| Powerbank (USB)            | 5.0               | 2000 – 10000           | €10 – €40   | Zeer hoge capaciteit, ingebouwde beveiliging| Groot en zwaar                | 4                   |

> *Er werd nog geen definitieve keuze gemaakt i.v.m. de batterij wegens tijdsgebrek.*

---

## Berekening batterijduur

Berekend met de formule:  
**Batterijduur (uren) = Capaciteit (mAh) / Verbruik (mA)**

Gemiddeld stroomverbruik XIAO ESP32S3:
- Actief: ~200 mA  
- Deep Sleep: ~15 mA

| Batterij                   | Capaciteit (mAh) | Normaal gebruik (~200 mA) | Deep Sleep (~15 mA)       |
|----------------------------|------------------|-----------------------------|----------------------------|
| LiPo 500 mAh               | 500              | ~2,5 uur                    | ~33 uur                    |
| LiPo 1000 mAh              | 1000             | ~5 uur                      | ~66 uur                    |
| LiPo 2000 mAh              | 2000             | ~10 uur                     | ~132 uur (5,5 dagen)       |
| 18650 Li-ion (2500 mAh)    | 2500             | ~12,5 uur                   | ~166 uur (bijna 7 dagen)   |
| 18650 Li-ion (3500 mAh)    | 3500             | ~17,5 uur                   | ~233 uur (9,7 dagen)       |
