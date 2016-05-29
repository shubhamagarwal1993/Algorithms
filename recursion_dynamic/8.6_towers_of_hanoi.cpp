#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

//using recursion
void towers_of_hanoi(int num_of_disks, string origin, string buffer, string destination)
{
	//base case
	if (num_of_disks == 1)
	{
		cout << "move disk " << num_of_disks << " from " << origin << " to  " << destination << endl;
		return;
	}

	towers_of_hanoi(num_of_disks-1, origin, destination, buffer);
	cout << "move disk " << num_of_disks << " from " << origin << " to  " << destination << endl;
	towers_of_hanoi(num_of_disks-1, buffer, origin, destination);
}

/*
void initialize_origin(stack <int> &origin, int num_of_disks)
{
	for(int i = num_of_disks; i > 0; i--)
		origin.push(i);
	return;
}

void movedisk(stack <int> origin, stack <int> destination)
{
	destination.push(origin.top());
	origin.pop();
	return;
}

void towers_of_hanoi(int num_of_disks, stack <int> origin, stack <int> buffer, stack <int> destination)
{
	//base case
	if (num_of_disks == 1)
	{
		movedisk(origin, destination);
		cout << origin.top() << " " << buffer.top() << " " << destination.top() << endl;
		return;
	}

	towers_of_hanoi(num_of_disks-1, origin, destination, buffer);
	movedisk(origin, destination);
	cout << origin.top() << " " << buffer.top() << " " << destination.top() << endl;
	towers_of_hanoi(num_of_disks-1, buffer, origin, destination);
}
*/
int main()
{

	//using recursion
	int num_of_disks = 4;
	towers_of_hanoi(num_of_disks, "origin", "buffer", "destination");

/*
	//using stacks
	int num_of_disks = 4;	
	stack <int> origin;
	stack <int> buffer;
	stack <int> destination;

	initialize_origin(origin, num_of_disks);
	towers_of_hanoi(num_of_disks, origin, buffer, destination);
*/
	return 0;
}