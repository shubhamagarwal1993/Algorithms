#include <iostream>
#include <list>

using namespace std;

class Edge {
    public:
        int src;
        int dest;
        int weight;

        int getSrc() {
            return this->src;
        }

        int getDest() {
            return this->dest;
        }
};
 
class Graph {
    public:
        int V;
        int E;
        list<int> *adj;
        Edge* edge;

        Graph(int V, int E) {
            this->V = V;
            this->E = E;
            this->adj = new list<int>[V];
            this->edge = new Edge[E];
        }

        void addEdge(int source, int dest, int weight, int edge_index) {
            // Add w to v’s list and vice versa
            this->adj[source].push_back(dest);
            this->adj[dest].push_back(source);

            this->edge[edge_index].src = source;
            this->edge[edge_index].dest = dest;
            this->edge[edge_index].src = source;
        }

        void constructGraph() {
            /*
                    10
                0--------1
                |  \     |
               6|   5\   |15
                |      \ |
                2--------3
                    4
            */

            int edge_index = 0;
            addEdge(0, 1, 10, edge_index);
            edge_index = 1;
            addEdge(0, 2, 6, edge_index);
            edge_index = 2;
            addEdge(0, 3, 5, edge_index);
            edge_index = 3;
            addEdge(1, 3, 15, edge_index);
            edge_index = 4;
            addEdge(2, 3, 4, edge_index);
        }
};
 
// A structure to represent a subset for union-find
class Subset {
    public:
        int parent;
        int rank;
};
 
/**
 * A utility function to find set of an element i (uses path compression technique)
 */
int find(Subset subsets[], int i) {

    // find root and make root as parent of i (path compression)
    if(subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }

    return subsets[i].parent;
}

/**
 * A function that does union of two sets of x and y (uses union by rank)
 */
void unionFunc(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high rank tree (Union by Rank)
    if(subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if(subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        // If ranks are same, then make one as root and increment its rank by one
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

/**
 * Compare two edges according to their weights
 */
int myComp(const void* a, const void* b) {
    Edge* a1 = (struct Edge*)a;
    Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
 
/*
 * Construct MST using Kruskal's algorithm
 *
 * Time Complexity: O(ElogE) or O(ElogV)
 *     Sorting of edges takes O(ELogE) time
 *     Iterate through all edges and apply find-union algorithm which can take atmost O(ELogV) time
 *     Overall complexity is O(ELogE + ELogV) time
 *     The value of E can be atmost O(V^2), so O(LogV) are O(LogE) same. Therefore, overall time complexity is O(ElogE) or O(ElogV)
 */
void kruskalMst(Graph g) {

    // Step 1:  Sort all the edges in increasing order of their weight
    qsort(g.edge, g.E, sizeof(g.edge[0]), myComp);

    // Allocate memory for creating V subsets
    Subset subsets[g.V];

    // Create V subsets with single elements
    for(int v = 0; v < g.V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Tnis will store the resultant MST
    Edge result[g.V]; 
    int result_index = 0;

    int edge_index = 0;

    // Number of edges to be taken is equal to V-1
    while (result_index < g.V - 1) {
        // Step 2: Pick the smallest edge. And increment the index for next iteration
        Edge next_edge = g.edge[edge_index++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does't cause cycle, include it in result and increment the index of result for next edge
        if(x != y) {
            result[result_index++] = next_edge;
            unionFunc(subsets, x, y);
        }
        // Else discard the next_edge
    }
 
    // print the contents of result[] to display the built MST
    cout << "Following are the edges in the constructed MST" << endl;
    for(int i = 0; i < result_index; i++) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
    }
    return;
}

int main() {

    // Number of vertices and edges in graph
    int V = 4;
    int E = 5;
    Graph g(V, E);
    g.constructGraph();

    kruskalMst(g);
 
    return 0;
}

