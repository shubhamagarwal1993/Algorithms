// Infinite number of quarters, dime, nickles, and pennies.
// Number of ways of representing n cents

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int countWays(int total) {

    // memoize
    int table[total+1];

    memset(table, 0, sizeof(table));

    // base case - if total is 0
    table[0] = 1;

    for(int i = 1; i <= total; i++) {
        table[i] += table[i-1];
    }

    for(int i = 5; i <= total; i++) {
        table[i] += table[i-5];
    }

    for(int i = 10; i <= total; i++) {
        table[i] += table[i-10];
    }

    for(int i = 25; i <= total; i++) {
        table[i] += table[i-25];
    }

    return table[total];
}

int main() {

    cout << countWays(10) << endl;
    return 0;
}

