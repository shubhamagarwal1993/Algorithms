#include <iostream>
#include <list>
#include <vector>

using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph {
    private:
        // No. of vertices
        int V;

        // Pointer to an array containing adjacency lists
        list<int> *adj;

        // A function used by DFS
        void DFSUtil(int v, int visited[], vector<int> &vec, int s, int d);

    public:
        // Constructor
        Graph(int V);

        // function to add an edge to graph
        void addEdge(int v, int w);

        // prints DFS traversal of the complete graph
        void DFS();
};

Graph::Graph(int V) {
    this->V = V;
    this->adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    // Add w to v’s list
    adj[v].push_back(w);
    adj[w].push_back(v);
}

Graph construct_graph() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(0, 2);
    return g;
}

void Graph::DFSUtil(int v, int visited[], vector<int> &paths, int s, int d) {

    // Increase visited count of current node and add it to path
    visited[v]++;
    paths.push_back(v);

    if((v == d) && (visited[s] == 2) && (paths.size() > 1)){
        cout << "Path: ";
        for(int i = 0; i < paths.size(); i++) {
            cout << paths[i] << " ";
        }
        cout << endl;

    } else {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i) {
            if(visited[*i] < 2) {
                DFSUtil(*i, visited, paths, s, d);
            }
        }
    }

    if(paths.size() > 1) {
        visited[v]--;
        paths.pop_back();
    }
}

// The function to do DFS traversal. It uses recursive DFSUtil()
void Graph::DFS() {
    // Mark all the vertices as not visited
    int *visited = new int[V];
    for(int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // store potential path here till destination is reached
    vector<int> paths;

    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    for (int i = 0; i < V; i++) {
        if (visited[i] < 2) {
            DFSUtil(i, visited, paths, 0, 0);
        }
    }
}

int main() {
    // construct graph
    // 0 ----- 1
    // |       |
    // |       |
    // 2       3

    Graph g = construct_graph();

    // Time: O(V + E), Space: O(V^2)
    g.DFS();
    cout << endl;

    return 0;
}

