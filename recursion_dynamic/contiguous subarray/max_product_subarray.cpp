#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Utility functions to get minimum of two integers
int min (int x, int y) {return x < y? x : y; }

// Utility functions to get maximum of two integers
int max (int x, int y) {return x > y? x : y; }

int maxSubArrayProduct(int arr[], int arr_size) 

int main() {
	int arr[] = {1, -2, -3, 0, 7, -8, -2};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int max_product = maxSubArrayProduct(arr, arr_size);
	cout << "Maximum contiguous product is: " << max_product << endl;
	return 0;
}

// Initialize:
//     max_so_far = 0
//     max_ending_here = 0

// Loop for each element of the array
//   (a) max_ending_here = max_ending_here + a[i]
//   (b) if(max_ending_here < 0)
//             max_ending_here = 0
//   (c) if(max_so_far < max_ending_here)
//             max_so_far = max_ending_here
// return max_so_far