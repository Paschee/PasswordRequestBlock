Password Request Block
----------------------

```bash
Entstehen wird eine Passwortabfrage, die nach Abgeschlossenem Bootvorgang beginnt.
Screen soll weitestgehend abgesperrt werden und es werden zusätzliche maßnahmen getroffen,
um das umgehen der abfrage so weit wie möglich zu unterbinden. Es wird jederzeit möglich sein,
ein neues Passwort zu speichern oder zu ändern. Das Passwort wird in einer für den Nutzer
nicht sichtbaren Datei abgelegt, um dem löschen oder ändern des Keys vorzubeugen.

Wird umgesetzt in : C++

------------------------------------------------------------------------------------------------------------------------

Das Projekt wird für den folgenden Zeitraum angesetzt :
Start    : 24.Juni.2013
Deadline : 15.Juli.2013


P.-
```

Fortschritt
---

```bash
Tag 1: • GUI inkl. Tab Struktur
       • Shutdown, Reboot
       • Vorbereitungen für kommende Funktionen
       • WindowState Maximized (1.Umgehungsschutz)

Tag 2: • Pseudo Konsole gefixed, Scrollbar angefügt
       • Passwort Speichern
       • Passwortbeschränkungen
       • Verschlüsselte Eingabe

Tag 3: • Speicherung geändert
       • File Attributes
       • Log in gestartet
       • Passwort konnte nicht überschrieben werden *fixed
       
Tag 4: • -

Tag 5: • CreatePassword und Log in sind jetzt komplett funktionsfähig
       • Bugs,Probleme und anderer Schmu *fixed
       
Tag 6: • Strukturen geändert

Tag 7: • Musste was am Passwort ändern, sonst hätte man einfach ein neues erstellen und eintreten können.
       • Altes Passwort wird beim erstellen eines neuem jetzt abgefragt (Wie konnte ich daran nicht denken ...)
       • Und immer mehr probleme ...
       
       Leider ist in den letzten Wochen nichts mehr passiert, was mit den Prüfungen aber 
       auch mit meiner Faulheit zu tun hat, dass möchte ich hier nicht unterschlagen. 
       Der aufhänger waren die an Tag 7 entstandenen Probleme, die mich gezwungen
       haben das programm neu zu strukturieren, wozu ich nun leider nicht gekommen bin - Bis jetzt.
       Ich habe endlich wieder einen kleinen Zeitraum in dem ich stressfrei coden kann und den werde ich gut nutzen
       um das programm wie versprochen als "Crack-Experiment" freizugeben.

```

```bash
Update 1.1: • Wideraufnahme des Projekts 
            • Das Ursprüngliche problem wurde in 5 Minuten gelöst (Ja, kein witz) und 
              jetzt gehts an die "blockierenden" Aspekte des Programms

Update 1.2: • Hab jetzt angefangen mich auf SetWindowsHookEx und CallNextHookEx zu stürzen
            • das erkennen der tasten funktioniert (war jetzt aber auch nichts großes)
            • das wäre jetzt auch die letzte große hürde, danach wär das programm für seine
              erste einsatzphase bereit
            • Tricky könnte werden, dass das meiste davon für 32-bit gedacht ist
            • Um das Programm mit dem PC bootvorgang zu starten, muss das Programm zuhause nur
              per "regedit" in HKEY_CURRENT_USER eingetragen werden - Ich schreibe dazu auch eine
              kleine Anleitung ins Programm

```
