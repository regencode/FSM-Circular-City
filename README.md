# Circular Train Stations using Finite State Automata

Station name is based on the first 2 terms of the state (example: 001 is in Station 00, 110 is in Station 11)

You start at Station 00, at state 000

Move in clockwise/anticlockwise by inputting 1.

Change tracks from clockwise -> anticlockwise and vice versa by inputting 0.

## DFA Implementation:
![fsmterminal](https://user-images.githubusercontent.com/114067350/211838875-d6378514-00c6-480c-a8fe-0936742fefe8.PNG)


## DFA Definition:
DFA is defined as a 5 tuple -> DFA = (Q, sigma, delta0, q0, F)

The definition of this DFA:

Q = {000, 001, 010, 011, 100, 101, 110, 111}

sigma = {Change track, Move to next station} encoded to {0, 1}

delta0 = 

![FSMdelta](https://user-images.githubusercontent.com/114067350/210193557-b417c89b-3812-46a8-a7b8-79e98cb2f93a.png)

q0 = 000

F = {101}

## State transitions as K-maps:

![kmap-1](https://user-images.githubusercontent.com/114067350/210193682-0ea09a2b-53ca-4bde-93ba-462d5a9a064b.png)

![kmap-2](https://user-images.githubusercontent.com/114067350/210193685-e557610f-74aa-45ae-a2df-751481ec491e.png)

![kmap-3](https://user-images.githubusercontent.com/114067350/210193688-89731284-998e-4002-94ea-1a2e67c606a2.png)


# Code implementation

In the main.c file, the implementation of the DFA is through the K-maps that are obtained through the changes of s0, s1, and s2

# Visualization in the terminal

Y - Your position

00, 01, 10, 11 - Station name

10 is highlighted in green as it is the destination terminal

![fsmterminal](https://user-images.githubusercontent.com/114067350/210596616-023c6d4c-cfe7-40e9-90a3-67edbbe46dd3.PNG)


## How to run:
With Makefile installed on your system, type "make" or "make run" to the terminal.

