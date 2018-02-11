// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering
// of vertices such that for every directed edge uv, vertex u comes before v
// in the ordering.
// Topological Sorting for a graph is not possible if the graph is not a DAG

// The first vertex in topological sorting is always a vertex with in-degree as 0
// (a vertex with no in-coming edges).

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
 
// Class to represent a graph
class Graph {

    // Pointer to an array containing adjacency listsList
    vector<vector<int> > myvec;

    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

    public:

        // function to add an edge to graph
        void addEdge(int v, int w);

        // prints a Topological Sort of the complete graph
        void topologicalSort();
};

void Graph::addEdge(int v, int w) {
    vector<int> tempVec;
    bool foundElement = false;
    for(int i = 0; i < myvec.size(); i++) {
        if(myvec[i][1] == v) {
            foundElement = true;
            tempVec = myvec[i];
            tempVec.push_back(w);
            myvec[i] = tempVec;
            break;
        }
    }

    if(!foundElement) {
        tempVec.push_back(v);
        tempVec.push_back(w);
        myvec.push_back(tempVec);
    }
    return;
}

// The function to do Topological Sort. It uses recursive
void Graph::topologicalSort() {
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool visited[myvec.size()];
    for(int i = 0; i < myvec.size(); i++) {
        visited[i] = false;
    }

    for(int i = 0; i < myvec.size(); i++) {
        for(int j = 0; j < myvec[i].size(); j++) {
            cout << myvec[i][j];
        }
        cout << endl;
    }

    return;
}

Graph construct_graph() {
    Graph g;
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    return g;
}

// Driver program to test above functions
int main() {

    // construct graph
    //        5   4        5 -> 2    5 -> 0     0 - 
    //       / \ / \       4 -> 1    4 -> 0     2 - 
    //      2       0      1         2 -> 3     3 - 
    //       \     /       3 -> 1               4 - 
    //        \   /                             5 - 
    //          3
    Graph g = construct_graph();
    cout << "Topological Sort : " << endl;
    g.topologicalSort();
    cout << endl;
    return 0;
}

