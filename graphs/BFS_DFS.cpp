#include <iostream>
#include <list>

using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph {
    // No. of vertices
    int V;
    // Pointer to an array containing adjacency lists
    list<int> *adj;
    // A function used by DFS
    void DFSUtil(int v, bool visited[]);

    public:
        // Constructor
        Graph(int V);

        // function to add an edge to graph
        void addEdge(int v, int w);

        // prints BFS traversal from a given source s
        void BFS(int s);

        // prints DFS traversal of the complete graph
        void DFS();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    // Add w to v’s list
    adj[v].push_back(w);
}

Graph construct_graph() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    return g;
}

void Graph::BFS(int s) {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFSUtil(int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i) {
        if(!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
}

// The function to do DFS traversal. It uses recursive DFSUtil()
void Graph::DFS() {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            DFSUtil(i, visited);
        }
    }
}

int main() {
    // construct graph
    //   ___   0 - 1
    //   \ /    \ /
    //    3 ---- 2

    Graph g = construct_graph();

    cout << "Breadth First Traversal" << "(starting from vertex 2): ";
    g.BFS(2);
    cout << endl;
    cout << "Depth First Traversal: ";
    g.DFS();
    cout << endl;
    return 0;
}
