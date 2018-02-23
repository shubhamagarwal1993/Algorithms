#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
int count_coins(int n, vector<int> memo, int penny, int nickel, int dime, int quarter, int current_coin)
{	cout << "here" << endl;
	if(n < 0)
		return 0;
	else if (n == 0)
	{
		cout << penny << " " << nickel << " " << dime << " " << quarter << endl;
		return 1;
	}
	else if (memo[n] > -1)
		return memo[n];
	else
	{
		int total = 0;
		if (current_coin >= 1)
		{
			total += count_coins(n-1, memo, penny+1, nickel, dime, quarter, 1);
			memo[n] = total;
		}
		if (current_coin >= 5)
		{
			total += count_coins(n-5, memo, penny, nickel+1, dime, quarter, 5);
			memo[n] = total;
		}
		if (current_coin >= 10)
		{
			total += count_coins(n-10, memo, penny, nickel, dime+1, quarter, 10);
			memo[n] = total;
		}
		if (current_coin >= 25)
		{
			total += count_coins(n-25, memo, penny, nickel, dime, quarter+1, 25);
			memo[n] = total;
		}
		return total;
	}
}
*/
int count_coins(int n, vector<int> memo, int penny, int nickel, int dime, int quarter, int current_coin)
{	cout << "here" << endl;
	if(n < 0)
		return 0;
	else if (n == 0)
	{
		cout << penny << " " << nickel << " " << dime << " " << quarter << endl;
		return 1;
	}
	else
	{
		int total = 0;
		if (current_coin >= 1)
			total += count_coins(n-1, memo, penny+1, nickel, dime, quarter, 1);
		if (current_coin >= 5)
			total += count_coins(n-5, memo, penny, nickel+1, dime, quarter, 5);
		if (current_coin >= 10)
			total += count_coins(n-10, memo, penny, nickel, dime+1, quarter, 10);
		if (current_coin >= 25)
			total += count_coins(n-25, memo, penny, nickel, dime, quarter+1, 25);
		return total;
	}
}

int main()
{
	int value_in_cents = 10;
	std::vector<int> memo(100,-1);
	cout << count_coins(value_in_cents, memo, 0, 0, 0, 0, value_in_cents) << endl;

	return 0;
}

