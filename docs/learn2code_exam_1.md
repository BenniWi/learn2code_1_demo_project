# Prüfungsleistung

## Inhalt der Prüfung

* Pointer
* const correctness
* Strukturen
* Funktionen
* Bibliotheken
* CMake
* GTest
* 

```C
int main(void)
{
    int a = 5;
    run(a,b);
}
```

## Bewertungskriterien

- Die relevanten Alternativen für die Zielumgebung sind:
  - Suse Installation im Hörsaal der Vorlesung
  - Suse Installation in der zur Verfügung gestellten virtuellen Maschine (VirtualBox)
  - Virtuelle Umgebung
    - Der im [learn-git Repository](https://github.com/BenniWi/learn-git) bereitgestellte *Codespace*
    - Der im [learn-git Repository](https://github.com/BenniWi/learn-git) bereitgestellte *Gitpod Container*
    - relevante Compiler Alternative: 
      - GCC 9.4.0
      - Clang 10.0.0
- Das Projekt kann mittels CMake (Version >= 3.20) ohne Fehler und Warnungen konfiguriert und erzeugt werden.
- Die Projektsprache ist **ENGLISCH**
- Das Projekt kann mittels eines der zulässigen Compiler ohne Fehler und Warnungen übersetzt werden.
- Die Fortschritte des Projektes sind anhand der Git-Historie klar zu erkennen und die Beiträge aller Beteiligen sind voneinander abzugrenzen.
- Git Commits sind in **ENGLISCH** und die Beschreibung ist aussagekräftig
- Der Quellcode ist ausreichend in **ENGLISCH** dokumentiert
- Der Quellcode des gesamten Projektes ist einheitlich formatiert
- Der Quellcode wurde vollständig in **ENGLISCH** geschrieben
- Variablen und Funktionsnamen sind deskriptiv und verständlich
- Variablentypen werden entsprechend dem Verwendungszweck gewählt
- Die Projektstruktur (Ordnerstruktur) entspricht der Konvention aus der Vorlesung
- Der Quellcode ist im notwendigen Umfang unter Verwendung von *gtest* getestet. 
- Die *const correctness* wurde beachtet
- Empfehlungen
  - Die Aufteilung von Arbeitspaketen auf Entwickler:innen ist oftmals hilfreich und sinnvoll
  - Die Entwicklung einzelner Arbeitspakete in gesonderten *Git-Branches* vereinfacht oftmals Vieles
    - Ein regelmäßiger Merge/Rebase mit der Mainline verhindert den *großen Konflikt (Big Bang)* am Ende
  - Konsequente Anwendung der Formatierungsrichtlininen vereinfacht die Zusammenarbeit
- Offene Punkte: 
  - doxygen
  - CI
    - build test
    - test execution
    - formatting tests
    - ...

