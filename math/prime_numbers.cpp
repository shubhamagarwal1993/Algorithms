#include <iostream>
#include <math.h>

using namespace std;

/*
 * Running time: O(sqrt n)
 * Space complexity: O(1)
 */
bool isPrimeNaive(int num) {

    if(num < 2) {
        return false;
    }

    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }

    return true;
}

void crossOff(bool* num_list_flags, int num_list_flags_size, int prime) {

    /* Cross off remaining multiples of prime. We can start with (prime*prime)
     * because if we have a k * prime, where k < prime, this value would have
     * already been crossed off in a prior iteration.
     */
    for(int i = prime * prime; i < num_list_flags_size; i += prime) {
        num_list_flags[i] = false;
    }

    return;
}

int getNextPrime(bool* num_list_flags, int num_list_flags_size, int prime) {
    int next_prime = prime + 1;

    while((next_prime < num_list_flags_size) && (num_list_flags[next_prime] == false)) {
        next_prime++;
    }
    return next_prime;
}

/*
 * Efficient way to generate list of primes
 * All non-prime numbers are divisble by a prime number
 *
 *
 */
bool sieveOfEratosthenes(int num) {
    int num_list_flags_size = num + 1;
    bool* num_list_flags = new bool[num_list_flags_size];
    for(int i = 0; i < num + 1; i++) {
        num_list_flags[i] = true;
    }

    int prime = 2;
    while(prime <= sqrt(num)) {
        // Cross off multiples of prime
        crossOff(num_list_flags, num_list_flags_size, prime);

        // find next prime number from list
        // this is the next number in the list which is true
        prime = getNextPrime(num_list_flags, num_list_flags_size, prime);
    }

    for(int i = 0; i < num_list_flags_size; i++) {
        if(num_list_flags[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return num_list_flags;
}

int main() {

    int num = 24;
    if(isPrimeNaive(num)) {
        cout << num << " is a prime number" << endl;
    } else {
        cout << num << " is not a prime number" << endl;
    }

    sieveOfEratosthenes(num);

    return 0;
}

