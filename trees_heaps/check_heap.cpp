#include <iostream>

using namespace std;

bool isHeap(int arr[], int index, int arr_size) {

    // If a leaf node
    if(index > (arr_size - 2)/2) {
        return true;
    }

    int left_child_index = (2*index + 1);
    int right_child_index = (2*index + 2);

    if((arr[index] >= arr[left_child_index])
    && (arr[index] >= arr[right_child_index])
    && (isHeap(arr, left_child_index, arr_size))
    && (isHeap(arr, right_child_index, arr_size))) {
        return true;
    }

    return false;
}

int main() {

    int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    isHeap(arr, 0, arr_size) ? cout << "Is a binary heap" << endl : cout << "Is not a heap" << endl;

    return 0;
}
