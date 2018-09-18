// https://stackoverflow.com/questions/1106929/how-to-find-all-combinations-of-coins-when-given-some-dollar-value#comment15033239_1107115
// Infinite number of quarters, dime, nickles, and pennies.
// Number of ways of representing n cents

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int countWays_iterative(int total) {

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

    cout << endl << "=============================" << endl;
    for(int i = 0; i < total+1; i++) {
        cout << table[i] << " ";
    }
    cout << endl << "=============================" << endl;
    return table[total];
}

int countWays_recursive(int denominations[], int den_size, int total, vector<int> vec) {

    if(total == 0) {
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
        return 1;
    }

    if(total < 0) {
        return 0;
    }

    if(den_size == 0 && total > 0) {
        return 0;
    }

    int without = countWays_recursive(denominations, den_size - 1, total, vec);

    vec.push_back(denominations[den_size - 1]);
    int with = countWays_recursive(denominations, den_size, total - denominations[den_size - 1], vec);
    vec.pop_back();

    return with + without;
}

bool doubleEquals(double a, double b, double epsilon = 0.001) {
    return std::abs(a - b) < epsilon;
}

int countWaysRecursive(double denominations[], int den_size, double total, vector<double> vec, double finalVal) {

    if(doubleEquals(total, finalVal)) {
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
        return 1;
    }

    if(total < 0) {
        return 0;
    }

    if(den_size == 0 && total > 0) {
        return 0;
    }

    int without = countWaysRecursive(denominations, den_size - 1, total, vec, finalVal);

    vec.push_back(denominations[den_size - 1]);
    int with = countWaysRecursive(denominations, den_size, total - denominations[den_size - 1], vec, finalVal);
    vec.pop_back();

    return with + without;
}

int main() {

    // total value
    int total = 15;
    int denominations[] = {25, 10, 5, 1};

    unordered_map<int, string> names;
    names[1] = "pennies";
    names[5] = "nickels";
    names[10] = "dimes";
    names[25] = "quarters";

    vector<int> vec;
    cout << "Total combinations iteratively: " << countWays_iterative(total) << endl;
    cout << "All Combinations" << endl;
    cout << "Total combinations recursively: " << endl;
    int total_ways = countWays_recursive(denominations, 4, total, vec);
    cout << "total combinations = " << total_ways << endl;

    double arr[] = {5.80, 4.20, 3.55, 3.35, 2.75, 2.15};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    //double sum = 4.90;
    double sum = 4.30;
    vector<double> vecDouble;
    double finalVal = 0;
    cout << "Double ways" << endl;
    countWaysRecursive(arr, arr_size, sum, vecDouble, finalVal);

    return 0;
}

