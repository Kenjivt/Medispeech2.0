# Installatie

Voordat de codes of componenten gebruikt kunnen worden, moeten eerst het spraak-naar-tekst-systeem en het LCD-scherm correct worden geïnstalleerd. Deze installaties moeten zorgvuldig worden uitgevoerd, anders zal het systeem niet naar behoren functioneren.

## Installatie LCD-scherm

De componenten die nodig zijn voor deze installatie:
- **XIAO ESP32S3 SENSE** [Link](https://www.tinytronics.nl/en/development-boards/microcontroller-boards/with-wi-fi/seeed-studio-xiao-esp32-s3-sense)
- **1,3'IPS_LCD 240*240(RGB)** [Link](https://www.tinytronics.nl/en/displays/tft/1.3-inch-ips-tft-display-240*240-pixels-spi-st7789v3)

## Stappenplan

<details>
<summary>Stap 1: Download TFT_eSPI </summary>

- Download het bestand TFT_eSPI" bij de **Release**-pagina.
- Pak het uit.
- Sla het bestand op in de standaard geïnstalleerde libraries-map van Arduino.

</details>

<details>
<summary>Stap 2: Pinnen </summary>

De gebruikte pinnen voor het scherm zijn terug te vinden in de map: TFT_eSPI/User_Setup
Specifiek tussen **lijn 257 en 261**.
Deze pinconfiguratie komt ook overeen met het schema van het LCD-scherm.

![afbeelding](https://github.com/user-attachments/assets/c208db07-3abe-4d3f-a18a-cc76c3acb9de)


</details>

<details>
<summary>Stap 3: Frequency</summary>

Als het scherm niet onmiddellijk correct functioneert, kan het probleem te maken hebben met de ingestelde frequentie.

Gebruik het scherm gedurende ongeveer **10 minuten**.  
Soms verbetert de werking vanzelf na een korte opwarmperiode.

Indien er na 10 minuten nog steeds problemen zijn, kan je de **SPI-frequentie** aanpassen.

Open het bestand: TFT_eSPI/User_Setup
Ga naar **lijn 360**, waar de frequentie momenteel als volgt is ingesteld: #define SPI_FREQUENCY   1000000

Je kunt deze waarde wijzigen naar één van de onderstaande opties (afhankelijk van wat je hardware ondersteunt).  
Experimenteer met deze waarden tot het scherm stabiel en correct werkt.

![afbeelding](https://github.com/user-attachments/assets/d64a0fa9-d84f-46c6-92af-29eb902f7e33)

</details>
