# Automotive Software Engineering

## Orga-Zeugs

- Passwort: automotiveRogue

## Standort

- Unterweisung pipapi

## Hinweise

- EB Tresos
  - Projekte immer auf C ablegen
  - Gleicher Arbeitsplatz!
- Schedule:
  - Wir sind am Donnerstag früh dran!

## Development of Automotive Systems

- Validierung vs. Verifikation
- Spec zu AutoSAR auf Folie 24

## Discrete, Embedded Systems

- Rätseltechnik
- Speicher
- RTS
  - Soft RTS
  - Hard RTS
- Tasks
- Tasks Priorities and Scheduling
- Task State Machine bei AutoSar
- CAN Busarchitektur
- Message, Payload und Signale mit Protokoll-Frames

*Frage: Warum überlegt man sich eigentlich kein Provider/Consumer Prinzip für die Steuergeräte, also ein Gerät, dass ein Gesamt-Provider funktioniert?*

## Requirements Engineering

- Wat is ne Dampfmaschine?
- Stakeholder
- Unser Tool: Doors Next
- Functional vs Non-Functional
- Definition: System Boundary
- Kano-Modell
- How to Write Requirements
- Folie 76 wichtig für Masterarbeit!
- Requirement Template

## Safety & Dependability

- Funktionale Sicherheit
- Dependability
  - umbrella term for all safety aspects
- Fault, Error, Failure
- 3/1000 - 3/100000 Faults/LOC
- Fault Trees
- Safety of Intended Functionality (SOTIF)
- Safety ist immer Validierung

## Experten-Interview

- Infos liegen auf Moodle

## Introduction to Bus Systems

*Binary Unit System*

- CAN
- FlexRay
- Lim

## Aufgaben von Group 3

**Fragen:**

1. Which bus topologies are supported by FlexRay? 
2. Which topologies are not supported by FlexRay? 
3. FlexRay is designed for how many bus channels? 
4. In this context and regarding basic FlexRay systems, is it sensible to call it a FlexRay bus? 
5. How can two-channel bus systems be used? 
6. What is the task of an active star? 
7. Create an example of a two-channel system in bus and star topology whose logical topologies match each other. 
8. What is the maximum number of cascaded stars that FlexRay supports, and why?

**Antworten:**

1. (Dual) Line Topology, (Multi )Star Topology, Combination of both
2. Ring Topology
3. Two channels (A & B)
4. No, it is not since most configurations involve dual channels or star topologies
5. Divide traffic between channels and distribute/connect participants to different channels to divide listening tasks // Redundancy
6. Communication distribution and clustering // redundancy (when using 2-star configurations)
7. Bus:
            A     B     C     D     E
Channel A   1     0     1     1     1
Channel B   1     1     1     0     1

Star:
            A     B     C     D     E
Star A      1     0     1     1     1
Star B      1     1     1     0     1

(S.33/34)
8. Maximum of 2 cascaded active stars

**Fragen:**
1. What is a FlexRay node? 
2. What are the essential components of a FlexRay node? 
3. What is the meaning of RxD, TxD, TxEN?

**Antworten:**
1. Node Types
   1. Sync Node: Active participation in clock sync
   2. Coldstart Node: Initialize Communication
   3. Non-Sync Node: No special tasks => normal participants
2. Communication Controller, Host, Power Supply, Two bus drivers (1 per channel)
3. Signal:
   1. RxD: Receive Data - BD to CC: Data Incoming
   2. TxD: Transfer Data - CC to BD: Transfer Data to BD for transmission
   3. TxEN: Transmit Data Enable Not - CC to BD: Enables the bus driver of the according channel to transmit data on TxD

