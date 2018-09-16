#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class Graph {
    private:
        // no. of vertices
        int V;

        // adjacency list
        list<int> *adj;

        // indegree - how many nodes are pointing to current node
        vector<int> indegree;

        // helper functions
        void topologicalSortUtil(int vertex, bool* visited, stack<int> &s);
        void allTopologicalSortsUtil(bool* visited, vector<int> &vec);

    public:
        Graph(int V);

        // add edge
        void addEdge(int v, int w);

        // get any topological sort for the graph
        void topologicalSort();

        // get all topological sorts for the graph
        void allTopologicalSorts();
};

Graph::Graph(int V) {
    this->V = V;
    this->adj = new list<int>[V];

    for(int i = 0; i < V; i++) {
        indegree.push_back(0);
    }
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);

    // v points to w, so w has a new indegree
    indegree[w]++;
}

Graph constructGraph() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    return g;
}

void Graph::topologicalSortUtil(int vertex, bool* visited, stack<int> &s) {

    visited[vertex] = true;

    list<int>::iterator i;
    for(i = adj[vertex].begin(); i != adj[vertex].end(); i++) {
        if(visited[*i] != true) {
            topologicalSortUtil(*i, visited, s);
        }
    }

    // recursion breaks here and last element in topological sort will be the first one here
    // Stock this in stack so that the latest / first element in sort is on top
    s.push(vertex);
    return;
}

void Graph::topologicalSort() {

    // Will store topological sort to print later
    stack<int> s;

    bool visited[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

    for(int i = 0; i < V; i++) {
        if(visited[i] == false) {
            topologicalSortUtil(i, visited, s);
        }
    }

    cout << "Any Topological Sort: ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return;
}

void Graph::allTopologicalSortsUtil(bool* visited, vector<int> &vec) {

    // loop over all vertices and check for vertex with no indegree - first node to start with
    for(int i = 0; i < V; i++) {

        if(indegree[i] == 0 && visited[i] == false) {

            // put current vertex as potential soln
            vec.push_back(i);
            visited[i] = true;

            // reduce the indegree of vertex around it 
            // This would be like getting rid of current vertex, so vectices with 0 indegree can be picked up in the next round
            list<int>::iterator j;
            for(j = adj[i].begin(); j != adj[i].end(); j++) {
                indegree[*j]--;
            }

            // check for remaining vertices
            allTopologicalSortsUtil(visited, vec);

            // Backtrack to check for other possible topological sorts
            // reset visited, remove element, and increate indegree
            visited[i] = false;
            //vec.pop_back();
            vec.erase(vec.end() - 1);
            for(j = adj[i].begin(); j != adj[i].end(); j++) {
                indegree[*j]++;
            }
        }
    }

    // if sort was found then print it
    if(vec.size() == V) {
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return;
}

void Graph::allTopologicalSorts() {

    // vector to hold all the sorts
    vector<int> res;

    bool visited[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

    allTopologicalSortsUtil(visited, res);
}

int main() {
    // construct graph
    //        5   4        5 -> 2    5 -> 0
    //       / \ / \       4 -> 1    4 -> 0
    //      2   0   1      2 -> 3
    //       \     /       3 -> 1
    //        \   /
    //          3

    Graph g = constructGraph();;
    g.topologicalSort();
    g.allTopologicalSorts();
    return 0;
}
