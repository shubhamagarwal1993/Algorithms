#include <iostream>

using namespace std;

// take an index in a heap, and heapify up to place it at its correct index
void heapifyUp(int arr[], int arr_size, int curr_index) {

    int left_child_index  = (2 * curr_index) + 1;
    int right_child_index = (2 * curr_index) + 2;

    int largest_index = curr_index;

    if(left_child_index < arr_size && arr[left_child_index] > arr[curr_index]) {
        largest_index = left_child_index;
    }

    if(right_child_index < arr_size && arr[right_child_index] > arr[largest_index]) {
        largest_index = right_child_index;
    }

    if(largest_index != curr_index) {
        swap(arr[curr_index], arr[largest_index]);
        heapifyUp(arr, arr_size, largest_index);
    }
}

// take an index in a heap, and heapify up to place it at its correct index
void heapifyDown(int arr[], int arr_size, int curr_index) {

    int left_child_index  = (2 * curr_index) + 1;
    int right_child_index = (2 * curr_index) + 2;

    int smallest_index = curr_index;

    if(left_child_index < arr_size && arr[left_child_index] < arr[curr_index]) {
        smallest_index = left_child_index;
    }

    if(right_child_index < arr_size && arr[right_child_index] < arr[smallest_index]) {
        smallest_index = right_child_index;
    }

    if(smallest_index != curr_index) {
        swap(arr[curr_index], arr[smallest_index]);
        heapifyDown(arr, arr_size, smallest_index);
    }
}

void convertMinHeapToMaxHeap(int arr[], int arr_size) {

    // Start from bottom most and right most index and heapify all nodes in bottom up manner
    for(int i = (arr_size - 2) / 2; i >= 0; i--) {
        heapifyUp(arr, arr_size, i);
    }
}

void convertMaxHeapToMinHeap(int arr[], int arr_size) {

    // Start from bottom most and right most index and heapify all nodes in bottom up manner
    for(int i = (arr_size - 2) / 2; i >= 0; i--) {
        heapifyDown(arr, arr_size, i);
    }
}

int main() {

    // array representing Min Heap
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout << "Min Heap array : ";
    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
 
    // convert a min heap to a max heap - Time complexity O(n), Space complexity O(1)
    convertMinHeapToMaxHeap(arr, arr_size);

    // print max heap
    cout << "Max Heap array : ";
    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // convert a max heap to a min heap - Time complexity O(n), Space complexity O(1)
    convertMaxHeapToMinHeap(arr, arr_size);

    // print max heap
    cout << "Max Heap array : ";
    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

