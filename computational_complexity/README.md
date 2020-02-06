# Computational Complexity
Computational complexity theory focuses on classifying computational problems according to their inherent difficulty, and relating these classes to each other.
One of the roles of computational complexity theory is to determine the practical limits on what computers can and cannot do.

# Time complexities
|--------------|----------------------|
| O(1)         | constant time        |
| O(log(n))    | logarithmic time     |
| O((log(n))c) | polylogarithmic time |
| O(n)         | linear time          |
| O(n^2)       | quadratic time       |
| O(n^c)       | polynomial time      |
| O(c^n)       | exponential time     |
| O(n!)        | factorial time       |

# P vs NP problem
It asks whether every problem whose solution can be quickly verified can also be solved quickly.
![P vs NP](./resources/P_NP_1.svg)  
[A brief video explanation](https://www.youtube.com/watch?v=YX40hbAHx3s)

## Polynomial time
An algorithm for which a deterministic polynomial time algorithm exists belong to the complexity class P.
T(n) = O(n^k) for some positive constant k.  

Example problems:
- Quicksort O(n^2)

## Non-deterministic polynomial time
It is easy to verify in polynomial time, but may or may not be polynomial time to solve.
Since it may be solvable in polynomial time, all P problems are also NP problems.

Example problems:
- Travelling Salesman Problem (TSP): Time Complexity Θ(n!)

## Non-deterministic hard complete time
Problems that can't be even checked in the polynomial time are NP hard.
There is no polynomial time know solution for these problem.

Example problems:
 - Choosing the best move in chess.

## Non-deterministic complete time
NP problems that cannot be solved in polynomial time.
NP problems are similar to each other and vary by some polynomial factor. Thus, a soln to one NP complete problem could solve or serve as the basis for all other NP complete problems.

Example problems:
- Sudoku (easy to verify soln, not easy to find soln)




TSP:
Given a set of cities and distance between every pair of cities, find the shortest possible
route that visits every city exactly once and returns to the starting point.

Hamiltonian Cycle problem is to find if there exist a tour that visits every city exactly once.
There are many such tours, and they are easy to find. The TSP problem is to find a minimum weight Hamiltonian Cycle.
