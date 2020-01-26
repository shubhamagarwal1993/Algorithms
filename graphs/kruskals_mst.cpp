#include <iostream>
#include <list>
#include <vector>

using namespace std;

// A structure to represent a subset for union-find
class Subset {
    public:
        int parent;
        int rank;

        /*
         * A utility function to find set of an element i (uses path compression technique)
         */
        int find(Subset subsets[], int i) {
            // find root and make root as parent of i (path compression)
            if(subsets[i].parent != i) {
                subsets[i].parent = find(subsets, subsets[i].parent);
            }

            return subsets[i].parent;
        }

        /*
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
};

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

        Edge(int src, int dest, int weight) {
            this->src = src;
            this->dest = dest;
            this->weight = weight;
        }

        /*
         * Compare two edges according to their weights
         */
        bool operator< (const Edge &other) const {
            return weight < other.weight;
        }
};
 
class Graph {
    public:
        int V;
        int E;
        list<int> *adj;
        vector<Edge> edges;

        Graph(int V, int E) {
            this->V = V;
            this->E = E;
            this->adj = new list<int>[V];
        }

        void addUndirectedEdge(int src, int dest, int weight) {
            // Add w to v’s list and vice versa
            this->adj[src].push_back(dest);
            this->adj[dest].push_back(src);

            // check if edge exists
            for(int idx = 0; idx < this->edges.size(); idx++) {
                if(this->edges[idx].src == src && this->edges[idx].dest == dest) {
                    return;
                }
            }

            for(int idx = 0; idx < this->edges.size(); idx++) {
                if(this->edges[idx].src == dest && this->edges[idx].dest == src) {
                    return;
                }
            }

            Edge edge = Edge(src, dest, weight);
            this->edges.push_back(edge);
            return;
        }

        void constructGraph() {
            /*
             *      10
             *  0--------1
             *  |  \     |
             * 6|   5\   |15
             *  |      \ |
             *  2--------3   
             *      4        
             */

            addUndirectedEdge(0, 1, 10);
            addUndirectedEdge(0, 2, 6);
            addUndirectedEdge(0, 3, 5);
            addUndirectedEdge(1, 3, 15);
            addUndirectedEdge(2, 3, 4);
        }

        /*
         * Construct MST using Kruskal's algorithm
         *
         * Time Complexity: O(ElogE) or O(ElogV)
         *   Sorting of edges takes O(ELogE) time
         *   Iterate through all edges and apply find-union algorithm which can take atmost O(ELogV) time
         *   Overall complexity is O(ELogE + ELogV) time
         *   The value of E can be atmost O(V^2), so O(LogV) and O(LogE) are the same.
         *   Therefore, overall time complexity is O(ElogE) or O(ElogV)
         */
        void kruskalMst() {

            // Step 1:  Sort all the edges in increasing order of their weight
            std::sort(this->edges.begin(), this->edges.end());

            // Allocate memory for creating V subsets
            Subset *subsets = new Subset[this->V * sizeof(Subset)];

            // Create V subsets with single elements
            for(int v = 0; v < this->V; v++) {
                subsets[v].parent = v;
                subsets[v].rank = 0;
            }

            // This will store the resultant MST
            vector<Edge> result;
            int result_idx = 0;
            int sorted_edges_idx = 0;

            // Number of edges to be taken is equal to V-1
            while(result_idx < this->V - 1 && sorted_edges_idx < this->E) {
                // Step 2: Pick the smallest edge. And increment the index for next iteration
                Edge next_edge = this->edges[sorted_edges_idx++];

                int x = subsets->find(subsets, next_edge.src);
                int y = subsets->find(subsets, next_edge.dest);

                // If including this edge does't cause cycle, include it in result and increment the index of result for next edge
                if(x != y) {
                    result.push_back(next_edge);
                    result_idx++;
                    subsets->unionFunc(subsets, x, y);
                }
                // Else discard next_edge, since it forms a cycle
            }

            // print the contents of result[] to display the built MST
            cout << "Following are the edges in the constructed MST" << endl;
            for(int i = 0; i < result_idx; i++) {
                cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
            }
            return;
        }
};
 
int main() {

    // Number of vertices and edges in graph
    int V = 4;
    int E = 5;
    Graph g(V, E);
    g.constructGraph();

    g.kruskalMst();
 
    return 0;
}

