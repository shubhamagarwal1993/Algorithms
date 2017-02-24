#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <typeinfo>
using namespace std;

double newton_sq_root(double y)
{
	double x1;
	double x0;

	x0 = log(y);

	x1 = (x0 - (((x0 * x0) - y)/(2* x0)));
	x0 = x1;

	while((x1 * x1) > y)
	{
		x1 = (x0 - (((x0 * x0) - y)/(2* x0)));
		x0 = x1;	
	}

	return x1;
}

int binary_search_floor_sq_root(int(num))
{
	if (num == 0 || num == 1)
		return num;
	
	int ans = 0;
	int start = 0;
	int end = num;

	while (start <= end)
	{
		int mid = (start+end)/2;
		
		if (mid*mid == num)
			return mid;
		
		if (mid*mid < num)
		{
			start = mid + 1;
			// if we need floor, we will store ans here
			ans = mid;
		}
		else
			// if we need ceiling, we will store and here
			end = mid - 1;
	}
	return ans;
}

double sqrt_double(double num)
{
	if (num < 0)
		return -1;

	if (num == 0 || num == 1)
		return num;

	//now start the core part of the code
	double precision = 0.00001;					//define the precision, so we stop when precision is achieved
	double start = 0;
	double end = num;

	//if num between 0 and 1
	if (num < 1)
		end = 1;

	//define a loop to continue if the precision is not yet achieved
	while((end - start) > precision)
	{
		double mid = (start+end)/2;
		double midSqr = mid*mid;
		if (midSqr == num)
			return mid;							//we find the exact sqrt value!
		else if (midSqr < num)
			start = mid;						//we shift our focus to bigger half
		else
			end = mid;							//shift focus to smaller half
	}

	//if we did not find exact sqrt value, we return the approxiated value with the defined precision
	return (start+end)/2;
}

int main()
{
	double y;
	cout << "Enter a value to be square rooted: " << endl;
	cin >> y;

	//cout << newton_sq_root(y) << endl;
	cout << binary_search_floor_sq_root(int(y)) << endl;
	//cout << sqrt_double(y) << endl;
	return 0;
}

