#include <iostream>
#include <random>

using namespace std;

// this returns 0 with 60% prob and 1 with 40% prob
int get0Or1FromBiasedCoin() {

    // obtain a random number from hardware
    random_device rd;
    // seed the generator
    // A Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits
    mt19937 eng(rd());
    // define the range
    uniform_int_distribution<> distr(1, 100);

    if(distr(eng) > 60) {
        return 1;
    } else {
        return 0;
    }
}

int get0Or1Unbiased() {

    int val1 = get0Or1FromBiasedCoin();
    int val2 = get0Or1FromBiasedCoin();

    // Will reach here with 0.24 probability
    if(val1 == 0 && val2 == 1) {
        return 0;
    }

    // Will reach here with 0.24 probability
    if(val1 == 1 && val2 == 0) {
        return 1;
    }

    // will reach here with (1 - 0.24 - 0.24) probability
   return get0Or1Unbiased();
}

int main() {

    int count0 = 0;
    int count1 = 0;

    for(int i = 0; i < 1000; i++) {
        // returns both 0 and 1 with 50% probability 
        int val = get0Or1Unbiased();
        if(val == 0) {
            count0++;
        } else {
            count1++;
        }
    }

    cout << count0 << " " << count1 << endl;
    return 0;
}

