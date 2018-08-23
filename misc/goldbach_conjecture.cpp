// Every even integer greater than 2 can be expressed as the sum of two primes
// There may be several combinations possible

#include <iostream>
#include <vector>

using namespace std;

void sieveOfEratosthenes(int num, bool prime[]) {

    // Bool array to keep track of prime from 0 to num
    // Initialize all as true - so all are prime
    // All false entries will be non-prime
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
}

int main() {

    int num = 30;

    bool prime[num+1];
    sieveOfEratosthenes(num, prime);

    // Put all prime numbers in a vector
    vector<int> prime_vec;
    for(int p = 2; p <= num; p++) {
        if(prime[p]) {
            prime_vec.push_back(p);
        }
    }

    int l_index = 0;
    int r_index = prime_vec.size() - 1;
    while(l_index < r_index) {
        if(prime_vec[l_index] + prime_vec[r_index] == num) {
            cout << prime_vec[l_index] << " " << prime_vec[r_index] << endl;
        }
        if(prime_vec[l_index] + prime_vec[r_index] < num) {
            l_index++;
        } else {
            r_index--;
        }
    }

    return 0;
}
