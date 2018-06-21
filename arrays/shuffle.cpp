// Given an array, write a program to generate a random permutation of array elements
// This question is also asked as “shuffle a deck of cards”

#include <iostream>

using namespace std;

void shuffle(int arr[], int arr_size) {

    // seed valud
    srand(time(NULL));

    // Start from last element and swap one by one
    // Do not swap for first element as it is already done
    for(int i = arr_size - 1; i > 0; i--) {
        
        // get a random index from 0 to i, thus we mod with i+1 to include i
        int shuffle_index = rand() % (i+1);

        // swap shuffle_index with current element
        swap(arr[shuffle_index], arr[i]);
    }
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout << "Original Array: ";
    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Shuffle array: Time O(n) and Space O(1)
    shuffle(arr, arr_size);
    cout << "Shuffled Array: ";
    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
