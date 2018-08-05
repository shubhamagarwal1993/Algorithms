#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Node {
    private:
    public:
        int data;
        bool visited;
        vector<Node*> adj;

        Node(int data) {
            this->data = data;
            this->visited = false;
            this->adj.clear();
        }
};

// This class represents a directed graph using adjacency list representation
class Graph {
    private:
        vector<Node> graphNodes;

        // A function used by DFS
//        void DFSUtil(int v, bool visited[]);
//        void DFSUtil_trial(int v, bool visited[], vector<int> &vec);

    public:
        // Constructor
        Graph();

        // contains all nodes
        void addNode(Node newNode) {

            for(int i = 0; i < graphNodes.size(); i++) {
                if(graphNodes[i].data == newNode.data) {
                    return;
                }
            }

            this->graphNodes.push_back(newNode);

            return;
        }

        // function to add an edge to graph
        void addEdge(Node origin, Node dest) {

            bool originExists = false;
            int originIndex = -1;
            bool destExists = false;

            for(int i = 0; i < graphNodes.size(); i++) {
                if(graphNodes[i].data == origin.data) {
                    originExists = true;
                    originIndex = i;
                }
                if(graphNodes[i].data == dest.data) {
                    destExists = true;
                }
            }

            if(!originExists || !destExists) {
                return;
            }

            graphNodes[originIndex].adj.push_back(&dest);
        }

        void construct_graph() {
           this->addNode(Node(0));
           this->addNode(Node(1));
           this->addNode(Node(2));
           this->addNode(Node(3));

           this->addEdge(Node(0), Node(1));
           this->addEdge(Node(1), Node(0));

           this->addEdge(Node(0), Node(2));
           this->addEdge(Node(2), Node(0));

           this->addEdge(Node(1), Node(2));
           this->addEdge(Node(2), Node(1));

           this->addEdge(Node(2), Node(3));
           this->addEdge(Node(3), Node(2));

           this->addEdge(Node(3), Node(3));
        }

        void printAllNodes() {
            for(int i = 0; i < this->graphNodes.size(); i++) {
                cout << this->graphNodes[i].data << endl;
            }
        }
//        // prints BFS traversal from a given source s
//        void BFS(int s);
//
//        // prints DFS traversal of the complete graph
//        void DFS();
//        void DFS_trial(vector<int> &vec);
//
};

