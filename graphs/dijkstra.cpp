/*
 * Dijkstra’s shortest path algorithm
 * Given a graph and a source vertex in the graph, find shortest paths from source to all vertices in the given graph
 *
 * Can be applied to both directed, and undirected graphs
 * Dijkstra’s algorithm doesn’t work for graphs with negative weight edges
 *
 * Generate a SPT (shortest path tree) with given source as root
 * Maintain two sets, one set contains vertices included in shortest path tree, other set includes vertices not yet included in shortest path tree
 * At every step of the algorithm, we find a vertex which is in the other set (set of not yet included) and has a minimum distance from the source.
 *
 * Running Time: O(V^2). Can be O(E log V) with the help of binary heap.
 * Space complexity: 
 *
 * Reference:
 * - https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
 * - https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/
 */
#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;
 
//class Edge {
//    private:
//        int src;
//        int dest;
//        int weight;
//    public:
//        Edge(int src, int dest, int weight) {
//            this->src = src;
//            this->dest = dest;
//            this->weight = weight;
//        }
//};
//
//// Class to represent a graph
//class Graph {
//    private:
//        // No. of vertices
//        int V;
//        int E;
//
//        // Pointer to an array containing adjacency listsList
//        list<int> *adj;
//        list<int> *edge;
//
//        // Create edge
//        void addUndirectedEdge(int src, int dest, int weight) {
//            this->adj[src].push_back(dest);
//            this->adj[dest].push_back(src);
//
//            // add edge, if it does not exist
//            list<int>::iterator it;
//            for(it = edge
//        }
//
//        // A function used by topologicalSort
//        void dijkstraUtil(vector<int> &res, bool visited[]) {
//            return;
//        }
//
//    public:
//        // Constructor
//        Graph(int V, int E) {
//            this->V = V;
//            this->E = E;
//            this->adj = new list<int>[V];
//            this->edge = new list<int>[E];
//        }
//
//        void construct_graph() {
//            // construct graph
//            //        5   4        5 -> 2    5 -> 0
//            //       / \ / \       4 -> 1    4 -> 0
//            //      2       0      1         2 -> 3
//            //       \     /       3 -> 1
//            //        \   /
//            //          3
//            addUndirectedEdge(0, 1, 5);
//            return;
//        }
//
//        // function to add an edge to graph
//        void addEdge(int v, int w) {
//            // Add w to v’s list
//            adj[v].push_back(w);
//        }
//
//        // prints a Topological Sort of the complete graph
//        void topologicalSort();
//
//        // prints all Topological Sorts of the complete graph
//        void allTopologicalSorts();
//};

void printSolution(int dist[]) {
    //
    for(int i = 0; i < 9; i++) {
        cout << i << " " << dist[i] << endl;
    }
    return;
}

/*
 * Find unvisited vertex with minimum distance from src
 */
int getClosestVertexFromSrc(int dist[9], bool sptSet[9]) {
    // find min distance vertex, and its index
    int min = INT_MAX;
    int min_idx = -1;

    for(int i = 0; i < 9; i++) {
        if(sptSet[i] == false && dist[i] <= min) {
            min = dist[i];
            min_idx = i;
        }
    }

    return min_idx;
}

void dijkstra(int graph[9][9], int src) {

    int vertex_count = 9;

    // final dist from src to dest will be stored here
    int distance_from_src[vertex_count];

    // true if vertex is included in shortest path
    bool shortest_path_set[vertex_count];

    for(int i = 0; i < vertex_count; i++) {
        distance_from_src[i] = INT_MAX;
        shortest_path_set[i] = false;
    }

    // Distance of source vertex from itself will be 0
    distance_from_src[src] = 0;

    for(int count = 0; count < vertex_count - 1; count++) {
        // Find min dist vertex not yet processed
        // dest is equal to src in the first iteration
        int src_new = getClosestVertexFromSrc(distance_from_src, shortest_path_set);

        // this vertex is now processed, and will not be touched again
        shortest_path_set[src_new] = true;

        // Update dist of vertices adjacent to dist
        for(int src_new_adj = 0; src_new_adj < vertex_count; src_new_adj++) {
            // unprocessed vertex
            // an edge exists from dest to i
            // weight of path from src to  v through dest is smaller than current value of dist[i]
            if((!shortest_path_set[src_new_adj]) && (graph[src_new][src_new_adj] > 0) && (distance_from_src[src_new] + graph[src_new][src_new_adj] < distance_from_src[src_new_adj])) {
                distance_from_src[src_new_adj] = distance_from_src[src_new] + graph[src_new][src_new_adj];
            }
        }
    }

    printSolution(distance_from_src);
    return;
}

// Driver program to test above functions
int main() {
    // Graph g(9);
    // g.construct_graph();

    /*
     * Adjacency matrix graph, with weigts
     */
    int V = 9;
    int graph[9][9] = { { 0,  4, 0,  0,  0,  0, 0,  8, 0 },
                        { 4,  0, 8,  0,  0,  0, 0, 11, 0 },
                        { 0,  8, 0,  7,  0,  4, 0,  0, 2 },
                        { 0,  0, 7,  0,  9, 14, 0,  0, 0 },
                        { 0,  0, 0,  9,  0, 10, 0,  0, 0 },
                        { 0,  0, 4, 14, 10,  0, 2,  0, 0 },
                        { 0,  0, 0,  0,  0,  2, 0,  1, 6 },
                        { 8, 11, 0,  0,  0,  0, 1,  0, 7 },
                        { 0,  0, 2,  0,  0,  0, 6,  7, 0 } };
    dijkstra(graph, 0);

    return 0;
}

