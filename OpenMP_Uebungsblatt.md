# Exercise OpenMP

## Intro

1. Exercise 1: Parallelisation of Addition
2. Exercise 2: Game of Life
3. Exercise 3: Quicksort - Parallelisation with Sections

## Exercise 1 Parallelisation of Addition

**Tasks:**

Try to optimize the addition by using parallelisation and OpenMP. Play around with the elements of OpenMP (see reference) and write down your results.


|Release | 1000 | 10000 | 50000 | 100000 | 500000 |
|--------|------|-------|-------|--------|--------|
| Normal |      |       |       |        |        |
| OpenMP |      |       |       |        |        |

|Debug   | 1000 | 10000 | 50000 | 100000 | 500000 |
|--------|------|-------|-------|--------|--------|
| Normal |      |       |       |        |        |
| OpenMP |      |       |       |        |        |

## Exercise 2 Game of Life

The Game of Life uses elements called 'cellular automata', which have a state and react to their neighbors states.
A short introduction and the rules can be found here:
[Regeln zum Game of Life](https://natureofcode.com/book/chapter-7-cellular-automata/#chapter07_section6)

In this section a simple implementation to the game is given.

**Tasks:**

Call the GameOfLife for different amounts of generations in main. Try to find a good optimization using OpenMP for the implemented GameOfLife.

|Release | 100		    | 10000 | 25000 |
|--------|--------------|-------|-------|
| Normal |              |       |       |
| OpenMP |              |       |       |


|Debug   | 100		    | 10000 | 25000 |
|--------|--------------|-------|-------|
| Normal |              |       |       |
| OpenMP |              |       |       |



## Exercise 3 Quicksort - Parallelisation with Sections

**Tasks:**

Try to find a good optimization using OpenMP for the implemented Quicksort. 
Try to keep the overhead for thread creation in mind!
Try to measure the runtime for different array sizes.

|Release | 1000 | 10000 | 50000 | 100000 | 500000 |
|--------|------|-------|-------|--------|--------|
| Normal |      |       |       |        |        |
| OpenMP |      |       |       |        |        |


## Tipps & Tricks

1. Remember, that the omp header needs to be accessible
2. The OpenMP elements and a help can be found here: https://www.openmp.org/wp-content/uploads/Intro_To_OpenMP_Mattson.pdf
3. Info to exercise 2 can be found here: https://www.youtube.com/watch?v=tENSCEO-LEc&t=108s
4. Questions regarging C++ elements: https://en.cppreference.com/w/ or just ask us
5. Think about using the different build configurations debug and release
6. Ask yourself the "why" question behind your results and try to find answers to specific behavior