//void Graph::BFS(int s) {
//    // Mark all the vertices as not visited
//    bool *visited = new bool[V];
//    for(int i = 0; i < V; i++) {
//        visited[i] = false;
//    }
//
//    // Create a queue for BFS
//    list<int> queue;
//
//    // Mark the current node as visited and enqueue it
//    visited[s] = true;
//    queue.push_back(s);
//
//    // 'i' will be used to get all adjacent vertices of a vertex
//    list<int>::iterator i;
//
//    while(!queue.empty()) {
//        // Dequeue a vertex from queue and print it
//        s = queue.front();
//        cout << s << " ";
//        queue.pop_front();
//
//        // Get all adjacent vertices of the dequeued vertex s
//        // If a adjacent has not been visited, then mark it visited
//        // and enqueue it
//        for(i = adj[s].begin(); i != adj[s].end(); ++i) {
//            if(!visited[*i]) {
//                visited[*i] = true;
//                queue.push_back(*i);
//            }
//        }
//    }
//}
//
//void Graph::DFSUtil(int v, bool visited[]) {
//    // Mark the current node as visited and print it
//    visited[v] = true;
//    cout << v << " ";
//
//    // Recur for all the vertices adjacent to this vertex
//    list<int>::iterator i;
//    for(i = adj[v].begin(); i != adj[v].end(); ++i) {
//        if(!visited[*i]) {
//            DFSUtil(*i, visited);
//        }
//    }
//}
//
//// The function to do DFS traversal. It uses recursive DFSUtil()
//void Graph::DFS() {
//    // Mark all the vertices as not visited
//    bool *visited = new bool[V];
//    for(int i = 0; i < V; i++) {
//        visited[i] = false;
//    }
//
//    // Call the recursive helper function to print DFS traversal
//    // starting from all vertices one by one
//    for (int i = 0; i < V; i++) {
//        if (visited[i] == false) {
//            DFSUtil(i, visited);
//        }
//    }
//}
//
//void Graph::DFSUtil_trial(int v, bool visited[], vector<int> &vec) {
//    // Mark the current node as visited and print it
//    visited[v] = true;
//    vec.push_back(v);
//
//    // Recur for all the vertices adjacent to this vertex
//    list<int>::iterator i;
//    for(i = adj[v].begin(); i != adj[v].end(); ++i) {
//        if(!visited[*i]) {
//            DFSUtil_trial(*i, visited, vec);
//        }
//    }
//}
//
//void Graph::DFS_trial(vector<int> &vec) {
//    // Mark all the vertices as not visited
//    bool *visited = new bool[V];
//    for(int i = 0; i < V; i++) {
//        visited[i] = false;
//    }
//
//    // Call the recursive helper function to print DFS traversal
//    // starting from all vertices one by one
//    for (int i = 0; i < V; i++) {
//        if (visited[i] == false) {
//            DFSUtil_trial(i, visited, vec);
//        }
//    }
//}
//
//bool validMatrix(int matrix[2][4], int row, int col, int row_end, int col_end, vector<int> &vec) {
//    if( (row >= 0) 
//     && (row <= row_end)
//     && (col >= 0)
//     && (col <= col_end)
//     && (!(std::find(vec.begin(), vec.end(), matrix[row][col]) != vec.end()))
//    ) {
//        return true;
//    }
//    return false;
//}
//
//bool dfsMatrix(int matrix[2][4], int row, int col, int row_end, int col_end, vector<int> &vec) {
//
//    if(vec.size() == 7) {
//
//        if(validMatrix(matrix, row+1, col, row_end, col_end, vec)) {
//            vec.push_back(matrix[row+1][col]);
//        } else if(validMatrix(matrix, row, col+1, row_end, col_end, vec)) {
//            vec.push_back(matrix[row][col+1]);
//        } else if(validMatrix(matrix, row-1, col, row_end, col_end, vec)) {
//            vec.push_back(matrix[row-1][col]);
//        } else if(validMatrix(matrix, row, col-1, row_end, col_end, vec)) {
//            vec.push_back(matrix[row][col-1]);
//        }
//    }
//
//    if(vec.size() == 8) {
//        return true;
//    }
//
//    if(validMatrix(matrix, row, col, row_end, col_end, vec)) {
//
//        vec.push_back(matrix[row][col]);
//
//        if( (dfsMatrix(matrix, row+1, col, row_end, col_end, vec)) 
//         || (dfsMatrix(matrix, row, col+1, row_end, col_end, vec)) 
//         || (dfsMatrix(matrix, row-1, col, row_end, col_end, vec)) 
//         || (dfsMatrix(matrix, row, col-1, row_end, col_end, vec)) 
//        ) {
//            return true;
//        } else {
//            vec.pop_back();
//            return false;
//        }
//    }
//    return false;
//}

int main() {
    // construct graph
    //   ___   0 - 1
    //   \ /    \ /
    //    3 ---- 2

    Graph graph;
    graph.construct_graph();
    graph.printAllNodes();
//
//    // Time: O(V + E), Space: O(V^2)
//    cout << "Breadth First Traversal" << "(starting from vertex 2): ";
//    g.BFS(2);
//    cout << endl;
//
//    // Time: O(V + E), Space: O(V^2)
//    cout << "Depth First Traversal: ";
//    g.DFS();
//    cout << endl;
//
//    cout << endl << endl << "Trial DFS: ";
//    vector<int> vec;
//    g.DFS_trial(vec);
//    for(int i = 0; i < vec.size(); i++) {
//        cout << vec[i] << " ";
//    }
//    cout << endl << endl;
//
//    int matrix[2][4] = {{1, 2, 3, 4}
//                      , {5, 6, 7, 8}
//                       };
//
//    vector<int> vec1;
//    dfsMatrix(matrix, 0, 0, 1, 3, vec1);
//    for(int i = 0; i < vec1.size(); i++) {
//        cout << vec1[i] << " ";
//    }
//    cout << endl << endl;

    return 0;
}
