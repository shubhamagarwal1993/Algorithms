#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printNonRepeating(int arr[], int size) {
    int xor_sum = arr[0];          // xor of all elements
    int set_bit_no;                // Will have only single set bit of xor
    int i;
    int x = 0, y = 0;

    // Get the xor of all elements in arr[] and {1, 2 .. n}
    for(i = 1; i < size; i++)
        xor_sum ^= arr[i];

    //cout << xor_sum << endl;

    // Get the rightmost set bit in set_bit_no
    set_bit_no = xor_sum & ~(xor_sum-1);

    //cout << set_bit_no << endl;

    // divide elements in two sets by comparing rightmost set bit of xor with bit at same position in each element
    for(i = 0; i < size; i++) {
        if(arr[i] & set_bit_no)
            x = x ^ arr[i];                // XOR of first set in arr[]
        else
            y = y ^ arr[i];                // XOR of second set in arr[]
    }

    cout << "The two repeating elements are " << x << " " << y << endl;
}

int main() {
    int arr[] = {4, 2, 4, 5, 2, 3, 1, 5};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printNonRepeating(arr, arr_size);
    return 0;
}

