### 3 ways to represent graphs:

#### Adjacency List: (For a good example, check out Bidirectional BFS example)
 - Pros:
   - Less space (O|V| + O|E|). Worst case O(V^2) space
   - Adding a vertex is easy
 - Cons:
   - To find if edge between u and v takes O(V) time

#### Adjacency Matrix:
 - Pros:
   - Removing edge takes O(1) time
   - To find if edge between u and v takes O(1) time
 - Cons:
   - Consumes more space O(V^2)
   - Even if the graph is sparse (contains less number of edges), it consumes the same space
   - Adding a vertex is O(V^2) time

#### Objects and Pointers:
 - Pros:
   - 
 - Cons:
   - 

### Polynomial vs exponential
 - Polynomial times:
   - look like C(n^k) or O(n^k) where n is the size of the input
   - can be constant, linear, quadratic, cubic
 - Exponential looks like C(k^n) or O(k^n) where n is the size of the input

### P vs NP vs NP-Complete vs NP-Hard Complexity classes
 - Decision problem: A problem with a yes or no answer
 - Refer: https://stackoverflow.com/questions/1857244/what-are-the-differences-between-np-np-complete-and-np-hard

#### P
 - A complexity class that represents the set of all decision problems that can be solved in polynomial time
 - Problems can be solved by deterministic turing machine
 - subset of NP problems
 - E.g. Given a connected graph G, can its vertices be coloured using two colours so that no edge is monochromatic?
   - Algorithm: start with an arbitrary vertex, color it red and all of its neighbours blue and continue. Stop when you run out of vertices or you are forced to make an edge have both of its endpoints be the same color.

#### NP
 - A complexity class that represents the set of all decision problems that can be verified in polynomial time
 - Problems that cannot be solved in polynomial time
 - problems that can be solved by non-deterministic turing machine
 - E.g. Integer factorisation is in NP. This is the problem that given integers n and m, is there an integer f with 1 < f < m, such that f divides n (f is a small factor of n)?
   - This is a decision problem because the answers are yes or no. If someone hands us an instance of the problem (so they hand us integers n and m) and an integer f with 1 < f < m, and claim that f is a factor of n (the certificate), we can check the answer in polynomial time by performing the division n / f.

#### NP-Complete
 - A complexity class which represents the set of all problems X in NP for which it is possible to reduce any other NP problem Y to X in polynomial time
 - Intuitively this means that we can solve Y quickly if we know how to solve X quickly. Precisely, Y is reducible to X, if there is a polynomial time algorithm f to transform instances y of Y to instances x = f(y) of X in polynomial time, with the property that the answer to y is yes, if and only if the answer to f(y) is yes.
 - E.g. 3-SAT. It can be shown that every NP problem can be reduced to 3-SAT. Also known as Cook's theorem
 - E.g. Find chromatic number of a given graph 

#### NP-Hard
 - These are the problems that are at least as hard as the NP-complete problems. Note that NP-hard problems do not have to be in NP, and they do not have to be decision problems
 - A problem X is NP-hard, if there is an NP-complete problem Y, such that Y is reducible to X in polynomial time
 - Since any NP-complete problem can be reduced to any other NP-complete problem in polynomial time, all NP-complete problems can be reduced to any NP-hard problem in polynomial time. Then, if there is a solution to one NP-hard problem in polynomial time, there is a solution to all NP problems in polynomial time.
 - E.g. The halting problem, this is the problem that given a program P, and input I, will it halt?
 - Any NP-complete problem is NP-hard

-----------------------------------------------------------------
| Problem Type  | Verifiable in P time  | Solvable in P time    |
|---------------|-----------------------|-----------------------|
| P             |        Yes            |        Yes            |
| NP            |        Yes            |     Yes or No         |
| NP-Complete   |        Yes            |      Unknown          |
| NP-Hard       |     Yes or No         |      Unknown          |
-----------------------------------------------------------------

#### Graph coloring Applications:
 - Making schedule or time table: How do we schedule the exam so that no two exams with a common student are scheduled at same time? How many minimum time slots are needed to schedule all exams? 
   - This problem can be represented as a graph where every vertex is a subject and an edge between two vertices mean there is a common student. So this is a graph coloring problem where minimum number of time slots is equal to the chromatic number of the graph
 - Mobile Radio Frequency Assignment: How to assign different frequencies to all towers at the same locatoin? What is the minimum number of frequencies needed ?
   - This problem is an instance of graph coloring problem where every tower represents a vertex and an edge between two towers represents that they are in range of each other
 - Sudoku: A variation of graph coloring problem where every cell represents a vertex. There is an edge between two vertices if they are in same row or same column or same block
 - Bipartitle graph: A variation of graph coloring problem. If a given graph is 2-colorable, then it is Bipartite, otherwise not
 - Map Coloring: Geographical maps of countries or states where no two adjacent cities cannot be assigned same color. Four colors are sufficient to color any map 
