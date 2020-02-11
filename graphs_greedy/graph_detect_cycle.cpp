#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

class Edge {
    private:
        int src;
        int dest;
        int weight;
    public:
        Edge(int src, int dest, int weight) {
            this->src = src;
            this->dest = dest;
            this->weight = weight;
        }
        int getSrc() {
            return this->src;
        }
        int getDest() {
            return this->dest;
        }
};

class Graph {
    private:
        int V;
        int E;
        list<int> *adj;
        list<int> *edge;

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

            // Backtrack, remove vertex from recursion stack, and not in cyclic path
            recStack[v] = -1;
            path.pop_back();
            return false;
        }

    public:
        Graph(int V, int E) {
            this->V = V;
            this->E = E;
            this->adj = new list<int>[V];
            this->edge = new list<int>[V];
        }

        void addDirectedEdge(int u, int w) {
            this->adj[u].push_back(w);
        }

        void addUndirectedEdge(int u, int w) {
            this->adj[u].push_back(w);
            this->adj[w].push_back(u);

            // check if edge exists
            list<int>::iterator it;
            for(it = edge[u].begin(); it != edge[u].end(); it++) {
                if(*it == w) {
                    return;
                }
            }
            for(it = edge[w].begin(); it != edge[w].end(); it++) {
                if(*it == u) {
                    return;
                }
            }

            // edge not found, add it
            this->edge[u].push_back(w);
            return;
        }

        void constructDirectedGraph() {

            //    ________
            //   /        \
            //  /          V
            // 0 --> 1 --> 2
            // ^          /
            //  \________/
            //
            // 3 ----
            // ^    |
            // |____|

            addDirectedEdge(0, 1);
            addDirectedEdge(0, 2);
            addDirectedEdge(1, 2);
            addDirectedEdge(2, 0);
            addDirectedEdge(3, 3);
        }

        void constructUndirectedGraph() {

            // 1
            // |
            // |
            // 0 --- 2 --- 4
            // |           |
            // |____ 3 ____|

            addUndirectedEdge(0, 1);
            addUndirectedEdge(0, 2);
            addUndirectedEdge(0, 3);
            addUndirectedEdge(3, 4);
            addUndirectedEdge(2, 4);
        }

        void directedGraphIsCyclic() {

            // Path of cycle
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
                    if(!directedGraphIsCyclicUtil(i, visited, recStack, path)) {
                        cout << "Graph doesn't contain cycle" << endl;
                    }
                }
            }
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
         * Print cycle
         */
        void printPath(vector<Edge> path, int dest) {

            int path_size = path.size();
            bool visited[path_size];
            for(int i = 0; i < path_size; i++) {
                visited[i] = false;
            }

            int src = -1;
            // initialize first edge
            for(int i = 0; i < path_size; i++) {
                int curr_src = path[i].getSrc();
                int curr_dest = path[i].getDest();
                if(curr_src == dest || curr_dest == dest) {
                    visited[i] = true;
                    if(curr_src == dest) {
                        src = curr_dest;
                    } else {
                        src = curr_src;
                    }
                    break;
                }
            }

            vector<int> new_path;
            new_path.push_back(dest);
            new_path.push_back(src);

            bool not_found = true;
            int last_src = -1;
            while(src != dest) {

                for(int i = 0; i < path_size; i++) {
                    if(!visited[i]) {
                        if(path[i].getSrc() == src) {
                            visited[i] = true;
                            last_src = src;
                            src = path[i].getDest();
                            not_found = false;
                            break;
                        } else if(path[i].getDest() == src) {
                            visited[i] = true;
                            last_src = src;
                            src = path[i].getSrc();
                            not_found = false;
                            break;
                        }
                    }
                }

                if(not_found) {
                    src = last_src;
                    new_path.pop_back();
                } else {
                    new_path.push_back(src);
                    not_found = true;
                }
            }
            for(int i = 0; i < new_path.size(); i++) {
                cout << new_path[i] << " ";
            }
            cout << endl;
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
         */
        void undirectedGraphIsCyclicUsingUnionFind() {

            int parent[V];
            for(int i = 0; i < V; i++) {
                parent[i] = -1;
            }

            vector<Edge> path;

            list<int>::iterator it;
            // Iterate through all edges of graph
            for(int i = 0; i < E; i++) {

                for(it = edge[i].begin(); it != edge[i].end(); it++) {

                    Edge temp(i, *it, 1);
                    path.push_back(temp);

                    int src = i;
                    int dest = *it;
                    int src_parent = find(parent, i);
                    int dest_parent = find(parent, *it);

                    // both points in same set
                    if(src_parent == dest_parent) {
                        //cout << src << " " << dest << " " << src_parent << " " << dest_parent << endl;
                        cout << "Found cycle - caused by edge " << src << "-" << dest << endl;
                        printPath(path, dest);
                        cout << endl;
                        break;
                    }

                    // if points in not the same set, then union them into same set
                    unionVertices(parent, src_parent, dest_parent);
                }
            }
        }
};

int main() {

    /*
     * Detect cycle in directed graph
     *
     * Algo: DFS, tarjan's algo, graph coloring
     * DFS: Time complexity: O(V + E), Space complexity O(V) -> O(V) path of cycle, O(V) recursion stack, O(V) visited array
     */
    Graph g_directed(4, 5);
    g_directed.constructDirectedGraph();
    g_directed.directedGraphIsCyclic();

    cout << "-------" << endl;

    /*
     * Detect cycle in undirected graph
     *
     * Algo: Union-find, DFS, BFS, and graph coloring
     */
    Graph g_undirected1(5, 5);
    g_undirected1.constructUndirectedGraph();

    /*
     * Union-find: Time complexity: O(E logV), Space complexity: O(V) -> O(V) path of cycle, O(V) recursion stack, O(V) visited array
     */
    g_undirected1.undirectedGraphIsCyclicUsingUnionFind();

    /*
     * DFS, BFS, Graph coloring: Time complexity: O(V + E), Space complexity: O(V) -> O(V) path of cycle, O(V) recursion stack, O(V) visited array
     */
    g_undirected1.undirectedGraphIsCyclicUsingDFS();

    return 0;
}
