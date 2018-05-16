#include <iostream>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool jobCompare(Job a, Job b) {
    return a.profit > b.profit;
}

class DisjointSet {

    private:
        int* parent;
    public:
        DisjointSet(int job_array_size);
        int find(int node);
        void merge(int prevAvailableSlot, int availableSlot);
};

DisjointSet::DisjointSet(int job_array_size) {
    this->parent = new int[job_array_size + 1];

    for(int i = 0; i <= job_array_size; i++) {
        parent[i] = i;
    }
}

int DisjointSet::find(int node) {
    if(node == parent[node]) {
        return node;
    }
    return find(parent[node]);
}

void DisjointSet::merge(int prevAvailableSlot, int availableSlot) {
    parent[availableSlot] = prevAvailableSlot;
}

int findMaxDeadline(Job job_array[], int job_array_size) {
    int max = INT_MIN;
    for(int i = 0; i < job_array_size; i++) {
        if(job_array[i].deadline > max) {
            max = job_array[i].deadline;
        }
    }
    return max;
}

// Sort all jobs in decreasing order of profit
// If current job can fit in the current result sequence without missing deadline, add job to result
void printJobSchedulingDisjointSet(Job job_array[], int job_array_size) {

    sort(job_array, job_array + job_array_size, jobCompare);

    int max_deadline = findMaxDeadline(job_array, job_array_size);
    DisjointSet ds(job_array_size);

    // traverse through all the jobs
    for(int i = 0; i < job_array_size; i++) {

        // find max available time slot for this slot, corresponding to its deadline
        int availableSlot = ds.find(job_array[i].deadline);

        if(availableSlot > 0) {
            ds.merge(ds.find(availableSlot - 1), availableSlot);

            cout << (char)job_array[i].id << " ";
        }
    }
    cout << endl;

    return;
}

// Sort all jobs in decreasing order of profit
// If current job can fit in the current result sequence without missing deadline, add job to result
void printJobSchedulingNaive(Job job_array[], int job_array_size) {

    sort(job_array, job_array + job_array_size, jobCompare);

    // To store sequence of jobs
    int result[job_array_size];

    // To keep track of free time slots
    bool slot[job_array_size];
    for(int i = 0; i < job_array_size; i++) {
        slot[i] = false;
    }

    // Iterate through all jobs
    for(int i = 0; i < job_array_size; i++) {

        // find a free slot from the end
        for(int j = min(job_array_size, job_array[i].deadline) - 1; j >= 0; j--) {
            if(slot[j] == false) {
                slot[j] = true;
                result[j] = i;
                break;
            }
        }
    }

    for(int i = 0; i < job_array_size; i++) {
        if(slot[i]) {
            cout << (char)job_array[result[i]].id << " ";
        }
    }
    cout << endl;

    return;
}

int main() {

    Job job_array[] = { {'a', 2, 100}
                      , {'b', 1, 19}
                      , {'c', 2, 27}
                      , {'d', 1, 25}
                      , {'e', 3, 15}
                      };
    int job_array_size = sizeof(job_array)/sizeof(job_array[0]);

    // Time Complexity: O(n^2)
    printJobSchedulingNaive(job_array, job_array_size);

    // Time Complexity: O(n^2)
    printJobSchedulingDisjointSet(job_array, job_array_size);

    return 0;
}
