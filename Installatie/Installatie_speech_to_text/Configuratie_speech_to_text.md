# Configuratie

Binnen het Speech-to-Text-programma zijn er verschillende aanpasbare instellingen.  
Spraakherkenning is sterk afhankelijk van de gebruiker, en binnen specifieke sectoren zoals de medische wereld komen vaak termen voor die fout geïnterpreteerd kunnen worden.  
Om dit te verbeteren, kunnen bepaalde parameters in de code worden aangepast.

Alle configuraties worden uitgevoerd in de `NodejsServer`-code.

## Locatie van de configuratie

Ga naar de map: XIAO-ESP32SSense-Speech2Text/NodejsServer/speechAPIServer


In deze map bevindt zich het bestand waarin alle spraakgerelateerde instellingen aangepast kunnen worden.

## Spraaktaal instellen

Op **regel 60** kan de taalinstelling van het programma aangepast worden.  
Standaard is deze ingesteld op `nl-BE` (Nederlands - België), maar dit kan gewijzigd worden naar een andere ondersteunde taal, zoals:

- `en-US` – Engels (Verenigde Staten)  
- `nl-NL` – Nederlands (Nederland)  
- `fr-FR` – Frans (Frankrijk)  
- `de-DE` – Duits (Duitsland)  
- `es-ES` – Spaans (Spanje)  
- `it-IT` – Italiaans (Italië)  
- `pt-BR` – Portugees (Brazilië)  
- `zh-CN` – Mandarijn (Chinees - Vereenvoudigd)  
- `pl-PL` – Pools (Polen)

Er zijn nog veel meer taalopties beschikbaar, afhankelijk van het gewenste accent of regio.

![Taalconfiguratie](https://github.com/user-attachments/assets/389ef6a0-7dac-4a32-b7cf-d936f34ecfe7)

## Kernwoorden (Speech Contexts)

In sectoren zoals de medische wereld is het belangrijk dat specifieke termen correct worden herkend.  
Om de herkenning van deze woorden te verbeteren, kunnen ze als kernwoorden worden toegevoegd aan de `speechContexts`.

Deze woorden worden geplaatst tussen `[` en `]`, en kunnen individueel een **boostwaarde** krijgen.  
Hiermee geef je aan welke woorden belangrijker zijn, zodat het systeem deze beter probeert te herkennen.  
Het is ook mogelijk om verschillende gradaties in de boost toe te passen.

![afbeelding](https://github.com/user-attachments/assets/001e5abd-771d-4c27-a120-60d0617c35e6)
