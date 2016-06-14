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

int kth_smallest_quicksort(int array[], int l, int r, int k)
{
	// If k is smaller than number of elements in array
	if (k > 0 && k <= r - l + 1)
	{
		// Partition the array around last element and get position of pivot element in sorted array
		int pos = partition(array, l, r);

		// If position is same as k
		if (pos-l == k-1)
			return array[pos];

		if (pos-l > k-1)  // If position is more, recur for left subarray
			return kth_smallest_quicksort(array, l, pos-1, k);

		// Else recur for right subarray
		return kth_smallest_quicksort(array, pos+1, r, k-pos+l-1);
    }
 
    // If k is more than number of elements in array
    return -1;
}

int main()
{
	//	Sorting and find k smallest/largest element
			//Running time will be O(nlog(n)) using quicksort or mergesort

	//	Using min/max heap - will have to pull elements first. Then extract elements k times
			//Takes extra space and unnecessary extra sorting


	//	Using partial quicksort
		//Do quicksort till a point where pivot is kth smallest element. Recur only left or right side, but noth both
			//Worst case running time is O(n^2) and avg is O(n).
			//No extra space used

	//value of k
	int k = 3;

	//finding the kth smallest element
	int array[] = {22, 30, 18, 4, 71, 45, 11};
	int k_small = k;
	int array_size = sizeof(array)/sizeof(array[0]);
	cout << k_small << "th smallest element: " << kth_smallest_quicksort(array, 0, array_size-1, k_small) << endl;

	//finding the kth largest element
	int k_large = array_size - k + 1;
	cout << k << "th largest element: " << kth_smallest_quicksort(array, 0, array_size-1, k_large) << endl;
	
	return 0;
}
