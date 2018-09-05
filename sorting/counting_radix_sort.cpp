#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int arr_size) {
    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * sorting technique based on keys between a specific range
 * It works by counting the number of objects having distinct key values (kind of hashing)
 * Then doing some arithmetic to calculate the position of each object in the output sequence
 *
 * Only efficient if range of input data is not significantly greater than number of objects to be sorted
 *
 * Time Complexity: O(n+k), n is number of elements, k is range of input
 * Space Complexity: O(n+k)
 */
void countingSort(int arr[], int arr_size, int range) {

    int output[arr_size];

    // Create count array to store count of inidividual ints
    int count[range + 1];
    for(int i = 0; i <= range; i++) {
        count[i] = 0;
    }

    // Store count of each int
    for(int i = 0; i < arr_size; i++) {
        count[arr[i]]++;
    }
 
    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for(int i = 1; i <= range; i++) {
        count[i] += count[i-1];
    }
 
    // Build the output character array
    for(int i = 0; i < arr_size; i++) {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to arr
    for(int i = 0; i < arr_size; i++) {
        arr[i] = output[i];
    }
}

/*
 * A utility function to get max value in arr[]
 */
int getMax(int arr[], int arr_size)  {
    int max = arr[0];
    for(int i = 1; i < arr_size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/**
 * Sorting technique bases on digit by digit sort starting from least significant digit to most significant digit
 *
 * This works if range of input data is significantly greater than number of objects to be sorted
 * User counting sort as a subroutine
 *
 * Time Complexity: O(d*(n+b)), d digits in input ints, b is base for representing nums -> 10, k is range of input
 * Space Complexity: O(n)
 */
void radixSort(int arr[], int arr_size) {

    // Find the maximum number to know number of digits
    int max_digits = getMax(arr, arr_size);

    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for(int exp = 1; max_digits/exp > 0; exp *= 10) {
        countingSort(arr, arr_size, exp);
    }
}

int main() {

    int range = 6;
    int arr1[] = {6, 5, 2, 1};
    int arr1_size = sizeof(arr1)/sizeof(arr1[0]);
    countingSort(arr1, arr1_size, range);
    printArray(arr1, arr1_size);

    int arr2[] = {6, 5, 2, 1};
    int arr2_size = sizeof(arr2)/sizeof(arr2[0]);
    radixSort(arr2, arr2_size);
    printArray(arr2, arr2_size);

    return 0;
}

