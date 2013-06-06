```bash

"OS"

- using.Microsoft.Win32 -> C ? Wirds so auch in C++ geben
- Lock screen
- Windows herunterfahren bzw. re-booten (Ist in C# vorhanden), wirds in C++ sicher auch geben
- Lock : Tab, Alt, Del, F4
- Hide : SetFormBorderStyle = None , ShowInTaskbar = false , weitere ...
- Wenn möglich sollte es unter Win7 und ubuntu (12.04) funktionieren
- Für ubuntu muss ich noch schauen was ich genau brauche (zwecks PC boot)
- Herunterfahren etc muss unter Ubuntu auch verändert gemacht werden
- programm in Ubuntu - und Windows Handling teilen.
- Anomalien ausnutzen, sofern welche vorhanden sind ?

"Passwort"

- mit MD5 hashen (Jeff C Tutorial Nr. 4)
- Passwort eingabe "IMMER" mit sonderzeichen überdecken
- Passwortlaengenmin = 4 , Passwortlaengenmax = 128
- Passwortbeschränkungen !
- Passwortpflichtzeichen: Buchstaben(A-Z / Ä,Ö,Ü,ß) , Zahlen (1-9), Sonderzeichen (!, $, ... , ?)
- beim 1. nutzen Datei erstellen (Abfrage im Programm ob vorhanden, sonst neue erstellen)
- Ordner mit Datei verstecken (Hide File) -> Beugt dem versuch es zu loeschen vor
- SetFileAttributes und FLAG setzen bei FILE_ATTRIBUTE_HIDDEN

"Sicherheitsmechanismen"

- Jeff das cracken so schwer wie möglich machen ! Wie ? Keine ahnung. :-)

"Programmierumgebung"

- RAD Studio
- Sprache: C++

```
