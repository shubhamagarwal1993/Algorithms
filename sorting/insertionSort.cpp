#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int array[], int array_size) {
    for(int i = 1; i < array_size; i++) {
        int key = array[i];
        int prev_index = i - 1;

        // move elements greater than array[i] from 0 to i-1 to right by one position
        while(prev_index >= 0 && array[prev_index] > key) {
            array[prev_index + 1] = array[prev_index];
            prev_index--;
        }
        array[prev_index+1] = key;
    }
}

int main() {

    int array[] = {6, 5, 2, 1};
    int array_size = sizeof(array)/sizeof(array[0]);
    insertionSort(array, array_size);

    for(int i = 0; i < array_size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

