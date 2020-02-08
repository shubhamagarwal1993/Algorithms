#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void buildMaxHeap() {
    priority_queue<int> pq;
    pq.push(5); pq.push(1); pq.push(10); pq.push(30); pq.push(20);

    // One by one extract items from max heap
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void buildMinHeap() {
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(5); pq.push(1); pq.push(10); pq.push(30); pq.push(20);

    // One by one extract items from max heap
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

class Point {
    public:
        int x;
        int y;
    
        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
};

class pointComparator {
    public:
        int operator() (const Point& p1, const Point& p2) {
            return p1.x > p2.x;
        }
};

void buildMinHeapOfGraphPoints() {
    priority_queue<Point, vector<Point>, pointComparator > pq;
    pq.push(Point(10, 2));
    pq.push(Point(2, 1));
    pq.push(Point(1,5));

    while(!pq.empty()) {
        Point p = pq.top();
        cout << "(" << p.x << ", " << p.y << ") ";
        pq.pop();
    }
    cout << endl;

    return;
}

void buildMaxHeapFromVector() {

    vector<int> vec;
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(25);
    vec.push_back(15);

    // Converting vector into a heap using make_heap()
    make_heap(vec.begin(), vec.end());

    cout << "The maximum element of heap is : ";
    cout << vec.front() << endl;

    return;   
}

void sortHeap() {

    vector<int> vec;
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(25);
    vec.push_back(15);

    vector<int>::iterator it1;

    // Converting vector into a heap using make_heap()
    make_heap(vec.begin(), vec.end());

    cout << "The heap elements are: ";
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    // check if heap
    //if(is_heap(vec.begin(), vec.end())) ? cout << "Is a heap" : cout << "Is not a heap";
    if(is_heap(vec.begin(), vec.end())) {
        cout << "Is a heap";
    } else {
        cout << "Is not a heap, but heap until: ";
        auto it = is_heap_until(vec.begin(), vec.end());
        for(it1 = vec.begin(); it1 != it; it1++) {
            cout << *it1 << " ";
        }
    }
    cout << "  =>  ";

    // sort the heap
    sort_heap(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    if(is_heap(vec.begin(), vec.end())) {
        cout << "Is a heap";
    } else {
        cout << "Is not a heap, but heap until: ";
        auto it = is_heap_until(vec.begin(), vec.end());
        for(it1 = vec.begin(); it1 != it; it1++) {
            cout << *it1 << " ";
        }
    }

    cout << endl;
    return;   
}

int main() {

    buildMaxHeap();
    buildMinHeap();
    buildMinHeapOfGraphPoints();
    buildMaxHeapFromVector();

    // This function is used to sort the heap. After this operation, the container is no longer a heap
    sortHeap();
 
    return 0;
}

