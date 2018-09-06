#include <iostream>

using namespace std;

void merge(int arr[], int l, int mid, int r) {

    // create 2 temp arrays, one including mid, and other not including mid
    int arr1_size = mid - l + 1;
    int arr2_size = r - mid;
    int arr1[arr1_size];
    int arr2[arr2_size];

    // copy data from arr into arr1 and arr2
    for(int i = 0; i < arr1_size; i++) {
        arr1[i] = arr[l+i];
    }
    for(int i = 0; i < arr2_size; i++) {
        arr2[i] = arr[mid + 1 + i];
    }

    // merging the 2 arrays
    int arr1_index = 0;
    int arr2_index = 0;
    int arr_index = l;  // start at left index and not 0
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

    // copy any remaining value into array
    // only one while loop will run below, the longer array
    while(arr1_index < arr1_size) {
        arr[arr_index] = arr1[arr1_index];
        arr1_index++;
        arr_index++;
    }

    while(arr2_index < arr2_size) {
        arr[arr_index] = arr2[arr2_index];
        arr2_index++;
        arr_index++;
    }
    return;
}

void mergesortRecursive(int arr[], int l, int r) {

    if(l < r) {
        int mid = (l+r)/2;      // if size 10; l=0, r = 9, mid = 4

        mergesortRecursive(arr, l, mid);
        mergesortRecursive(arr, mid+1, r);

        merge(arr, l, mid, r);
    }

    // Finding time complexity
    // T(n) = T(n/2) + T(n/2) + O(n)
    // T(0) = 0
    //           n
    //      n/2     n/2
    //  n/4  n/4  n/4  n/4
    //
    //  sum of each level = n
    //  value of each node = n/(2^l)
    //  n/(2^l) = 2 at last level. Thus n = 2^l => l = logn base 2
    //  Total work = height of tree * sum of each level => logn * n => O(nlogn)
}

void mergesortIterative(int arr[], int arr_size) {

    for(int curr_size = 1; curr_size <= arr_size-1; curr_size = 2*curr_size) {
        for(int left_start = 0; left_start < arr_size-1; left_start += 2*curr_size) {
            int mid = (left_start + curr_size - 1);

            int right_end = min(left_start + 2*curr_size - 1, arr_size - 1);

            merge(arr, left_start, mid, right_end);
        }
    }
    return;
}

void printArray(int arr[], int arr_size) {

    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

int main() {

    // Recursive merge sort
    int arr1[] = {6, 65, 5, 32, 2, 0, 1, 9};
    int arr1_size = sizeof(arr1)/sizeof(arr1[0]);
    int left_index = 0;
    int right_index = arr1_size - 1;
    mergesortRecursive(arr1, left_index, right_index);
    printArray(arr1, arr1_size);

    // Iterative merge sort
    int arr2[] = {6, 5, 2, 1};
    int arr2_size = sizeof(arr2)/sizeof(arr2[0]);
    mergesortIterative(arr2, arr2_size);
    for(int i = 0; i < arr2_size; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}

