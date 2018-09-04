// Spanning Tree - Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. A single graph can have many different spanning trees
// Minimum Spanning Tree (MST) or minimum weight spanning tree - For a weighted, connected and undirected graph is a spanning tree with weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree
// A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph
#include <iostream>
#include <list>

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
};

class Graph {
    private:
        int V;
        int E;
        list<int> *adj;
        list<int> *edge;
    public:
        Graph(int V, int E) {
            this->V = V;
            this->E = E;
            this->adj = new list<int>[V];
            this->edge = new list<int>[V];
        }

        // function to add an undirected edge to graph
        void addUndirectedEdge(int v, int w) {
            // Add w to v’s list and vice versa
            this->adj[v].push_back(w);
            this->adj[w].push_back(v);

            // check if edge exists
            list<int>::iterator it;
            for(it = edge[v].begin(); it != edge[v].end(); it++) {
                if(*it == w) {
                    return;
                }
            }
            for(it = edge[w].begin(); it != edge[w].end(); it++) {
                if(*it == v) {
                    return;
                }
            }

            // edge not found, add it
            this->edge[v].push_back(w);
            return;
        }

        void constructUndirectedGraph() {
            addUndirectedEdge(0, 1);
            addUndirectedEdge(0, 2);
            addUndirectedEdge(0, 6);
            addUndirectedEdge(1, 2);
            addUndirectedEdge(1, 4);
            addUndirectedEdge(2, 3);
            addUndirectedEdge(2, 4);
            addUndirectedEdge(3, 4);
            addUndirectedEdge(4, 5);
            addUndirectedEdge(5, 6);
            return;
        }
};

/**
 * Sort all the edges in non-decreasing order of their weight
 * Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far
 *     If cycle is not formed, include this edge
 *     Else, discard it
 * Repeat step#2 until there are (V-1) edges in the spanning tree
 *
 * This is a greedy algo
 */
void kruskal() {

}

int main() {

    Graph g_undirected(7, 10);
    g_undirected.constructUndirectedGraph();

    return 0;
}
