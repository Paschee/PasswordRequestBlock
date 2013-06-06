```bash
Höchstwahrscheinlich in C++

"Allgemeine Windowsdinge"

- c# : using.Microsoft.Win32 -> C ? // Hat sich erledigt
- Lock screen
- Windows herunterfahren bzw. re-booten (Ist in C# vorhanden) // wirds in C++ sicher auch geben
- Lock : Tab, Alt, Del, F4
- Hide : SetFormBorderStyle = None , ShowInTaskbar = false , weitere ...

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

- Jeff das cracken so schwer wie möglich machen ! Wie ? Keine ahnung. // :-)


```
