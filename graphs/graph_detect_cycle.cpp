#include <iostream>
#include <list>

using namespace std;

class Graph {
    private:
        int V;
        list<int> *adj;

    public:
        Graph(int V) {
            this->V = V;
            this->adj = new list<int>[V];
        }

        void addEdge(int u, int w) {
            this->adj[u].push_back(w);
        }

        void constructGraph() {
            addEdge(0, 1);
            addEdge(0, 2);
            addEdge(1, 2);
            addEdge(2, 0);
            addEdge(2, 3);
            addEdge(3, 3);
        }

        void isCyclic() {

            // Mark all vertices as not visited and not part of recursion stack
            bool *visited = new bool[V];
            bool *recStack = new bool[V];
            for(int i = 0; i < V; i++) {
                visited[i] = false;
                recStack[i] = false;
            }

            // Call recursive helper function to detect cycle in different DFS trees
            //for(int i = 0; i < V; i++) {
                if(isCyclicUtil(0, visited, recStack)) {
                    cout << "Graph contains cycle" << endl;
                } else {
                    cout << "Graph doesn't contain cycle" << endl;
                }
            //}
        }

        bool isCyclicUtil(int v, bool visited[], bool recStack[]) {

            if(visited[v] == false) {
                // Mark the current node as visited and part of recursion stack
                visited[v] = true;
                recStack[v] = true;
         
                // Recur for all the vertices adjacent to this vertex
                list<int>::iterator i;
                for(i = adj[v].begin(); i != adj[v].end(); ++i) {
                    if(!visited[*i] && isCyclicUtil(*i, visited, recStack)) {
                        return true;
                    } else if(recStack[*i]) {
                        return true;
                    }
                }
            }
            recStack[v] = false;  // remove the vertex from recursion stack
            return false;
        }
};

int main() {

    Graph g(4);
    g.constructGraph();

    // Time Complexity: O(V^2 + E) in worst case
    g.isCyclic();

    return 0;
}
