// Given a number n, print all primes smaller than or equal to n
// The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million

// Example:
//
// Input: n = 10
// Output: 2 3 5 7

// Following is the algorithm to find all the prime numbers less than or equal to a given integer n by Eratosthenes’ method:
//
// Create a list of consecutive integers from 2 to n: (2, 3, 4, …, n)
// Initially, let p = 2, the first prime number
// Starting from p, count up in increments of p and mark each of these numbers greater than p itself in the list
//     These numbers will be 2p, 3p, 4p, etc
//     Note that some of them may have already been marked
// Find the first number greater than p in the list that is not marked
//     If there was no such number, stop
//     Otherwise, let p now equal this number (which is the next prime), and repeat from step 3
//
// When the algorithm terminates, all the numbers in the list that are not marked are prime

#include <iostream>

using namespace std;

// Time complexity : O(sqrt(n)loglog(n))
void sieveOfEratosthenes(int num) {

    // Bool array to keep track of prime from 0 to num
    // Initialize all as true - so all are prime
    // All false entries will be non-prime
    bool prime[num+1];
    for(int i = 0; i < num + 1; i++) {
        prime[i] = true;
    }
 
    // we limit loop to p <= sqrt(num) since all numbers bigger than that
    // would have already been marked as non-prime by a small number within sqrt(num)
    for(int p = 2; p*p <= num; p++) {
        // If prime[p] is not changed, then it is a prime
        if(prime[p] == true) {
            // Update all multiples of p
            for(int i = p*2; i <= num; i += p) {
                prime[i] = false;
            }
        }
    }
 
    // Print all prime numbers
    for(int p = 2; p <= num; p++) {
        if(prime[p]) {
          cout << p << " ";
        }
    }
    cout << endl;
}

int main() {

    int num = 30;
    cout << "Prime numbers smaller than or equal to " << num << endl;
    sieveOfEratosthenes(num);

    return 0;
}
