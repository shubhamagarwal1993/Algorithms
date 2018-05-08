#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition (int array[], int l, int r) {
    int pivot = array[r];
    int i = (l - 1);

    for (int j = l; j < r; j++) {
        if (array[j] <= pivot) {
            i++;
            swap (array[i], array[j]);
        }
    }

    swap (array[i + 1], array[r]);
    return (i + 1);
}

void quicksort_recursive(int array[], int l, int r) {
    if (l < r) {
        int mid = partition(array, l, r);
        quicksort_recursive(array, l, mid-1);
        quicksort_recursive(array, mid+1, r);
    }
}

void quicksort_iterative(int array[], int l, int r) {
    // Create an auxiliary stack
    int stack[ r - l + 1 ];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = r;

    // Keep popping from stack while is not empty
    while ( top >= 0 ) {
        // Pop h and l
        r = stack[ top-- ];
        l = stack[ top-- ];

        // Set pivot element at its correct position in sorted array
        int p = partition( array, l, r);

        // If there are elements on left side of pivot, then push left side to stack
        if ( p-1 > l ) {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }

        // If there are elements on right side of pivot, then push right side to stack
        if ( p+1 < r ) {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = r;
        }
    }
}

// Kth element, partially sort the array till an element has kth position
int kthSmallestElement(int array[], int l, int r, int k) {
    if(k > 0 && k <= r - l + 1) {

        int pivot = partition(array, l, r);

        // if pivot is the position needed
        if(pivot - l == k - 1) {
            return array[pivot];
        }

        // if pivot is greater than k, recur on left side
        if(pivot - l > k - 1) {
            return kthSmallestElement(array, l, pivot - 1, k);
        }

        // else recur on the right side
        return kthSmallestElement(array, pivot + 1, r, k - pivot + l - 1);
    }
    return -1;
}

// partially sort till all elements upto kth position are sorted
int firstKSmallestElements(int array[], int l, int r, int k) {
    if(k > 0 && k <= r - l + 1) {

        int pivot = partition(array, l, r);

        // if pivot is the position needed
        if(pivot - l == k - 1) {
            return array[pivot];
        }

        // if pivot is greater than k, recur on left side
        if(pivot - l > k - 1) {
            return kthSmallestElement(array, l, pivot - 1, k);
        }

        // else recur on the right side
        return kthSmallestElement(array, pivot + 1, r, k - pivot + l - 1);
    }
    return -1;
}

int main() {

    // MergeSort = picks element as pivot and partitions the array around the picked pivot
    // Thus, pivot ends up in its correct position and all smaller than pivot elements are before the pivot

    // Recursive quick sort
    int array1[] = {6, 5, 2, 1, 9, 7, 3};
    int array1_size = sizeof(array1)/sizeof(array1[0]);
    quicksort_recursive(array1, 0, array1_size-1);
    for (int i = 0; i < array1_size; i++)
        cout << array1[i] << " ";
    cout << endl;

    // Iterative quick sort
    int array2[] = {6, 5, 2, 1, 9, 7, 3};
    int array2_size = sizeof(array2)/sizeof(array2[0]);
    quicksort_iterative(array2, 0, array2_size-1);
    for (int i = 0; i < array2_size; i++)
        cout << array2[i] << " ";
    cout << endl;

    // quickSelect - find kth smallest element
    int array3[] = {6, 5, 2, 1, 9, 7, 3};
    int array3_size = sizeof(array3)/sizeof(array3[0]);
    int k = 4;
    cout << "Kth smallest element: " << kthSmallestElement(array3, 0, array3_size - 1, k) << endl;
    int array4[] = {30, 4, 8, 2, 9, 35, 7};
    int array4_size = sizeof(array4)/sizeof(array4[0]);
    firstKSmallestElements(array4, 0, array4_size - 1, k);
    cout << "First K smallest elements: ";
    for(int i = 0; i < k; i++) {
        cout << array4[i] << " ";
    }
    cout << endl;
    return 0;
}
