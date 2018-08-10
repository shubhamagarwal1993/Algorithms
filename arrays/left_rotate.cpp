#include <iostream>

using namespace std;

// Euclidean algorithm to find GCD:
// If we subtract smaller number from larger (we reduce larger number), 
// GCD doesn’t change. So if we keep subtracting repeatedly the larger of two,
// we end up with GCD.
//
// Now instead of subtraction, if we divide smaller number,
// the algorithm stops when we find remainder 0.
int getGCD(int a, int b) {
    if(a == 0) {
        return b;
    }

    if(a == b) {
        return a;
    }

    return getGCD(b%a, a);
}

// Move the elements within sets
// number of sets = GCD of arr_size and d
//
//
void leftRotate(int arr[], int arr_size, int rotate_index) {

    int set_size = getGCD(arr_size, rotate_index);

    for(int i = 0; i < set_size; i++) {
        int set_first_value = arr[i];
        int j = i;

        while(1) {
            int set_index = j + rotate_index;

            if(set_index >= arr_size) {
                set_index = set_index - arr_size;
            }

            if(set_index == i) {
                break;
            }

            arr[j] = arr[set_index];
            j = set_index;
        }

        arr[j] = set_first_value;
    }

    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

int main() {
    int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    leftRotate(arr, 12, 3);

    return 0;
}
