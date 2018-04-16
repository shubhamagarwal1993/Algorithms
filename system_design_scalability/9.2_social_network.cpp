// Design data structures for a very large social network
// Design an algorithm to show the shortest path between 2 people

// graph - each person is a node - edge between 2 nodes indicates friends
// To find path between 2 people - BFS or a bi-directional BFS
#include <iostream>

using namespace std;

class Person {
    string name;
};

// This class will represent the path as we are searching it storing each Person each previousNode we visited in the path
class PathNode {
    private:
        Person person;
        PathNode previousNode = null;
    public:
        PathNode(Person p, PathNode previous) {
            person = p;
            previousNode = previous;
        }
};

int main() {
    return 0;
}
