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
- Syntax und Terminology

## Aufgaben von Group 3 zu Flexray

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
6. Communication distribution and clustering // redundancy (when using 2-star configurations), Verstärker für Signale
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

**Questions: Chapter 7**

1. General: What does TDMA mean and why does TDMA-based communication require a synchronized time base? 
2. What would be an alternative to a synchronization process of different, in principle equal partners?
3. What is a Coldstarter?
4. How many of these exist in a FlexRay cluster?
5. What is the difference between a Leading Coldstarter and a Following Coldstarter?
6. What is the startup procedure (see in particular fig. 7-10 and sections 7.2.4.1 to 7.2.4.3)?

**Answers: Chapter 7**

1. TDMA: Time division multiple access; Every participant needs to synchronize their communication slot with one another, to avoid bus collisions
2. Just sequential sending of sender addresses (possibly hard-coded)
3. Coldstart Node: Initialize Communication (Cluster startup only by them)
4. There can only be as many coldstarters as static keyslots are available in the flexray (1023)
5. A coldstart node that actively starts the cluster is also called a leading coldstart node. A coldstart node that
integrates upon another coldstart node is also called a following coldstart node. 
6. Startup -> Coldstart listen -> coldstart collision resolution -> consistency check -> normal active

**Questions: Chapter 8**

1. How is the time hierarchy structured?
2. How does FlexRay understand global and local time?
3. Why is the vMacrotick parameter node-specific, even if the macrotick should be the same
length for all nodes?
4. What are the two reasons why clocks are not synchronized?
Information: In embedded systems, oscillators, such as a quartz oscillator, act as the frequency source for a clock. But even high-quality oscillators show deviations from their standard frequency. Reasons for these deviations are manufacturing tolerances, temperature fluctuations, aging and vibration.
5. What is the basic synchronization process of FlexRay? At what point is which type of
synchronization deviation corrected?
6. Information: The basic structure of a communication cycle is described in section 5 on page
100ff. In the static segment, which exists in every communication cycle, the same nodes always transmit at the same position (static slots), whereas in the dynamic part the transmission can vary from cycle to cycle. Only the static part is used as the base for the time measurement. Since there is a fixed schedule for the static part, the nodes know in advance when a message should arrive. This expected point in time is used as the basis for the measurement. Each node starts sending its message exactly at the ActionPoint when the ActionPoint is reached according to its own clock.
The receiving nodes compare the time of the incoming message with their own time (see Error! Reference source not found.).

**Answers: Chapter 8**

1. Cycles, Macroticks and Microticks
   1. Macrotick = n * Microtick
   2. Cycles = m * Macrotick
   3. Microticks == Processor frequency
2. The local time is the time of the node's clock and is represented by the variables vCycleCounter, vMacrotick,
and vMicrotick. vCycleCounter and vMacrotick shall be visible to the application. The update of
vCycleCounter at the beginning of a cycle shall be atomic with the update of vMacrotick. The local time is based on the local view of the global time. Every node uses the clock synchronization algorithm to attempt to adapt its local view of time to the global time.
3. vMactrotick is based on local time, therefore it needs to be node-specific
4. The bus is decentralized and there is no time manager. The ECUs have their own oszillator and their progress on time would differ between the nodes.
5. Sync process is two-staged: Sync-frames in predefined static slots to correct each nodes rate deviation and network idle time every 2nd cycle to correct each nodes offset.

## Automotive Ethernet

- kranke Latenzanforderungen (teils ≤ 10 µs!!)
- Bei Ethernet neuer Physical Layer und neue Bausteine in Anwendungsschicht

## AutoSAR


## Interview Fragen / Vorbereitung

Nur noch Reihenfolge überlegen mit Luft dazwischen für spontane Fragen!