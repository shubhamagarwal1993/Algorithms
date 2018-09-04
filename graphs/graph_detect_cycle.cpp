#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

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

        void addUndirectedEdge(int u, int w) {
            this->adj[u].push_back(w);
            this->adj[w].push_back(u);
        }

        void constructDirectedGraph() {
            addDirectedEdge(0, 1);
            addDirectedEdge(0, 2);
            addDirectedEdge(1, 2);
            addDirectedEdge(2, 0);
            addDirectedEdge(3, 3);
        }

        void constructUndirectedGraph() {
            addUndirectedEdge(0, 1);
            addUndirectedEdge(0, 2);
            addUndirectedEdge(0, 3);
            addUndirectedEdge(3, 4);
            addUndirectedEdge(2, 4);
        }

        void directedGraphIsCyclic() {

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
                    if(directedGraphIsCyclicUtil(i, visited, recStack, path)) {
                        cout << "Graph contains cycle" << endl;
                        cout << endl;
                    } else {
                        cout << "Graph doesn't contain cycle" << endl;
                    }
                }
            }
        }

        bool directedGraphIsCyclicUtil(int v, bool visited[], int recStack[], vector<int> path) {

            if(visited[v] == false) {
                // Mark the current node as visited and part of recursion stack
                visited[v] = true;
                recStack[v] = v;
                path.push_back(v);

                // Recur for all the vertices adjacent to this vertex
                list<int>::iterator i;
                for(i = adj[v].begin(); i != adj[v].end(); ++i) {
                    if(!visited[*i] && directedGraphIsCyclicUtil(*i, visited, recStack, path)) {
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

        void undirectedGraphIsCyclicUsingDFS() {

            vector<int> path;
            // Mark all vertices as not visited
            bool visited[V];
            for(int i = 0; i < V; i++) {
                visited[i] = false;
            }

            // in undirected graph, parent will always from a loop
            // We need to keep a node's parent updated to avoid check for cycle with parent
            int parent = -1;

            // Call recursive helper function to detect cycle in different DFS trees
            for(int i = 0; i < V; i++) {
                if(!visited[i]) {
                    if(undirectedGraphIsCyclicUtilUsingDFS(i, visited, path, parent)) {
                        cout << "Graph contains cycle" << endl;
                        cout << endl;
                    } else {
                        cout << "Graph doesn't contain cycle" << endl;
                    }
                }
            }
        }

        bool undirectedGraphIsCyclicUtilUsingDFS(int v, bool visited[], vector<int> path, int parent) {

            visited[v] = true;
            path.push_back(v);

            // Recur for all the vertices adjacent to this vertex
            list<int>::iterator i;
            for(i = adj[v].begin(); i != adj[v].end(); i++) {
                if(!visited[*i]) {
                    if(undirectedGraphIsCyclicUtilUsingDFS(*i, visited, path, v)) {
                        return true;
                    }
                } else if(*i != parent) {
                    path.push_back(*i);
                    for(int i = 0; i < path.size(); i++) {
                        cout << path[i] << " ";
                    }
                    cout << endl;
                    return true;
                }

            }
            path.pop_back();
            return false;
        }

        /**
         * Takes a vertex and finds its main parent
         */
        int find(int parent[], int i) {
            if(parent[i] == -1) {
                return i;
            }
            return find(parent, parent[i]);
        }

        /**
         * Takes parents and merges them one set
         */
        void unionVertices(int parent[], int src_parent, int dest_parent) {
            int src_set = find(parent, src_parent);
            int dest_set = find(parent, dest_parent);
            if(src_set >= 0) {
                parent[src_set] = dest_set;
            }
        }

        /**
         * Detect cycle in an undirected graph using disjoint set (or union-find)
         *
         * Uses a disjoint set data structure, this data structure keeps track
         * of set of elements partioned into a number of disjoint subsets
         *
         * This algo performs 2 functions:
         *   - Find:  Find which subset a particular element is in
         *            Used to determine if 2 elements are in the same subset
         *   - Union: Join 2 subsets into a single subset
         *
         * How it works:
         *   - Keep track of the subsets in an array called parent[]
         *      - Initially, all slots of parent array are initialized to -1
         *      - This means there is only one item in every subset
         *
         *   - Now process all edges one by one
         *      - For each edge, make subsets using both the vertices of the edge
         *      - If both the vertices are in the same subset, a cycle is found
         *      - If vertices are in different subset, take union of them. Make node 0 parent of node 1
         * TODO: an edge tables needs to be added and this algo should be run on edges instead of vertices
         */
        void undirectedGraphIsCyclicUsingUnionFind() {

            // store path of cycle
            vector<int> path;

            int parent[V];
            for(int i = 0; i < V; i++) {
                parent[i] = -1;
            }

            list<int>::iterator it;
            // Iterate through all edges of graph
            for(int i = 0; i < V; i++) {

                for(it = adj[i].begin(); it != adj[i].end(); it++) {
                    int src_parent = find(parent, i);
                    int dest_parent = find(parent, *it);

                    // both points in same set
                    if(src_parent == dest_parent) {
                        cout << "&&Found cycle&&" << endl;
                        break;
                    }

                    // if points in not the same set, then union them into same set
                    unionVertices(parent, src_parent, dest_parent);
                }
            }
        }
};

int main() {

    // Detect cycle in directed graph
    // Can use DFS, tarjan's algo, graph coloring. All take time O(V + E)
    // DFS - Time Complexity: O(V + E), space O(V) -> O(V) path of cycle, O(V) recursion stack, O(V) visited array
    Graph g_directed(4);
    g_directed.constructDirectedGraph();
    g_directed.directedGraphIsCyclic();

    cout << "-------" << endl;

    // Detect cycle in undirected graph
    // Can use union-find, DFS, BFS, and graph coloring. All take time O(V + E) except union-find which takes O(E logV)
    Graph g_undirected(5);
    g_undirected.constructUndirectedGraph();
    // DFS - Time Complexity: O(V + E), space O(V) -> O(V) path of cycle, O(V) recursion stack, O(V) visited array
    g_undirected.undirectedGraphIsCyclicUsingDFS();
    // union-find - Time Complexity: O(E logV), space O(V) -> O(V) path of cycle, O(V) recursion stack, O(V) visited array
    g_undirected.undirectedGraphIsCyclicUsingUnionFind();

    return 0;
}
