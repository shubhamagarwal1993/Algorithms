// We will get the median of a running stream of integers
// For total of odd numbers - return the middle position integer
// For total of even numbers - return the avg of the 2 middle position integers
//
// We will solve by maintaining a max heap for the left side of the integers of the median, and a min heap for the right side

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <signal.h>

using namespace std;

// max heap will always have equal or 1 more than min heap
// max heap will have lower numbers
// min heap will have upper numbers
int get_median(priority_queue<int> max_heap, priority_queue<int, vector<int>, std::greater<int> > min_heap) {
    if(max_heap.size() == min_heap.size() + 1)
        return max_heap.top();
    else if (max_heap.size() == min_heap.size())
        return ((max_heap.top() + min_heap.top())/2);
    else {
        cout << "error in heaps" << endl;
        return -1;
    }
}

void insert(priority_queue<int> &max_heap, priority_queue<int, vector<int>, std::greater<int> > &min_heap, int temp) {

    // If max_heap > min_heap then insert new element in min_heap
    if(max_heap.size() == min_heap.size() + 1) {
        cout << "insert into min_heap" << endl;
        if(temp < max_heap.top()) {
            max_heap.push(temp);            // max_heap has 2 more elements than min_heap
            temp = max_heap.top();          // get the highest value in max heap
            max_heap.pop();                 // temp has lowerest value for min_heap and max_heap is 1 more in size
            min_heap.push(temp);            // max_heap and min_heap have same size now with corrent ordering of elements
        } else {
            min_heap.push(temp);
        }
    } else if(max_heap.size() == min_heap.size()) {
        if(max_heap.empty()) {
            max_heap.push(temp);
        } else if(min_heap.empty()) {
            // we have to insert here after checking with max heap
            if(temp < max_heap.top()) {
                max_heap.push(temp);        // max heap has 2 more elements than min heap
                temp = max_heap.top();      // we get the highest value in max heap
                max_heap.pop();             // temp has lowerest value for min heap and max heap is 1 more in size
                min_heap.push(temp);        // max and min heap have same size
            } else {
                min_heap.push(temp);
            }
        } else if(temp > min_heap.top()) {  // since same size, max heap will get element {
            min_heap.push(temp);
            temp = min_heap.top();
            min_heap.pop();
            max_heap.push(temp);            // max heap has one extra element now
        } else {
            max_heap.push(temp);
        }
    } else {
        cout << "error in heaps" << endl;
    }

    if(!min_heap.empty()) {
        cout << "size " << min_heap.size() << " min " << min_heap.top() << endl;
    } else {
        cout << "min size " << min_heap.size() << endl;
    }

    cout << "max size " << max_heap.size() << " max " << max_heap.top() << endl;
    cout << "median " << get_median(max_heap, min_heap) << endl;
}

void my_handler(int s) {
    cout << endl << "Caught signal " << s << endl;
    cout << "Closing program...Bye!" << endl;
    exit(1);
}

int main() {

    // handle keyboard interrupt
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);

    int input;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, std::greater<int> > min_heap;

    while(1) {
        cin >> input;
        insert(max_heap, min_heap, input);
    }

    return 0;
}

