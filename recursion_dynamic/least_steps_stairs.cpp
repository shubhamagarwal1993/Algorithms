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

void leastSteps(vector<int> steps, int curr_step, vector<int> &res, int &steps_shortest) {
    // base case
    if(curr_step >= steps.size() - 1) {

        // if on the last step, add it to the path
        if((curr_step == steps.size() - 1) && (steps[curr_step] == 1)) {
        //    res.push_back(curr_step);
        }

        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        return;
    }

    if((curr_step < steps.size()) && (steps[curr_step] == 1)) {
        res.push_back(curr_step);
        steps_shortest += 1;

        leastSteps(steps, curr_step + 3, res, steps_shortest);
        leastSteps(steps, curr_step + 1, res, steps_shortest);

        res.pop_back();
    }
}

int main() {
    //we will a vector to store previous computer values -> like fibbonacci numbers
    std::vector<int> memo(100, -1);
    cout << countWays(10, memo) << endl;
    cout << countWays(20, memo) << endl;
    // cout << countWays(25, memo) << endl;    
    // cout << countWays(30, memo) << endl;

    vector<int> steps {1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1};
    //                 0  1  2  3  4  5  6  7  8  9 10 11 12 13
    int steps_shortest = INT_MAX;
    int curr_step = 0;
    vector<int> res;
    leastSteps(steps, curr_step, res, steps_shortest);

    return 0;
}

