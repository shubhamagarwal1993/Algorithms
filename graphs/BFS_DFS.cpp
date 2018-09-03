#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Node {
    private:
        int data;
        bool visited;

    public:
        Node(int data) {
            this->data = data;
            this->visited = false;
        }
};

// This class represents a directed graph using adjacency list representation
class Graph {
    private:
        // No. of vertices
        int V;

        // Pointer to an array containing adjacency lists
        list<int> *adj;

        // A function used by DFS
        void DFSUtil(int v, bool visited[]);
        void DFSUtil_trial(int v, bool visited[], vector<int> &vec);

    public:
        // Constructor
        Graph(int V) {
            this->V = V;
            this->adj = new list<int>[V];
        }

        // function to add an edge to graph
        void addEdge(int v, int w) {
            // Add w to v’s list
            adj[v].push_back(w);
        }

        // prints DFS traversal of the complete graph
        void DFS();
        void DFS_trial(vector<int> &vec);

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
};

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
    for(int i = 0; i < V; i++) {
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

void Graph::DFSUtil_trial(int v, bool visited[], vector<int> &vec) {
    // Mark the current node as visited and print it
    visited[v] = true;
    vec.push_back(v);

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i) {
        if(!visited[*i]) {
            DFSUtil_trial(*i, visited, vec);
        }
    }
}

void Graph::DFS_trial(vector<int> &vec) {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            DFSUtil_trial(i, visited, vec);
        }
    }
}

bool validMatrix(int matrix[2][4], int row, int col, int row_end, int col_end, vector<int> &vec) {
    if( (row >= 0) 
     && (row <= row_end)
     && (col >= 0)
     && (col <= col_end)
     && (!(std::find(vec.begin(), vec.end(), matrix[row][col]) != vec.end()))
    ) {
        return true;
    }
    return false;
}

bool dfsMatrix(int matrix[2][4], int row, int col, int row_end, int col_end, vector<int> &vec) {

    if(vec.size() == 7) {

        if(validMatrix(matrix, row+1, col, row_end, col_end, vec)) {
            vec.push_back(matrix[row+1][col]);
        } else if(validMatrix(matrix, row, col+1, row_end, col_end, vec)) {
            vec.push_back(matrix[row][col+1]);
        } else if(validMatrix(matrix, row-1, col, row_end, col_end, vec)) {
            vec.push_back(matrix[row-1][col]);
        } else if(validMatrix(matrix, row, col-1, row_end, col_end, vec)) {
            vec.push_back(matrix[row][col-1]);
        }
    }

    if(vec.size() == 8) {
        return true;
    }

    if(validMatrix(matrix, row, col, row_end, col_end, vec)) {

        vec.push_back(matrix[row][col]);

        if( (dfsMatrix(matrix, row+1, col, row_end, col_end, vec)) 
         || (dfsMatrix(matrix, row, col+1, row_end, col_end, vec)) 
         || (dfsMatrix(matrix, row-1, col, row_end, col_end, vec)) 
         || (dfsMatrix(matrix, row, col-1, row_end, col_end, vec)) 
        ) {
            return true;
        } else {
            vec.pop_back();
            return false;
        }
    }
    return false;
}

int main() {
    // construct graph
    //   ___   0 - 1
    //   \ /    \ /
    //    3 ---- 2

    Graph g(4);
    g.construct_graph();

    // Time: O(V + E), Space: O(V^2)
    cout << "Depth First Traversal: ";
    g.DFS();
    cout << endl;


    cout << endl << endl << "Trial DFS: ";
    vector<int> vec;
    g.DFS_trial(vec);
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl << endl;

    int matrix[2][4] = {{1, 2, 3, 4}
                       ,{5, 6, 7, 8}
                       };

    vector<int> vec1;
    dfsMatrix(matrix, 0, 0, 1, 3, vec1);
    for(int i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl << endl;

    return 0;
}
