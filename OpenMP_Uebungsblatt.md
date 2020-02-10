# Übung OpenMP

## Intro

1. Übung 1: Parallelisierung von Addition
2. Übung 2: Game of Life
3. Übung 3: Quicksort - Parallelisierung mit Sections

## Übung 1 Parallelisierung von Addition

**Aufgaben:**

Versuche eine optimale Parallelisierung der Addition zu erreichen. Spiele mit den Elementen von OpenMP und nimm die Ergebnisse auf.


|Release | Average Time |
|--------|--------------|
| Normal |              |
| OpenMP |              |

|Debug   | Average Time |
|--------|--------------|
| Normal |              |
| OpenMP |              |

## Übung 2 Game of Life

Das Game of Life beschäftigt sich mit zellulären Automaten und ihrem Verhalten zu Nachbarn.
Eine kurze Einleitung und die Spielregeln sind hier zu finden:
[Regeln zum Game of Life](https://natureofcode.com/book/chapter-7-cellular-automata/#chapter07_section6)

In dieser Lektion ist eine Implementierung zum Spiel gegeben.

**Aufgaben:**

Starte das GameOfLife für eine verschiedende Anzahl an Generationen, indem du die korrekten Funktionen aus dem bestehenden Code nutzt und in Main aufrufst. Versuche anschließend eine optimale Parallelisierung durchzuführen mit Elementen aus OpenMP. Notiere dir deine Herangehensweise und schreibe kurz heraus welche Stellen sich am ehesten für eine Parallelisierung eignen.

|Release | 100		    | 10000 | 25000 |
|--------|--------------|-------|-------|
| Normal |              |       |       |
| OpenMP |              |       |       |


|Debug   | 100		    | 10000 | 25000 |
|--------|--------------|-------|-------|
| Normal |              |       |       |
| OpenMP |              |       |       |



## Übung 3 Quicksort - Parallelisierung mit Sections

**Aufgaben:**

Versuche eine optimale Parallelisierung des bereits vorimplementierten Quicksorts. 
Beachte dabei vorallem den möglichen Overhead durch die Erstellung von Threads!
Probiere dabei die Laufzeit bei verschiedenen Arraygrößen aus.

|Release | 1000 | 10000 | 50000 | 100000 | 500000 |
|--------|------|-------|-------|--------|--------|
| Normal |      |       |       |        |        |
| OpenMP |      |       |       |        |        |


## Tipps & Tricks

1. Daran denken, dass der omp.h Header auch zugreifbar ist
2. Die OpenMP Elemente und eine Hilfe sind hier zu finden: https://www.openmp.org/wp-content/uploads/Intro_To_OpenMP_Mattson.pdf
3. Infos zu Übung 2 sind auch hier zu finden: https://www.youtube.com/watch?v=tENSCEO-LEc&t=108s
4. Bei Fragen zu C++ Elementen und Membern: https://en.cppreference.com/w/ oder einfach melden
5. Denke an Unterschiede zwischen Debug- und Release-Konfigurationen
6. Frage dich auch das "Warum" hinter Ergebnissen und bestimmtem Verhalten