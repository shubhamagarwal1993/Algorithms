#include <iostream>
#include <list>

using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph {
    private:
        // No. of vertices
        int V;

        // Pointer to an array containing adjacency lists
        list<int> *adj;

        void printAllPathsUtil(int src, int dest, bool visited[], int path[], int path_index);

    public:
        // Constructor
        Graph(int V) {
            this->V = V;
            this->adj = new list<int>[V];
        }

        // function to add an edge to graph
        void addEdge(int v, int w) {
            // Add w to v’s list
            int adj_size = sizeof(this->adj)/sizeof(this->adj[0]);
            this->adj[v].push_back(w);
        }

        // prints BFS traversal from a given source s
        void BFS(int s);
        void anyPath(int s, int d);
        void allPaths(int s, int d);

        // construct graph
        //  ____   0 ---> 1
        //  \  /   ^\\   /
        //   ^v       v v
        //    3 <---- 2
        void construct_graph() {
            addEdge(0, 1);
            addEdge(0, 2);
            addEdge(0, 6);
            addEdge(1, 2);
            addEdge(1, 4);
            addEdge(2, 3);
            addEdge(2, 4);
            addEdge(3, 4);
            addEdge(4, 5);
            addEdge(5, 6);
        }
};

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

//void printVector(vector<int> path) {
//    int size = path.size();
//    for(int i = 0; i < path.size(); i++) {
//        cout << path[i] << " ";
//    }
//
//    cout << endl;
//}

void Graph::anyPath(int src, int dest) {

    // Mark all the vertices as not visited
    bool visited[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    list<int> queue;
    queue.push_back(src);

    // store path here
    list<int> path;

    // Mark the current node as visited and enqueue it
    visited[src] = true;

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty()) {
        int curr_node = queue.front();
        queue.pop_front();
        path.push_back(curr_node);

        if(curr_node == dest) {
            for(i = path.begin(); i != path.end(); i++) {
                cout << *i << " ";
            }
            cout << endl;
            return;
        }

        // Get all adjacent vertices of path_last_node
        // If a adjacent has not been visited, then mark it visited and enqueue it
        for(i = adj[curr_node].begin(); i != adj[curr_node].end(); i++) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::allPaths(int src, int dest) {

    // Mark all the vertices as not visited
    bool visited[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }
 
    // Create an array to store paths
    int path[V];
    int path_index = 0;
 
    // Call the recursive helper function to print all paths
    printAllPathsUtil(src, dest, visited, path, path_index);
}

void Graph::printAllPathsUtil(int src, int dest, bool visited[], int path[], int path_index) {

    // Mark the current node and store it in path
    visited[src] = true;
    path[path_index] = src;
    path_index++;

    // If current vertex is same as destination, then print current path
    if(src == dest) {
        for(int i = 0; i < path_index; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        // If current vertex is not destination, recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for(i = adj[src].begin(); i != adj[src].end(); i++) {
            if(!visited[*i]) {
                printAllPathsUtil(*i, dest, visited, path, path_index);
            }
        }
    }

    // Backtrack - Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[src] = false;
}

int main() {

    Graph g(10);
    g.construct_graph();

    // simple BFS, Time: O(V + E), Space: O(V^2)
    cout << "Simple BFS starting from 2: ";
    g.BFS(2);
    cout << endl << endl;

    // BFS - any path from source node to dest node, Time: O(V + E), Space: O(V^2)
    cout << "BFS all paths from 1 to 5: ";
    g.anyPath(1, 5);
    cout << endl << endl;

    // BFS all paths from source node to dest node, Time: O(V + E), Space: O(V^2)
    cout << "BFS all paths from 1 to 5: " << endl;
    g.allPaths(1, 5);
    cout << endl << endl;

    // BFS - iteratvely (does this even exist)
    // BFS - shortest path from source node to dest node
    // BFS - on matrix

    return 0;
}
