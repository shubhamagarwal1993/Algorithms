#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int LIS(int arr[], int arr_size) {

    // will store index here for increasing subsequence here
    int lis[arr_size];
    for(int i = 0; i < arr_size; i++) {
        lis[i] = 1;
    }

    // loop over and give higher index for greater values
    for(int i = 1; i < arr_size; i++) {
        for(int j = 0; j < i; j++) {
            if((arr[i] > arr[j]) && (lis[i] < lis[j]+1)) {
                lis[i] = lis[j]+1;
            }
        }
    }

    // Get the highest index - that will be the size of the lis
    int max = 0;
    vector<int> lis_vec;
    for(int i = 0; i < arr_size; i++) {
        if(max < lis[i]) {
            max = lis[i];
            lis_vec.push_back(arr[i]);
        }
    }

    // print lis
    for(int i = 0; i < lis_vec.size(); i++) {
        cout << lis_vec[i] << " ";
    }
    cout << endl;

    return max;
}

int main() {

    int arr[] = {3, 10, 2, 1, 20};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    // Time complexity O(n^2)
    cout << LIS(arr, arr_size) << endl;

    return 0;
}

