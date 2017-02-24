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

int maxSubArrayProduct(int arr[], int arr_size) {
	// max positive product ending at the current position
	int max_ending_here = 1;

	// min negative product ending at the current position
	int min_ending_here = 1;

	// Initialize overall max product
	int max_so_far = 1;

	/* Traverse through the array. Following values are
	maintained after the i'th iteration:
	max_ending_here is always 1 or some positive product
					ending with arr[i]
	min_ending_here is always 1 or some negative product 
					ending with arr[i] */
	for (int i = 0; i < n; i++)
	{
		/* If this element is positive, update max_ending_here. 
		Update min_ending_here only if min_ending_here is 
		negative */
		if (arr[i] > 0)
		{
			max_ending_here = max_ending_here*arr[i];
			min_ending_here = min (min_ending_here * arr[i], 1);
		}

		/* If this element is 0, then the maximum product 
		cannot end here, make both max_ending_here and 
		min_ending_here 0
		Assumption: Output is alway greater than or equal 
					to 1. */
		else if (arr[i] == 0)
		{
			max_ending_here = 1;
			min_ending_here = 1;
		}

		/* If element is negative. This is tricky
		max_ending_here can either be 1 or positive. 
		min_ending_here can either be 1 or negative.
		next min_ending_here will always be prev. 
		max_ending_here * arr[i] next max_ending_here
		will be 1 if prev min_ending_here is 1, otherwise 
		next max_ending_here will be prev min_ending_here *
		arr[i] */
		else
		{
			int temp = max_ending_here;
			max_ending_here = max (min_ending_here * arr[i], 1);
			min_ending_here = temp * arr[i];
		}

		// update max_so_far, if needed
		if (max_so_far < max_ending_here)
		    max_so_far = max_ending_here;
	}

	return max_so_far;
}


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