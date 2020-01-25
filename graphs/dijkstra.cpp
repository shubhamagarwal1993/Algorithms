/*
 * Dijkstra’s shortest path algorithm
 * Given a graph and a source vertex in the graph, find shortest paths from source to all vertices in the given graph.
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

int minDistance(int dist[9], bool sptSet[9]) {
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

    int V = 9;

    // final dist from src to dest will be stored here
    int dist[V];

    // true if vertex is included in shortest path
    bool sptSet[V];

    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;
    for(int count = 0; count < V - 1; count++) {
        // Find min dist vertex not yet processed
        // dest is equal to src in the first iteration
        int dest = minDistance(dist, sptSet);

        // this vertex is now processed, and will not be touched again
        sptSet[dest] = true;

        // Update dist of vertices adjacent to dist
        for(int i = 0; i < V; i++) {
            if((!sptSet[i]) && (graph[dest][i] > 0) && (dist[dest] != INT_MAX) && (dist[dest] + graph[dest][i] < dist[i])) {
                dist[i] = dist[dest] + graph[dest][i];
            }
        }
    }

    printSolution(dist);
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

