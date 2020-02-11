#include <iostream>
#include <list>
#include <vector>
#include <stack>

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
        void DFSUtil(int v, bool visited[]) {
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

    public:
        // Constructor
        Graph(int V) {
            this->V = V;
            this->adj = new list<int>[V];
        }

        // function to add an edge to graph
        void addEdgeDirected(int v, int w) {
            // Add w to v’s list
            adj[v].push_back(w);
        }

        void addEdgeUndirected(int v, int w) {
            adj[v].push_back(w);
            adj[w].push_back(v);
        }

        Graph construct_graph() {
            // construct graph
            //   ___   0 - 1
            //   \ /    \ /
            //    3 ---- 2

            Graph g(4);
            g.addEdgeDirected(0, 1);
            g.addEdgeDirected(0, 2);
            g.addEdgeDirected(1, 2);
            g.addEdgeDirected(2, 0);
            g.addEdgeDirected(2, 3);
            g.addEdgeDirected(3, 3);
            return g;
        }

        //  1   3
        //   \ /
        //    0
        //   / \
        //  2   4
        void constructGraphIterative() {
            addEdgeUndirected(0, 1);
            addEdgeUndirected(0, 3);
            addEdgeUndirected(2, 3);
            addEdgeUndirected(1, 4);
        }

        // DFS traversal of the complete graph, using recursive DFSUtil()
        void DFS() {
            // Time: O(V + E), Space: O(V^2)
            cout << "Depth First Traversal: ";

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
            cout << endl;
        }

        void DFSIterative(int start) {

            cout << "Depth First Traversal Iterative: ";
            bool visited[5];
            for(int i = 0; i < V; i++) {
                visited[i] = false;
            }

            stack<int> s;
            s.push(start);
            visited[start] = true;
            cout << start << " ";

            list<int>::iterator iter;

            while(!s.empty()) {

                bool found_neighbor = false;
                int curr = s.top();
                for(iter = adj[curr].begin(); iter != adj[curr].end(); iter++) {
                    if(!visited[*iter]) {
                        found_neighbor = true;
                        s.push(*iter);
                        visited[*iter] = true;
                        cout << *iter << " ";
                        break;
                    }
                }

                if(!found_neighbor) {
                    s.pop();
                }
            }
            cout << endl;
        }
};

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
    Graph g(4);
    g.construct_graph();

    // Simple DFS
    g.DFS();

    int matrix[2][4] = {{1, 2, 3, 4}
                       ,{5, 6, 7, 8}
                       };
    vector<int> vec1;
    dfsMatrix(matrix, 0, 0, 1, 3, vec1);
    for(int i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl << endl;

    Graph g1(5);
    g1.constructGraphIterative();
    g1.DFSIterative(0);

    return 0;
}

