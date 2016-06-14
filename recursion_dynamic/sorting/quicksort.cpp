#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition (int array[], int l, int r)
{
	int x = array[r];
	int i = (l - 1);

	for (int j = l; j <= r- 1; j++)
	{
		if (array[j] <= x)
		{
			i++;
			swap (array[i], array[j]);
		}
	}

	swap (array[i + 1], array[r]);
	return (i + 1);
}

void quicksort_recursive(int array[], int l, int r)
{
	if (l < r)
	{
		int mid = partition(array, l, r);
		quicksort_recursive(array, l, mid-1);
		quicksort_recursive(array, mid+1, r);
	}
}

void quicksort_iterative(int array[], int l, int r)
{
	// Create an auxiliary stack
	int stack[ r - l + 1 ];

	// initialize top of stack
	int top = -1;

	// push initial values of l and h to stack
	stack[ ++top ] = l;
	stack[ ++top ] = r;

	// Keep popping from stack while is not empty
	while ( top >= 0 )
	{
		// Pop h and l
		r = stack[ top-- ];
		l = stack[ top-- ];

		// Set pivot element at its correct position in sorted array
		int p = partition( array, l, r);

		// If there are elements on left side of pivot, then push left side to stack
		if ( p-1 > l )
		{
			stack[ ++top ] = l;
			stack[ ++top ] = p - 1;
		}

		// If there are elements on right side of pivot, then push right side to stack
		if ( p+1 < r )
		{
			stack[ ++top ] = p + 1;
			stack[ ++top ] = r;
		}
	}
}




int main()
{
	
	//	Recursive quick sort
	int array[] = {6, 5, 2, 1};
	int array_size = sizeof(array)/sizeof(array[0]);
	quicksort_recursive(array, 0, array_size-1);
	for (int i = 0; i < array_size; i++)
		cout << array[i] << " ";
	cout << endl;
	
/*
	//	Iterative quick sort
	int array[] = {6, 5, 2, 1};
	int array_size = sizeof(array)/sizeof(array[0]);
	quicksort_iterative(array, 0, array_size-1);
	for (int i = 0; i < array_size; i++)
		cout << array[i] << " ";
	cout << endl;
*/

	return 0;
}
