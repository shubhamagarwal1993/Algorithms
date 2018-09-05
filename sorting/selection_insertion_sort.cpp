#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void printArray(int arr[], int arr_size) {
    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * Sorts an array by repeatedly finding the minimum element
 * from unsorted part and putting it at the beginning of the unsorted part
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 */
void selectionSort(int arr[], int arr_size) {

    for(int i = 0; i < arr_size - 1; i++) {

        // lowest index of unsorted array
        int min_idx = i;
        for(int j = i + 1; j < arr_size; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the lowest element of unsorted array with smallest element found
        swap(&arr[min_idx], &arr[i]);
    }
    return;
}

/**
 * Sorts an array by finding a smaller number and shifting elements to the right
 * by one, and putting it at the beginning of the unsorted part
 *
 * Time Complexity: O(n * n)
 * Space Complexity: O(1)
 *
 */
void insertionSort(int arr[], int arr_size) {
    for(int i = 1; i < arr_size; i++) {
        int key = arr[i];
        int prev_index = i - 1;

        // move elements greater than array[i] from 0 to i-1 to right by one position
        while(prev_index >= 0 && arr[prev_index] > key) {
            arr[prev_index + 1] = arr[prev_index];
            prev_index--;
        }
        arr[prev_index+1] = key;
    }
}

/**
 * find the position where item should be inserted in a[low..high]
 */
int binarySearch(int arr[], int item, int low, int high) {

    if(high <= low) {
        return (item > arr[low]) ?  (low + 1) : low;
    }

    int mid = (low + high)/2;

    if(item == arr[mid]) {
        return mid+1;
    }

    if(item > arr[mid]) {
        return binarySearch(arr, item, mid+1, high);
    }

    return binarySearch(arr, item, low, mid-1);
}

/**
 * Sorts an array by finding a smaller number and shifting elements to the right
 * by one, and putting it at the beginning of the unsorted part
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 */
void binaryInsertionSort(int arr[], int arr_size) {
    for(int i = 1; i < arr_size; i++) {
        int key = arr[i];
        int prev_index = i - 1;

        int loc = binarySearch(arr, key,  0, prev_index);

        // move elements greater than array[i] from 0 to i-1 to right by one position
        while(prev_index >= loc) {
            arr[prev_index + 1] = arr[prev_index];
            prev_index--;
        }
        arr[prev_index+1] = key;
    }
}

int main() {

    int arr1[] = {6, 5, 2, 1};
    int arr1_size = sizeof(arr1)/sizeof(arr1[0]);
    selectionSort(arr1, arr1_size);
    printArray(arr1, arr1_size);

    int arr2[] = {6, 5, 2, 1};
    int arr2_size = sizeof(arr2)/sizeof(arr2[0]);
    insertionSort(arr2, arr2_size);
    printArray(arr2, arr2_size);

    int arr3[] = {6, 5, 2, 1};
    int arr3_size = sizeof(arr3)/sizeof(arr3[0]);
    binaryInsertionSort(arr3, arr3_size);
    printArray(arr3, arr3_size);

    return 0;
}

