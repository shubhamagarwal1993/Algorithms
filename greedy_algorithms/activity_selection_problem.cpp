// Given n activites with start and finish times
// Select max number of activities that can be performed by a single person. Person can only work on a single activity at a time

// Example: Consider the following 3 activities sorted by finish time
//      start[]  =  {10, 12, 20};
//      finish[] =  {20, 25, 30};
//
// The maximum set of activities that can be executed is {0, 2} (indexes in start[] and finish[])

#include <iostream>
#include <unordered_map>

using namespace std;

void printMaxActivites(int start[], int finish[], int start_finish_size) {

    int latest_finish_time = -1;
    for(int i = 0; i < start_finish_size; i++) {
        if(start[i] > latest_finish_time) {
            cout << "INDEX - " << i << endl;
            // only update the latest finish time if the activity is actually picked up
            latest_finish_time = finish[i];
        }
    }
    cout << endl;

    return;
}

int main() {

    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int start_finish_size = sizeof(start)/sizeof(start[0]);

    printMaxActivites(start, finish, start_finish_size);

    return 0;
}
