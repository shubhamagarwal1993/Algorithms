
## Common Summation Formulas

```
  Sum of int 1 to N
  (1 + 2 + ...... + N) = `n(n+1)/2`
```

```
  Sum of powers of 2
  (2^0 +2^1 + ..... + 2^n) = `(2^(n+1))-1`
  The sum of a sequence of powers of two is rougly equal to the next value in the sequence
```

```
  Permutations of n unique characters
  n * (n-1) * (n-2) * ....... * 1 = n!
```

```
  Forming a k length string (with all unique characters) from n total unique characters
  n * (n-1) * (n-2) * ....... * (n-k+1) = n!/(n-k)!
```

```
  How many k sized subsets are there out of n distinct elements? (order does not matter)
  n!/(k! * (n-k)!) = (n k)
```

## Geometric progression
  - common ratio = r
  - a, ar, a(r^2), a(r^3), a(r^4),....,a(r^(n-1)), a(r^n)
  - nth term = a(r^(n-1))
  - Sum of nth partial sum of GP, r not equal 1
    - Sn = a(1 - (r^n))/(1 - r)
  - Sum to infinity,
    - Sinf = a(r^(n-1))
    - If -1 < r < 1, then Sinf = a/(1-r)

## Runtimes
 - Big O     : upper bound on time, less than equal to relationship
   - Some Big O runtimes - O(log N), O(N logN), O(N), O(N^2), O(2^N)
 - Big theta : upper and lower bound on time
 - Big omega : lower bound on time, greater than equal to relationship

## Run times of Data Structures:
  - Lists
  - Vectors / Arraylists
  - Heaps
  - Trees
  - Tries
  - Graphs
  - Hash table
