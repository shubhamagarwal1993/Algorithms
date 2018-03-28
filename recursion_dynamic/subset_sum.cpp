#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

bool subsetSum_test(int arr[], int arr_size, int sum) {
    // The value of subset[i][j] will be true if there is a 
    // subset of set[0....j-1] with sum equal to i
    bool subset[arr_size+1][sum+1];

    // if sum is 0, then answer is true
    for(int i = 0; i < arr_size+1; i++) {
        subset[i][0] = true;
    }

    // if sum is not 0 and set it empty, then answer is false
    for(int i = 1; i < sum + 1; i++) {
        subset[0][i] = false;
    }

    // fill the subset table bottom up
    for(int i = 1; i < arr_size + 1; i++) {
        for(int j = 1; j < sum + 1; j++) {
            // if smaller than previous no, then keep original sum
            if(j < arr[i-1]) {
                subset[i][j] = subset[i-1][j];
            }
            if(j >= arr[i-1]) {
                subset[i][j] = subset[i-1][j] || subset[i-1][j-arr[i-1]];
            }
        }
    }

    //
    return subset[arr_size][sum];
}

bool subsetSum(int arr[], int arr_size, int sum) {

    if(sum == 0) return true;
    if((sum != 0) && (arr_size == 0)) return false;

    if(arr[arr_size-1] > sum) {
        subsetSum(arr, arr_size-1, sum);
    }

    // check with last element included as well as excluded
    return subsetSum(arr, arr_size-1, sum - arr[arr_size-1]) || subsetSum(arr, arr_size-1, sum);
}


int main() {

    int arr[] = {6,3,4,9,2};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int sum = 8;

    // exponential time
    if(subsetSum(arr, arr_size, sum)) {
        cout << "found subset" << endl;
    } else {
        cout << "no subset" << endl;
    }

    // pseudo-polynomial time
    if(subsetSum_test(arr, arr_size, sum)) {
        cout << "found subset" << endl;
    } else {
        cout << "no subset" << endl;
    }

    return 0;
}
