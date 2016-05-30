#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

//max heap will always have equal or 1 more than min heap
//max heap will have lower numbers
//min heap will have upper numbers

int get_median(priority_queue<int> max_heap, priority_queue<int, vector<int>, std::greater<int> > min_heap)
{
	if(max_heap.size() == min_heap.size() + 1)
		return max_heap.top();
	else if (max_heap.size() == min_heap.size())
		return ((max_heap.top() + min_heap.top())/2);
	else
	{
		cout << "error in heaps" << endl;
		return -1;
	}
}

void insert(priority_queue<int> &max_heap, priority_queue<int, vector<int>, std::greater<int> > &min_heap, int temp)
{
	if (max_heap.size() == min_heap.size() + 1)
	{
		cout << "second" << endl;
		if(temp < max_heap.top())
		{
			max_heap.push(temp);				//max heap has 2 more elements than min heap
			temp = max_heap.top();				//we get the highest value in max heap
			max_heap.pop();						//temp has lowerest value for min heap and max heap is 1 more in size
			min_heap.push(temp);				//max and min heap have same size
		}
		else
			min_heap.push(temp);
	}
	else if (max_heap.size() == min_heap.size())
	{
		if (max_heap.empty())
		{
			max_heap.push(temp);
		}
		else if (min_heap.empty())
		{
			//we have to insert here after checking with max heap
			if(temp < max_heap.top())
			{
				max_heap.push(temp);				//max heap has 2 more elements than min heap
				temp = max_heap.top();				//we get the highest value in max heap
				max_heap.pop();						//temp has lowerest value for min heap and max heap is 1 more in size
				min_heap.push(temp);				//max and min heap have same size
			}
			else
				min_heap.push(temp);
		}
		else if(temp > min_heap.top())				//since same size, max heap will get element
		{
			min_heap.push(temp);
			temp = min_heap.top();
			min_heap.pop();
			max_heap.push(temp);				//max heap has one extra element now
		}
		else
			max_heap.push(temp);
	}
	else
		cout << "error in heaps" << endl;

	if (!min_heap.empty())
		cout << "size " << min_heap.size() << " min " << min_heap.top() << endl;
	else
		cout << "min size " << min_heap.size() << endl;
	cout << "max size " << max_heap.size() << " max " << max_heap.top() << endl;
	cout << "median " << get_median(max_heap, min_heap) << endl;
}

int main()
{
	int temp;
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, std::greater<int> > min_heap;

	while(1)
	{
		cin >> temp;
		insert(max_heap, min_heap, temp);
	}

	return 0;
}
