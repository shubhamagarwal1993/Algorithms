// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering
// of vertices such that for every directed edge uv, vertex u comes before v
// in the ordering.
// Topological Sorting for a graph is not possible if the graph is not a DAG

// The first vertex in topological sorting is always a vertex with in-degree as 0
// (a vertex with no in-coming edges).

#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;
 
// Class to represent a graph
class Graph {
    // No. of vertices
    int V;

    // Pointer to an array containing adjacency listsList
    list<int> *adj;

    // Vector to store indegree of vertices
    vector<int> indegree;

    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

    // A function used by topologicalSort
    void allTopologicalSortsHelper(vector<int> &res, bool visited[]);

    public:
        // Constructor
        Graph(int V);

        // function to add an edge to graph
        void addEdge(int v, int w);

        // prints a Topological Sort of the complete graph
        void topologicalSort();

        // prints all Topological Sorts of the complete graph
        void allTopologicalSorts();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];

    // initialize all indegree to 0
    for(int i = 0; i < V; i++) {
        indegree.push_back(0);
    }
}

void Graph::addEdge(int v, int w) {
    // Add w to v’s list
    adj[v].push_back(w);

    indegree[w]++;
}

// Helper function for TopologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) {
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            topologicalSortUtil(*i, visited, Stack);
        }
    }

    // Push current vertex to stack which stores result
    Stack.push(v);
}

// Topological Sort using recursion
void Graph::topologicalSort() {
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

// Helper function for allTopologicalSorts
void Graph::allTopologicalSortsHelper(vector<int> &res, bool visited[]) {

    // check if we found a topological sort
    bool flag = false;

    // Recur for all the vertices
    for(int i = 0; i < V; i++) {

        // find last element of topological sort - all incoming edges
        if((indegree[i] == 0) && !visited[i]) {
            
            // include this in result
            res.push_back(i);
            visited[i] = true;

            // reduce indegree of all adjacent vertices
            // When they reach 0, they can be caught in this condition
            list<int>::iterator j;
            for(j = adj[i].begin(); j != adj[i].end(); j++) {
                indegree[*j]--;
            }

            // process remaining vertices
            allTopologicalSortsHelper(res, visited);

            // Backtrack for other possible solutions
            // resetting visited, res, and indegree
            visited[i] = false;
            res.erase(res.end() - 1);
            for(j = adj[i].begin(); j != adj[i].end(); j++) {
                indegree[*j]++;
            }

            // found a topological sort
            flag = true;
        }
    }

    // print all topological sorts
    if(!flag) {
        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}

// All Topological Sorts using recursion and backtracking
void Graph::allTopologicalSorts() {

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    vector<int> res;

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    allTopologicalSortsHelper(res, visited);
}

Graph construct_graph() {
    Graph g(6);
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
    //        5   4        5 -> 2    5 -> 0
    //       / \ / \       4 -> 1    4 -> 0
    //      2       0      1         2 -> 3
    //       \     /       3 -> 1
    //        \   /
    //          3
    Graph g = construct_graph();

    // Any 1 possible topological sort
    cout << "Any possible Topological Sort : ";
    g.topologicalSort();
    cout << endl << endl;

    // All possible topological sort
    cout << "All possible Topological Sorts : " << endl;
    g.allTopologicalSorts();
    cout << endl;

    return 0;
}

