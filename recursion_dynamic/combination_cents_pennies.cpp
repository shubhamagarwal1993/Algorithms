/*
 * Infinite number of quarters, dime, nickles, and pennies
 * Number of ways of representing n cents
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void combinationsIterative(int total, int denominations[], int denominations_size, unordered_map<int, string> denomination_names) {
    // store possible combinations for each penny
    int table[total+1];
    for(int i = 0; i < total + 1; i++) {
        table[i] = 0;
    }

    // base case - if total is 0
    table[0] = 1;

    // increase possible combination count for each cent that can be matched by 1 cent
    for(int i = 1; i <= total; i++) {
        table[i] += table[i-1];
    }

    // increase possible combination count for each cent that can be matched by 5 cents
    for(int i = 5; i <= total; i++) {
        table[i] += table[i-5];
    }

    // increase possible combination count for each cent that can be matched by 10 cents
    for(int i = 10; i <= total; i++) {
        table[i] += table[i-10];
    }

    // increase possible combination count for each cent that can be matched by 25 cents
    for(int i = 25; i <= total; i++) {
        table[i] += table[i-25];
    }

    // The last value is the max possible combinations
    cout << "Max possible combinations iteratively: " << table[total] << endl << endl;
    return;
}

int combinationsRecursiveUtil(int denominations[], int denominations_size, int total, vector<int>combination_vec) {

    if(total < 0) {
        return 0;
    }

    if(total == 0) {
        for(int i = 0; i < combination_vec.size(); i++) {
            cout << combination_vec[i] << " ";
        }
        cout << endl;
        return 1;
    }

    if(denominations_size == 0 && total > 0) {
        return 0;
    }

    if(denominations_size < 0) {
        return 0;
    }

    // Possible combination without including denomination
    int without = combinationsRecursiveUtil(denominations, denominations_size - 1, total, combination_vec);

    // Possible combination including denomination
    combination_vec.push_back(denominations[denominations_size - 1]);
    int with = combinationsRecursiveUtil(denominations, denominations_size, total - denominations[denominations_size - 1], combination_vec);
    combination_vec.pop_back();

    return with + without;
}

void combinationsRecursive(int total, int denominations[], int denominations_size, unordered_map<int, string> denomination_names) {
    int combinations_total = 1;

    if(total < 0) {
        cout << "Invalid input given" << endl;
        return;
    }

    if(denominations_size == 0 && total > 0) {
        cout << "Invalid input given" << endl;
        return;
    }

    if(total == 0) {
        cout << "Total combinations: " << combinations_total << endl;
        return;
    }

    // Store current valid combination
    vector<int> combination_vec;
    combinations_total = combinationsRecursiveUtil(denominations, denominations_size, total, combination_vec);
    cout << "Total combinations " << combinations_total << endl << endl;
    return;
}

bool doubleEquals(double a, double b, double epsilon = 0.001) {
    //return std::abs(a - b) < epsilon;
    return fabs(a - b) < std::numeric_limits<double>::epsilon();
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
    int denominations_size = sizeof(denominations)/sizeof(denominations[0]);

    unordered_map<int, string> denomination_names;
    denomination_names[1] = "cents";
    denomination_names[5] = "nickels";
    denomination_names[10] = "dimes";
    denomination_names[25] = "quarters";

    // Find all possible combinations iteratively
    combinationsIterative(total, denominations, denominations_size, denomination_names);

    // Find all possible combinations recursively
    combinationsRecursive(total, denominations, denominations_size, denomination_names);

    // double arr[] = {5.80, 4.20, 3.55, 3.35, 2.75, 2.15};
    // int arr_size = sizeof(arr) / sizeof(arr[0]);
    // //double sum = 4.90;
    // double sum = 4.30;
    // vector<double> vecDouble;
    // double finalVal = 0;
    // cout << "Double ways" << endl;
    // countWaysRecursive(arr, arr_size, sum, vecDouble, finalVal);

    return 0;
}

