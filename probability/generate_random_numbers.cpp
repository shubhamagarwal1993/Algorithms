#include <iostream>
#include <random>

using namespace std;

int randomNumber1To5() {

    // obtain a random number from hardware
    random_device rd;
    // seed the generator
    // A Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits
    mt19937 eng(rd());
    // define the range
    uniform_int_distribution<> distr(1, 5);

    return distr(eng);
}

// Only using function randomNumber1To5()
int randomNumber1To7(int random_int_1_5) {

    // Generate integers from 1 to a-multiple-of-7 (like 7, 14, 21, …) with equal probability
    // Use modulo division by 7 followed by adding 1 to get the numbers from 1 to 7 with equal probability

    // The range of values returned by below equation is 1 to 25, each number occuring only once
    int random_int_1_25 = (5 * randomNumber1To5()) + randomNumber1To5() - 5;
    // 01 - (%7) + 1 = 2
    // 02 - (%7) + 1 = 3
    // 03 - (%7) + 1 = 4
    // 04 - (%7) + 1 = 5
    // 05 - (%7) + 1 = 6
    // 06 - (%7) + 1 = 7
    // 07 - (%7) + 1 = 1
    // 08 - (%7) + 1 = 2
    // 09 - (%7) + 1 = 3
    // 10 - (%7) + 1 = 4
    // 11 - (%7) + 1 = 5
    // 12 - (%7) + 1 = 6
    // 13 - (%7) + 1 = 7
    // 14 - (%7) + 1 = 1
    // 15 - (%7) + 1 = 2
    // 16 - (%7) + 1 = 3
    // 17 - (%7) + 1 = 4
    // 18 - (%7) + 1 = 5
    // 19 - (%7) + 1 = 6
    // 20 - (%7) + 1 = 7
    // 21 - (%7) + 1 = 1
    // 22 to 25 - ignore

    if(random_int_1_25 < 22) {
        return (random_int_1_25 % 7) + 1;
    }
    return randomNumber1To7(random_int_1_5);
}

// Utility function to find ceiling of r in arr[l..h]
int findCeil(int arr[], int r, int l, int h) {
    int mid;
    while(l < h) {
        mid = l + ((h - l) >> 1);  // Same as mid = (l+h)/2
        (r > arr[mid]) ? (l = mid + 1) : (h = mid);
    }
    return (arr[l] >= r) ? l : -1;
}

int randomNumberArbitraryProbability() {

    // array numbers with different probabilities
    int arr[] = {1, 2, 3, 4};
    int freq[] = {10, 5, 20, 100};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // Use a different seed value for every run
    srand(time(NULL));

    // Create and fill prefix array
    int prefix[arr_size];
    prefix[0] = freq[0];
    for(int i = 1; i < arr_size; i++) {
        prefix[i] = prefix[i - 1] + freq[i];
    }
 
    // prefix[n-1] is sum of all frequencies. Generate a random number
    // with value from 1 to this sum
    int r = (rand() % prefix[arr_size - 1]) + 1;
 
    // Find index of ceiling of r in prefix arrat
    int indexc = findCeil(prefix, r, 0, arr_size - 1);
    return arr[indexc];
}

int main() {
    int random_int_1_5 = randomNumber1To5();
    cout << randomNumber1To7(random_int_1_5) << endl;

    cout << randomNumberArbitraryProbability() << endl;

    return 0;
}
