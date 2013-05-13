```bash
-> Wird eventuell in C# gemacht

"Allgemeine Windowsdinge"

- c# : using.Microsoft.Win32 -> C ?
- Lock screen
- Windows herunterfahren bzw. re-booten (Ist in C# vorhanden)
- 
- Lock : Tab, Alt, Del, F4
- Hide : SetFormBorderStyle = None , ShowInTaskbar = false

"Passwort"

- mit MD5 hashen (Jeff C Tutorial Nr. 4)
- beim 1. nutzen Datei erstellen (Abfrage im Programm ob vorhanden, sonst neue erstellen)
- Ordner mit Datei verstecken (Hide File) -> Beugt dem versuch es zu loeschen vor
- SetFileAttributes und FLAG setzen bei FILE_ATTRIBUTE_HIDDEN

```
