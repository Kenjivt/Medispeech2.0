## Installatie

Voordat de codes of componenten gebruikt kunnen worden, moeten eerst het spraak-naar-tekst-systeem en het LCD-scherm correct worden geïnstalleerd. Deze installaties moeten zorgvuldig worden uitgevoerd, anders zal het systeem niet naar behoren functioneren.

### Installatie Speech to Text

De werking en installatie is grotendeels overgenomen van [wiki.seeedstudio](https://wiki.seeedstudio.com/xiao_esp32s3_speech2chatgpt/).  
De componenten die nodig zijn voor deze installatie:
- Een **XIAO ESP32S3 SENSE** (belangrijk: niet de gewone ESP32S3)
- Een **16GB SD-kaart**

Eerst wordt de antenne op de XIAO geplaatst, vervolgens wordt het SD-kaartslot geïnstalleerd. Zorg ervoor dat de SD-kaart geformatteerd is voordat deze wordt geplaatst.

<p>
  <img src="https://github.com/user-attachments/assets/52d4c004-91b1-483f-8381-a6441d0bd9df" width="362"/>
  <img src="https://github.com/user-attachments/assets/9e814670-f59e-4d3f-bf9e-f02cbaa15d11" width="300"/>
</p>

---

### Stappenplan

<details>
<summary>Stap 1: API instellen</summary>

Registreer [hier](https://console.cloud.google.com/) voor een Google Cloud account.

![afbeelding](https://github.com/user-attachments/assets/9cc48f45-d9bf-4a61-848c-7766a0398bbb)

</details>

<details>
<summary>Stap 2: Project selecteren</summary>

Klik op **Project selector page**.  
Kies een bestaand project of maak een nieuw project aan. Als je een nieuw project maakt, wordt gevraagd om een betaalaccount te koppelen. Bij een bestaand project moet **billing** geactiveerd zijn.

![afbeelding](https://github.com/user-attachments/assets/c0d33e7d-f815-4b43-938c-c76bbafc4f48)

</details>

<details>
<summary>Stap 3: Speech-to-Text service starten</summary>

- Typ in de zoekbalk bovenaan "speech".
- Selecteer **Cloud Speech-to-Text API** uit de resultatenlijst.

![afbeelding](https://github.com/user-attachments/assets/217f145e-b0a2-4903-a114-e01e286704d1)

</details>

<details>
<summary>Stap 4: Service account aanmaken</summary>

- Klik op **CREATE CREDENTIALS** → **Service account**.
- Geef een unieke naam op bij **Service account name**.
- (Optioneel) Voeg een beschrijving toe.
- Klik op **CREATE AND CONTINUE**.

![afbeelding](https://github.com/user-attachments/assets/89015b42-ec41-4835-876b-b34fbb73d742)
![afbeelding](https://github.com/user-attachments/assets/cced8d0d-5c62-43cb-bc7f-1914c520e284)

- Bij **Select a role**, kies **Owner**.
- Klik op **CONTINUE**.

![afbeelding](https://github.com/user-attachments/assets/329ed1f2-0428-40e9-a667-3b54280b170e)

- Klik op **DONE** als je geen extra toegang wilt toewijzen.

![afbeelding](https://github.com/user-attachments/assets/aac974e8-680b-4ff9-818d-79032419c30c)

- De service account verschijnt nu in de lijst.

![afbeelding](https://github.com/user-attachments/assets/deffc777-5ab7-4323-a8cd-cd89aa5a0cba)

</details>

<details>
<summary>Stap 5: JSON-sleutel aanmaken</summary>

- Klik op het aangemaakte service account.
- Ga naar het tabblad **KEYS**.
- Klik op **ADD KEY** → **Create new key** → kies **JSON**.

![afbeelding](https://github.com/user-attachments/assets/a70d810d-0a5e-4066-a8b8-ed10e5b52188)

De sleutel wordt automatisch gedownload. Bewaar deze veilig. Deze JSON-sleutel is essentieel om toegang te krijgen tot de Speech-to-Text API.

![afbeelding](https://github.com/user-attachments/assets/f83dce6d-537e-43b0-b503-66c02dae31f9)

</details>

<details>
<summary>Stap 6: Bestand downloaden en voorbereiden</summary>

- Download het bestand "XIAO-ESP32SSense-Speech2Text" bij de **Release**-pagina.
- Pak het uit.
- Sla het bestand op een locatie op die gemakkelijk terug te vinden is.
- Plaats de JSON-sleutel (uit stap 5) in de map **NodejsServer**.

![afbeelding](https://github.com/user-attachments/assets/f3fa42d4-ebaf-4050-88d4-15ed2746caa0)

</details>

---

## Belangrijk

- **Stappen 1 t/m 6** zijn **eenmalig** nodig.
- **Stap 7** moet **iedere keer** opnieuw worden uitgevoerd voordat het device gebruikt wordt.

---

<details>
<summary>Stap 7: Windows Powershell gebruiken</summary>

1. Open **Windows Powershell**.
2. Kopieer het pad van de map **NodejsServer**.
3. Typ het volgende en plak het pad (voorbeeld):
cd "C:\Users\Beheerder\Desktop\XIAO-ESP32S3Sense-Speech2ChatGPT\NodejsServer"

![afbeelding](https://github.com/user-attachments/assets/88803eb6-5955-4a35-84c2-2e32b3dff204)

5. Kopieer het pad van het JSON-bestand.

6. Stel het pad in met het volgende commando (vervang het pad door dat van jouw JSON-bestand):
$env:GOOGLE_APPLICATION_CREDENTIALS="C:\Users\Beheerder\Desktop\XIAO-ESP32S3Sense-Speech2ChatGPT\NodejsServer\solar-virtue-451018-q7-4417a0e3ca08.json"

7. Start de server door dit commando uit te voeren:
node ./speechAPIServer.js

Er verschijnt nu het bericht:

    Listing at 8888
    

![afbeelding](https://github.com/user-attachments/assets/2d23a058-d987-4391-ba08-8793ec46c76f)

De installatie is nu voltooid en het device kan worden gebruikt. 
</details>
