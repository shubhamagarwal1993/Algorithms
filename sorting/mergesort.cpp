#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int array[], int l, int mid, int r)
{
	//create 2 temp arrays
	int size_1 = mid - l + 1;
	int size_2 = r - mid;

	int array_1[size_1];
	int array_2[size_2];

	//copy data from array into array_1 and array_2
	for (int i = 0; i < size_1; i++)
		array_1[i] = array[l+i];
	for (int i = 0; i < size_2; i++)
		array_2[i] = array[mid + 1 + i];

	//merging the 2 arrays
	int i = 0, j = 0, k = l;
	while (i < size_1 && j < size_2)
	{
		if (array_1[i] <= array_2[j])
		{
			array[k] = array_1[i];
			i++;
		}
		else
		{
			array[k] = array_2[j];
			j++;
		}
		k++;
	}

	while(i < size_1)
	{
		array[k] = array_1[i];
		i++;
		k++;
	}

	while(j < size_2)
	{
		array[k] = array_1[j];
		j++;
		k++;
	}
}

void mergesort_recursive(int array[], int l, int r)
{
	if (l < r)
	{
		int mid = (l+r)/2;				//if size 10; l=0, r = 9, mid = 5

		mergesort_recursive(array, l, mid);
		mergesort_recursive(array, mid+1, r);
	
		merge(array, l, mid, r);
	}
}

void mergesort_iterative(int array[], int array_size)
{
	for (int curr_size = 1; curr_size <= array_size-1; curr_size = 2*curr_size)
	{
		for (int left_start = 0; left_start < array_size-1; left_start += 2*curr_size)
		{
			int mid = (left_start+curr_size-1);

			int right_end = min (left_start + 2*curr_size-1, array_size-1);

			merge(array, left_start, mid, right_end);
		}
	}
}

int main()
{
	/*
	//	Recursive merge sort
	int array[] = {6, 5, 2, 1};
	int array_size = sizeof(array)/sizeof(array[0]);
	mergesort_recursive(array, 0, array_size-1);
	for (int i = 0; i < array_size; i++)
		cout << array[i] << " ";
	cout << endl;
	*/

	//	Iterative merge sort
	int array[] = {6, 5, 2, 1};
	int array_size = sizeof(array)/sizeof(array[0]);
	mergesort_iterative(array, array_size);
	for (int i = 0; i < array_size; i++)
		cout << array[i] << " ";
	cout << endl;


	return 0;
}
