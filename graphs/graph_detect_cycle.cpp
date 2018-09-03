#include <iostream>
#include <list>
#include <vector>

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

        void addDirectedEdge(int u, int w) {
            this->adj[u].push_back(w);
        }

        void constructDirectedGraph() {
            addDirectedEdge(0, 1);
            addDirectedEdge(0, 2);
            addDirectedEdge(1, 2);
            addDirectedEdge(2, 0);
            addDirectedEdge(3, 3);
        }

        void isCyclic() {

            vector<int> path;
            // Mark all vertices as not visited and not part of recursion stack
            bool visited[V];
            int recStack[V];
            for(int i = 0; i < V; i++) {
                visited[i] = false;
                recStack[i] = -1;
            }

            // Call recursive helper function to detect cycle in different DFS trees
            for(int i = 0; i < V; i++) {
                if(!visited[i]) {
                    if(isCyclicUtil(i, visited, recStack, path)) {
                        cout << "Graph contains cycle" << endl;
                        cout << endl;
                    } else {
                        cout << "Graph doesn't contain cycle" << endl;
                    }
                }
            }
        }

        bool isCyclicUtil(int v, bool visited[], int recStack[], vector<int> path) {

            if(visited[v] == false) {
                // Mark the current node as visited and part of recursion stack
                visited[v] = true;
                recStack[v] = v;
                path.push_back(v);

                // Recur for all the vertices adjacent to this vertex
                list<int>::iterator i;
                for(i = adj[v].begin(); i != adj[v].end(); ++i) {
                    if(!visited[*i] && isCyclicUtil(*i, visited, recStack, path)) {
                        return true;
                    } else if(recStack[*i] >= 0) {
                        path.push_back(*i);
                        cout << "Cycle at node: " << v << " " << recStack[*i] << endl;
                        for(int i = 0; i < path.size(); i++) {
                            cout << path[i] << " ";
                        }
                        cout << endl;
                        return true;
                    }
                }
            }
            recStack[v] = -1;  // remove the vertex from recursion stack
            path.pop_back();
            return false;
        }
};

int main() {

    // Detect cycle in directed graph
    // Can use DFS, tarjan's algo, graph coloring. All take time O(V + E)
    // DFS - Time Complexity: O(V + E)
    Graph g_directed(4);
    g_directed.constructDirectedGraph();
    g_directed.isCyclic();

    return 0;
}
