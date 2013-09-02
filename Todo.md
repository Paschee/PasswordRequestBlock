```bash

"Allgemeines"

- die UR-Version wird wohl vorerst nur Konsolenbasiert sein. | IST GUI GEWORDEN -> DONE
- Oberfläche könnte entsprechend nachgereicht werden. | S. PUNKT 1
- Wenn Oberfläche, dann schlicht (2 x Edit, Evtl. zeitanzeige und Button zum Entern oder Runterfahren) | DONE

"OS"

- using.Microsoft.Win32 -> C ? Wirds so auch in C++ geben | GIBT ES, WURDE BEREITS GENUTZT
- Lock screen | BORDERSTYLE = NONE, WSMAXIMIZED | DONE
- Windows herunterfahren bzw. re-booten (Ist in C# vorhanden), wirds in C++ sicher auch geben | DONE
- Lock : Tab, Alt, Del, F4 | "X"
- Hide : SetFormBorderStyle = None , ShowInTaskbar = false , weitere ... | ZUM TEIL DONE
- Wenn möglich sollte es unter Win7 und ubuntu (12.04) funktionieren | ENTFÄLLT
- Für ubuntu muss ich noch schauen was ich genau brauche (zwecks PC boot) | ENTFÄLLT
- Herunterfahren etc muss unter Ubuntu auch verändert gemacht werden | ENTFÄLLT
- programm in Ubuntu - und Windows Handling teilen. | ENTFÄLLT
- Anomalien ausnutzen, sofern welche vorhanden sind ? | ENTFÄLLT

"Passwort"

- mit MD5 hashen (Jeff C Tutorial Nr. 4)
- Passwort eingabe "IMMER" mit sonderzeichen überdecken | DONE
- Passwortlaengenmin = 4 , Passwortlaengenmax = 128 | DONE
- Passwortpflichtzeichen: Buchstaben(A-Z / Ä,Ö,Ü,ß) , Zahlen (1-9), Sonderzeichen (!, $, ... , ?) | entfällt da unnötig.
- beim 1. nutzen Datei erstellen (Abfrage im Programm ob vorhanden, sonst neue erstellen) | DONE
- Ordner mit Datei verstecken (Hide File) -> Beugt dem versuch es zu loeschen vor | S. NÄCHSTEN PUNKT
- SetFileAttributes und FLAG setzen bei FILE_ATTRIBUTE_HIDDEN | IN ARBEIT

"Sicherheitsmechanismen"

- Jeff das cracken so schwer wie möglich machen ! Wie ? Keine ahnung. :-) | RECHERCHE IN ARBEIT

"Programmierumgebung"

- RAD Studio
- Sprache: C++

```
