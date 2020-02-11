#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void powerSet_iterate(char *set, int set_size) {
    // Size of power set will be 2^n as each element has choice of present or absent in subset
    int pow_set_size = pow(2, set_size);

    // counter 000 to 111
    for(int counter = 0; counter < pow_set_size; counter++) {
        cout << "{ ";
        // compare against 001 010 100
        for(int j = 0; j < set_size; j++) {
            // Check if jth bit in counter is set
            if( counter & (1 << j) )
                cout << set[j] << " ";
        }
        cout << "}";
        cout << endl;
    }
}

void printSet(char array[], int size) {
    cout << "{ ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";

    cout << "}" << endl;
    return;
}

void powerSet_recursive(char *input, char s[], int k, int m, int size) {
    if(m < size) {
        s[k] = input[m];
        printSet(s, k+1);
        powerSet_recursive(input, s, k+1, m+1, size);
        powerSet_recursive(input, s, k, m+1, size);
        return;
    }
}

void set_helper(int arr[], int size, int subset[], int index) {
    // if out of array and competed subset, print the subset
    if(index == size) {
        for(int i = 0; i < size; i++) {
            cout << subset[i] << "_";
        }
        cout << endl;
    } else {
        subset[index] = 0;
        set_helper(arr, size, subset, index+1);
        subset[index] = arr[index];
        set_helper(arr, size, subset, index+1);
    }
}

void powerset_simple(char arr[], int arr_size, int idx, vector<char> comb) {

    if(arr_size == 0) {
        cout << "{";
        for(int i = comb.size() - 1; i >= 0; i--) {
            cout << comb[i] << " ";
        }
        cout << "}" << endl;
        return;
    }

    // without
    powerset_simple(arr, arr_size - 1, idx + 1, comb);

    // with
    comb.push_back(arr[arr_size - 1]);
    powerset_simple(arr, arr_size - 1, idx + 1, comb);
    comb.pop_back();
}

int main() {
    char input[] = {'a','b','c'};
    int input_size = sizeof(input)/sizeof(*input);

    cout << input_size << endl;
    //iterative method
    // powerSet_iterate(input, sizeof(input)/sizeof(*input));

    //recursive method
    //int k = 0, m = 0, size = sizeof(input)/sizeof(*input);
    //char stack[size];
    //cout << "{}" << endl;
    //powerSet_recursive(input, stack, k, m, size);

    // test recursive method
    //int array1[] = {1, 2};
    //int array1_size = 2;
    //int subset[] = {array1_size};
    //set_helper(array1, array1_size, subset, 0);

    vector<char> comb;
    powerset_simple(input, input_size, 0, comb);
    return 0;
}

