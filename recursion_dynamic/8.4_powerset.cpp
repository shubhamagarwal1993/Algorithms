#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void powerSet_iterate(char *set, int set_size)
{
	// Size of power set will be 2^n as each element has choice of present or absent in subset
	int pow_set_size = pow(2, set_size);

	// counter 000..0 to 111..1
	for(int counter = 0; counter < pow_set_size; counter++)
	{
		for(int j = 0; j < set_size; j++)
		{
			// Check if jth bit in counter is set
			if ( counter & (1 << j) )
				cout << set[j] << " ";
		}
		cout << endl;
	}
}

void printSet(char array[], int size)
{
	cout << "{ ";
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";

	cout << "}" << endl;
	return;
}

void powerSet_recursive(char *input, char s[], int k, int m, int size)
{
	if (m < size)
	{
		s[k] = input[m];
		printSet(s, k+1);
		powerSet_recursive(input, s, k+1, m+1, size);
		powerSet_recursive(input, s, k, m+1, size);
		return;
	}
}

int main()
{
	char input[] = {'a','b','c'};
/*
	//iterative method
	powerSet_iterate(input, 3);
*/
/*
	//recursive method
	int k = 0, m = 0, size = sizeof(input)/sizeof(*input);
	char stack[size];
	cout << "{}" << endl;
	powerSet_recursive(input, stack, k, m, size);
*/

	//string permutation without duplicates
	







	return 0;
}

