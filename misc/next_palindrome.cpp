#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void next_palindrome(int num, int num_len)
{
	int next_num = 0;

	if (num_len % 2 == 0)			//if even len number, then copy have the numbers
	{
		for(int i = 0; i < num_len/2; i++)
		{

		}
	}
}

int main()
{
	int num;
	cin >> num;
	int temp = num;
	std::vector<int> vec;

	//make a vector of num
	while(temp > 0)
	{
		vec.push_back(temp%10);
		temp = temp/10;
	}
	temp = 0;

	std::reverse(vec.begin(), vec.end());

	//make a palindrome of this vector
	for(int i = 0; i < vec.size()/2; i++)
		vec[vec.size()-1-i] = vec[i];

//	for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
//		cout << *i << " ";

	for(int i = 0; i < vec.size(); i++)
	{
		temp = temp + vec[i];
		temp = temp*10;
	}
	temp = temp/10;

	//now checking if the new number is good enough
	if (temp > num)
		cout << "next number is: " << temp << endl;
	else
	{
		if (vec.size() % 2 == 1)
		{
			if (vec[vec.size()/2] != 9)
			{
				vec[vec.size()/2] = vec[vec.size()/2] + 1;

				temp = 0;
				for(int i = 0; i < vec.size(); i++)
				{
					temp = temp + vec[i];
					temp = temp*10;
				}
				temp = temp/10;				
			}
			else
			{
				//round up number if middle is 9 
			}
		}
		else
		{
			if(vec[vec.size()/2] != 9)
			{
				vec[vec.size()/2] = vec[vec.size()/2] + 1;
				vec[(vec.size()/2)-1] = vec[(vec.size()/2)-1] + 1;
				temp = 0;
				for(int i = 0; i < vec.size(); i++)
				{
					temp = temp + vec[i];
					temp = temp*10;
				}
				temp = temp/10;
			}
			else
			{
				//round up number if middle is 9
			}
		}
		cout << "next number is: " << temp << endl;
	}

	return 0;
}
