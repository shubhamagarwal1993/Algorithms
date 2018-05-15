// Given n activites with start and finish times
// Select max number of activities that can be performed by a single person. Person can only work on a single activity at a time

// Example: Consider the following 3 activities sorted by finish time
//      start[]  =  {10, 12, 20};
//      finish[] =  {20, 25, 30};
//
// The maximum set of activities that can be executed is {0, 2} (indexes in start[] and finish[])

#include <iostream>

using namespace std;

struct Activity {
    int start;
    int finish;
};

bool activityCompare(Activity a, Activity b) {
    return a.finish < b.finish;
}

// Takes array sorted by finish time and applied simple greedy algo
void printMaxActivitesSorted(int start[], int finish[], int start_finish_size) {

    cout << "INDEX - ";
    int latest_finish_time = -1;
    for(int i = 0; i < start_finish_size; i++) {
        if(start[i] > latest_finish_time) {
            cout << i << " ";
            // only update the latest finish time if the activity is actually picked up
            latest_finish_time = finish[i];
        }
    }
    cout << endl;

    return;
}

// Takes array unsorted, sorts it by finish time and applied simple greedy algo
bool printMaxActivitesUnsorted(Activity activity_array[], int activity_array_size) {

    // sort by finish time
    sort(activity_array, activity_array + activity_array_size, activityCompare);

    cout << "INDEX - ";
    int latest_finish_time = -1;
    for(int i = 0; i < activity_array_size; i++) {
        if(activity_array[i].start > latest_finish_time) {
            cout << "(" << activity_array[i].start << ", " << activity_array[i].finish << "), ";
            // only update the latest finish time if the activity is actually picked up
            latest_finish_time = activity_array[i].finish;
        }
    }
    cout << endl;

    return true;
}

int main() {

    // Sorted by finish time
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int start_finish_size = sizeof(start)/sizeof(start[0]);

    // unsorted - we will have to sort to apply the same algorithm
    Activity activity_array[] = { {5, 9}
                                , {1, 2}
                                , {3, 4}
                                , {0, 6}
                                , {5, 7}
                                , {8, 9}
                                };
    int activity_array_size = sizeof(activity_array)/sizeof(activity_array[0]);

    printMaxActivitesSorted(start, finish, start_finish_size);
    printMaxActivitesUnsorted(activity_array, activity_array_size);

    return 0;
}
