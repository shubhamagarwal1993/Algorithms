# Discrete Maths

## Common Summation Formulas:
- Sum of int 1 to N
  ```
  (1 + 2 + ...... + N) = n(n+1)/2
  ```
- Sum of powers of 2
  ```
  (2^0 +2^1 + ..... + 2^n) = `(2^(n+1))-1`
  The sum of a sequence of powers of two is rougly equal to the next value in the sequence
  ```
- Permutations of n unique characters
  ```
  n * (n-1) * (n-2) * ....... * 1 = n!
  ```
- Forming a k length string (with all unique characters) from n total unique characters
  ```
  n * (n-1) * (n-2) * ....... * (n-k+1) = n!/(n-k)!
  ```
- How many k sized subsets are there out of n distinct elements? (order does not matter)
  ```
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

## ASCII Table
| Decimal | Char  |
| ------- | ----- |
| 0       | NULL  |
| 32      | space |
| 48      | 0     |
| 57      | 9     |
| 65      | A     |
| 90      | Z     |
| 97      | a     |
| 122     | z     |
| 127     | DEL   |

- print ASCII value of chars in c++, where ascii ranges from 32 (space) to 126 (~)
  ```
  int main() {
      char c = 'A';
      cout << "The ASCII value of " << c << " is " << int(c) << endl;
  }
  ```
- print chars of ASCII value in c++, where ascii ranges from 32 to 126
  ```
  int main() {
      int ascii_val 97;
      cout << "The char value of " << ascii_val << " is " << char(ascii_val) << endl;
  }
  ```

## Primitive types and size
| Type   | Size    |         | Total values         | Range                           |
| ------ | ------- | ------- | -------------------- | ------------------------------- |
| char   | 1 byte  |  8 bits | 2^8  = 256           |           -128 to 127           |
| uchar  | 1 byte  |  8 bits | 2^8  = 256           |              0 to 256           |
| short  | 2 bytes | 16 bits | 2^16 = 65,536        |        -32,768 to 32,767        |
| ushort | 2 bytes | 16 bits | 2^16 = 65,536        |              0 to 65,535        |
| int    | 4 bytes | 32 bits | 2^32 = 4,294,967,296 | -2,147,483,648 to 2,147,483,647 |
| uint   | 4 bytes | 32 bits | 2^32 = 4,294,967,296 |              0 to 4,294,967,295 |
| long   | 8 bytes | 64 bits | 2^64 = .......       | -...           to ...           |
| ulong  | 8 bytes | 64 bits | 2^64 = .......       |              0 to ......        |

## Constants
| Constant | Value       |
| -------- | ----------- |
| INT_MAX  |  2147483647 |
| INT_MIN  | -2147483648 |

## Runtimes
 - Big O     : upper bound on time, less than equal to relationship
 - Big theta : upper and lower bound on time
 - Big omega : lower bound on time, greater than equal to relationship

# Probability
## Bayes theorem
P(A given B) = P(B given A) P(A) / P(B)

probability of landing in A or B: P(A or B) = P(A) + P(B) - P(A and B)

## Independence and Mutual Exclusivity
Two events cannot be both independent and mutually exclusive
- Independence
  - A and B are independent (that is, one happening tells you nothing about the other happening)
  - P(A and B) = P(A) P(B)
- Mutual Exclusivity 
  - A and B are mutually exclusive (that is, if one happens, then the other cannot happen)
  - P(A or B) = P(A) + P(B). This is because P(A and B) = 0

