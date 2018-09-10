#include <iostream>

using namespace std;

/*
 * return array with pivot at correct position
 *
 * Different ways of picking a pivot:
 *     Always pick first element as pivot
 *     Always pick last element as pivot (implemented below)
 *     Pick a random element as pivot
 *     Pick median as pivot
 */
int partition(int arr[], int l, int r) {

    // pick right most element as pivot
    int pivot = arr[r];
    int smaller_element_index = (l - 1);

    for(int j = l; j < r; j++) {
        if(arr[j] <= pivot) {
            smaller_element_index++;
            swap(arr[smaller_element_index], arr[j]);
        }
    }

    swap(arr[smaller_element_index + 1], arr[r]);
    return (smaller_element_index + 1);
}

void quicksortRecursive(int arr[], int l, int r) {
    if (l < r) {
        int mid = partition(arr, l, r);

        // dont include mid since its already in its correct position
        quicksortRecursive(arr, l, mid-1);
        quicksortRecursive(arr, mid+1, r);
    }
}

void quicksortIterative(int arr[], int l, int r) {

    int arr_size = r - l + 1;
    // Create an auxiliary stack
    int stack[arr_size];

    // initialize top of stack
    int top = 0;

    // push initial values of l and h to stack
    stack[top] = l;
    stack[++top] = r;

    // Keep popping from stack while is not empty
    while(top >= 0) {
        // Pop h and l
        r = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position in sorted array
        int p = partition(arr, l, r);

        // If there are elements on left side of pivot, then push left side to stack
        if(p-1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot, then push right side to stack
        if(p+1 < r) {
            stack[++top] = p + 1;
            stack[++top] = r;
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

void printArray(int arr[], int arr_size) {
    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    // MergeSort = picks element as pivot and partitions the array around the picked pivot
    // Thus, pivot ends up in its correct position and all smaller than pivot elements are before the pivot

    // Recursive quick sort
    int arr1[] = {6, 5, 2, 1, 9, 7, 3};
    int arr1_size = sizeof(arr1)/sizeof(arr1[0]);
    int left_index = 0;
    int right_index = arr1_size - 1;
    quicksortRecursive(arr1, left_index, right_index);
    printArray(arr1, arr1_size);

    // Iterative quick sort
    int arr2[] = {6, 5, 2, 1, 9, 7, 3};
    int arr2_size = sizeof(arr2)/sizeof(arr2[0]);
    left_index = 0;
    right_index = arr1_size - 1;
    quicksortIterative(arr2, left_index, right_index);
    printArray(arr2, arr2_size);

    // quickSelect - find kth smallest element
    int arr3[] = {6, 5, 2, 1, 9, 7, 3};
    int arr3_size = sizeof(arr3)/sizeof(arr3[0]);
    int k = 4;
    cout << "Kth smallest element: " << kthSmallestElement(arr3, 0, arr3_size - 1, k) << endl;

    int arr4[] = {30, 4, 8, 2, 9, 35, 7};
    int arr4_size = sizeof(arr4)/sizeof(arr4[0]);
    firstKSmallestElements(arr4, 0, arr4_size - 1, k);
    cout << "First K smallest elements: ";
    for(int i = 0; i < k; i++) {
        cout << arr4[i] << " ";
    }
    cout << endl;

    return 0;
}
