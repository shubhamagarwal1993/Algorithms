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

int main() {

    // Recursive quick sort
    int array1[] = {6, 5, 2, 1};
    int array1_size = sizeof(array1)/sizeof(array1[0]);
    quicksort_recursive(array1, 0, array1_size-1);
    for (int i = 0; i < array1_size; i++)
        cout << array1[i] << " ";
    cout << endl;

    // Iterative quick sort
    int array2[] = {6, 5, 2, 1};
    int array2_size = sizeof(array2)/sizeof(array2[0]);
    quicksort_iterative(array2, 0, array2_size-1);
    for (int i = 0; i < array2_size; i++)
        cout << array2[i] << " ";
    cout << endl;

    return 0;
}
