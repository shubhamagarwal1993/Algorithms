#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int* array_merge(int arr1[], int arr1_size, int arr2[], int arr2_size) {
    // create temp array
    int *arr = new int[arr1_size + arr2_size];

    // merge arr1 and arr2 into arr
    int arr1_index = 0;
    int arr2_index = 0;
    int arr_index = 0;
    while(arr1_index < arr1_size && arr2_index < arr2_size) {
        if(arr1[arr1_index] <= arr2[arr2_index]) {
            arr[arr_index] = arr1[arr1_index];
            arr1_index++;
        } else {
            arr[arr_index] = arr2[arr2_index];
            arr2_index++;
        }
        arr_index++;
    }
    while(arr1_index < arr1_size) {
        arr[arr_index] = arr1[arr1_index];
        arr_index++;
        arr1_index++;
    }
    while(arr2_index < arr2_size) {
        arr[arr_index] = arr2[arr2_index];
        arr_index++;
        arr2_index++;
    }
    return arr;
}

void array_merge_inplace(int arr1[], int arr1_size, int arr2[], int arr2_size) {

    for(int i = arr2_size - 1; i >= 0; i--) {

        // record last element as it will be needed later
        int arr1_last = arr1[arr1_size-1];
        int j;

        // shift all elements larger than arr2[i] to make space for arr2[i]
        for(j = arr1_size-2; (j >= 0) && arr1[j] > arr2[i]; j--) {
            arr1[j+1] = arr1[j];
        }

        // if we found a greater element than arr2[i], or the last element of 
        // arr1 is the only one greater than arr2, then place arr2
        if(j != arr1_size-2 || arr1_last > arr2[i]) {
            arr1[j+1] = arr2[i];
            arr2[i] = arr1_last;
        }
    }
}

int main() {
    int arr1[5] = {3, 5, 8, 11, 23};
    int arr2[8] = {1, 5, 6, 8, 19, 20, 23, 26};
    int arr1_size = sizeof(arr1)/sizeof(arr1[0]);
    int arr2_size = sizeof(arr2)/sizeof(arr2[0]);

    // Time: O(n1 + n2), Space: O(n1 + n2)
    int *arr3 = array_merge(arr1, arr1_size, arr2, arr2_size);
    for(int i = 0; i < arr1_size + arr2_size; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    array_merge_inplace(arr1, arr1_size, arr2, arr2_size);
    for(int i = 0; i < arr1_size; i++) {
        cout << arr1[i] << " ";
    }
    for(int i = 0; i < arr2_size; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
