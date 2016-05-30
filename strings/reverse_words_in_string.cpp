#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

void reverse(string &str, int left, int right)
{
	char temp;

	if (str.length() == 0)
		return;

	for (int i = 0; i < (right+1-left)/2; i++)
	{
		temp = str[left+i];
		str[left+i] = 	str[right-i];
		str[right-i] = temp;
	}
	return;
}

void reverse_words(string &str)
{
	int l = 0, r = 0;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == ' ')
		{
			r = i-1;
			reverse(str, l, r);
			l = i+1;
		}
		else if (i == str.length()-1)
		{
			r = i;
			reverse(str, l, r);
		}
	}
	return;
}

int main()
{
	string str = "abc dfg erwe";
	reverse(str, 0, str.length()-1);
	cout << str << endl;
	reverse_words(str);
	cout << str << endl;
	return 0;
}

