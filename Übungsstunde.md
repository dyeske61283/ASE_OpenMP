# OpenMP

## Agenda

1. Einleitung (15 min)
2. Übungsaufgaben (45 min)
3. Nachbereitung/Diskussion (30 min)

## Ideen

- Code mit STD/Chrono o.ä. vorbereiten
- I/O-, Daten- und irgendeinen dritten Task einmal implementieren lassen
- Zeiten messen
- OpenMP integrieren
- Zeiten messen
- Vergleichen und begründen/erklären

## Infos zu OpenMP

- Parallelisierung ist immer eine Optimierung und sollte nur mit konkreten Messungen und Zielen durchgeführt werden!

Warum überhaupt OpenMP nutzen? Es gibt doch die parallelen Algorithmen in der STL. (Seit C++17!)

- Granularität und explizite Parallelisierung
- Explizites tagging von Daten
- Parallele Ausführung nur bei passenden Datensätzen/Größen
- 

Consists of:
  - Compiler directives
  - Run time routines
  - Environment variables

## Related

https://www.reddit.com/r/cpp/comments/9wc84h/the_amazing_performance_of_c17_parallel/e9mrdlk/

https://electronics.stackexchange.com/questions/411049/is-it-true-that-on-a-modern-processor-parallelism-is-possible-on-a-single-core

https://cppcon.org/class-2019-parallelism-cpu-gpu/

https://www.researchgate.net/post/Concurrency_Vs_Parallelism

## Einleitung (15min)

**Parallelität, Multicore Systeme und deren Programmierung in C mit der OpenMP API**

C ist Standard und die HW-nähe ist durchaus praktisch und effizient. Sehr explizit. Parallelität verlangt dadurch allerdings einiges, weil keine Abstraktion.
Immer mehr (verschiedene) Aufgaben in einem Automobil => ~80 Steuergeräte in einem Auto und über 1 km CAN-Bus-Kabel!
OpenMP macht den Einstieg sehr einfach, weil man letztendlich einfach ein paar Präprozessor- und Compiler-Direktiven einfügt und schon Multi-Core Fähigkeit hat.
Im Auto bietet sich außerdem die moderne Multi-Core-Programmierung mit Threads und Scheduling an, weil man eben Multicores und Single-Speicher hat. Viele Aufgaben im Auto können (oder sogar müssen) auf die gleichen Daten zugreifen und unterschiedliche Befehle oder Aufgaben ableiten.
Wichtig dabei: Multicore Programmierung und Parallelisierung sind Optimierungen! Man handelt sich ein gutes Stück Komplexität und zusätzliche Aufgaben ein: Race Conditions müssen beachtet werden, Abriegeln von Daten und ein Scheduling falls Task-basiert gearbeitet wird müssen implementiert werden. Bugs durch Parallelität sind äußerst schwierig zu finden und können echte Probleme bereiten. Daher: Nur Parallelisieren nachdem ein Profiling ergeben hat, dass es eine sinnvolle und notwendige Performance-Steigerung bringen kann!

## Übung (45min)

- Code mit STD/Chrono vorbereiten
  - Code zur Zeitmessung vorbereiten und Main erstellen mit Aufrufen von Algorithmen/Funktionen von Teilnehmern
- CommandLine für Aufruf und Compile vorbereiten (compile options und linking beachten!)
- I/O- und Daten-/Algorithmen-Task, sowie einfache FOR-Schleife normal implementieren lassen
  - Funktionsrahmen vorgeben
  - ggf. Kommentare vorgeben für Implementierungsschritte (nicht jeder ist stark in C..)
  - Coole Algorithmen und Code-Spielchen bekommt man z.B. vom CodingTrain: https://www.youtube.com/user/shiffman
- Zeiten messen
  - ggf. verschiedene Optimierungsstufen ausprobieren lassen
- OpenMP integrieren
  - Konstrukte erklären und abdrucken
  - Einmal vorgeben, wie es funktioniert (bei FOR-Schleife)
  - Zweimal ausprobieren lassen
- Zeiten messen
- Vergleichen und begründen/erklären

## Nachbereitung/Diskussion

Zur Vorbereitung:

1. Einmal Beispiel ausprogrammieren und ausprobieren
2. Ergebnisse notieren (ggf. von zwei oder mehr verschiedenen Rechnern --> Configs notieren!)
3. Auch einfach mal die STL parallel Implementierung testen f. zeitliche Vergleiche
4. Verhalten von geschützten Daten und Laufzeit-Overhead anschauen, um Fragen in die Richtung beantworten zu können
5. ???