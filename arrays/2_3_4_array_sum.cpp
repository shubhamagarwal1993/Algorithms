// compile using g++ -std=c++0x 2_3_4_array_sum.cpp

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void two_sum(int arr[], int arr_size, int sum)
{
	int temp;
	unordered_map<int, int> mymap;

	for (int i = 0; i < arr_size; i++)
	{
		temp = sum - arr[i];
		if (temp >= 0 && mymap[temp] == 1)
			cout << "Pair with given sum " << sum << " is " << arr[i] << ", " << temp << endl;
		else
			mymap[ arr[i] ] = 1;
	}
}

void three_sum(int arr[], int arr_size, int sum)
{
	int left, right;
	sort(arr, arr + arr_size);

	for (int i = 0; i < arr_size-2; i++)
	{
		left = i+1;
		right = arr_size - 1;

		while(left < right)
		{
			if (arr[i] + arr[left] + arr[right] == sum)
			{
				cout << "triplet with given sum " << sum << " is " << arr[i] << ", " << arr[left] << ", " << arr[right] << endl;
				left++;
			}
			else if (arr[i] + arr[left] + arr[right] < sum)
				left++;
			else
				right--;
		}
	}
}

class x_y
{
	public:
		int sum;
		int x;
		int y;
};

bool comp(x_y const & a, x_y const & b)
{
	return a.sum < b.sum;
}

bool not_repeat(x_y a, x_y b)
{
	if (a.x == b.x || a.x == b.y || a.y == b.x || a.y == b.y)
		return false;
	return true;
}

void four_sum(int arr[], x_y temp_arr[], int arr_size, int temp_arr_size, int final_sum)
{
	int k = 0;
	for (int i = 0; i < arr_size-1; i++)
	{
		for (int j = i+1; j < arr_size; j++)
		{
			temp_arr[k].sum = arr[i]+arr[j];
			temp_arr[k].x = i;
			temp_arr[k].y = j;
			k++;
		}
	}

//	for (int q = 0; q < k; q++)
//		cout << temp_arr[q].sum << endl;

	std::sort(temp_arr, temp_arr+temp_arr_size, comp);

//	for (int q = 0; q < k; q++)
//		cout << temp_arr[q].sum << endl;

	int l = 0, r = arr_size-1;
	while(r >= 0 && l < temp_arr_size)
	{
		if ((temp_arr[l].sum + temp_arr[r].sum == final_sum) && (not_repeat(temp_arr[l], temp_arr[r])))
		{
			cout << final_sum << " = " << arr[temp_arr[l].x] << ", " << arr[temp_arr[l].y] << ", " << arr[temp_arr[r].x] << ", " << arr[temp_arr[r].y] << endl;
			l++;
		}
		else if (temp_arr[l].sum + temp_arr[r].sum < final_sum)
			l++;
		else
			r--;
	}
}

int main()
{
/*
	// 2 sum
	int arr[6] = {1, 4, 45, 6, 10, 8};
	int sum = 16;
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	two_sum(arr, arr_size, sum);
*/
/*
	// 3 sum
	int arr[8] = {1, 4, 45, 6, 10, 8, 19, 2};
	int sum = 22;
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	three_sum(arr, arr_size, sum);
*/

	// 4 sum
	int arr[8] = {10, 20, 30, 40, 1, 2, 25, 16};
	int final_sum = 91;
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int temp_arr_size = arr_size*(arr_size-1)/2;
	x_y temp_arr[temp_arr_size];					//will store all sum pairs here
	four_sum(arr, temp_arr, arr_size, temp_arr_size, final_sum);

	return 0;
}
