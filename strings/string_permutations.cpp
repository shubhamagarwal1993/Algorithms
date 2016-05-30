#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

//  swap values for x and y
void swap(char &x, char &y)
{
	char temp;
	temp = x;
	x = y;
	y = temp;
}

int factorial(int n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

//print permutations of string using recursion
void permute_recursion(string a, int l_index, int r_index)
{
	if (l_index == r_index)
		cout << a << endl;
	else
	{
		for (int i = l_index; i <= r_index; i++)
		{
			swap( a[l_index], a[i]);
			permute_recursion(a, l_index+1, r_index);
			swap( a[l_index], a[i]);
		}
	}
}
/*
//iterative method -> DOES NOT WORK
void permutation_iter(string &st, int st_length, int st_factorial)
{
	for(int i = 0; i < st_factorial; i++)
	{
		int j = i % (st_length - 1);
		swap_recursion( st[j], st[j+1]);
		for (int k = 0; k < st_length; k++)
			cout << st[k] << " ";
		cout << endl;
	}
}
*/
int main()
{
	//using recursion
	string str = "AA";
	int length = str.length();
	permute_recursion(str, 0, length-1);
	cout << endl;

	//standard c++ built in function
	string s = "ABCD";
	vector <char> vec;
	for(int i = 0; i < s.length(); i++)
	{
		vec.push_back(s[i]);
		cout << s[i] << " ";
	}
	cout << endl;
	while(next_permutation(vec.begin(), vec.end()))
	{
		for(vector<char>::iterator it = vec.begin(); it != vec.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
/*
	//iterative method -> DOES NOT WORK
	string st = "ABCD";
	int st_factorial = factorial(st.length());
	permutation_iter(st, st.length(), st_factorial);
*/
	return 0;
}

