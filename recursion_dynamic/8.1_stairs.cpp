#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countWays(int n, vector<int> memo) {
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else if (memo[n] > -1)
        return memo[n];
    else {
        memo[n] = countWays(n-1, memo) + countWays(n-2, memo) + countWays(n-3, memo);
        return memo[n];
    }
}

int main() {
    //we will a vector to store previous computer values -> like fibbonacci numbers
    std::vector<int> memo(100, -1);
    cout << countWays(10, memo) << endl;
    cout << countWays(20, memo) << endl;
    cout << countWays(25, memo) << endl;    
    cout << countWays(30, memo) << endl;
    return 0;
}

