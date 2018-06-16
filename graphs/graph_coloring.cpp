// Graph coloring problem is to assign colors to certain elements of a graph subject to certain constraints
// Vertex coloring: most common graph coloring problem. Givem 'm' colors, find a way of coloring the vertices of a graph such that no two adjacent vertices are colored using same color.
// Edge coloring: No vertex is incident to two edges of same color
// Face Coloring (Geographical Map Coloring): Can be transformed into vertex coloring
//
// Chromatic Number: The smallest number of colors needed to color a graph G is called its chromatic number. This is an NP Complete problem

// This is a greedy algo to assign colors. It does not guarantee to use munimum colors, but guarantees to use no more than d + 1 colors where d is the max degree of a vertex
// Color first vertex with first color
// for the remaining V-1 vertices
//   consider the currently picked vertex and color it with the lowest numbered color that has not been used on any previously colored vertices adjacent to it
//   If all previously used colors appear on vertices adjacent to v, assign a new color to it

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

        void addEdge(int u, int w);
        void greedyColoring();
};

void Graph::addEdge(int u, int w) {
    adj[u].push_back(w);
    adj[w].push_back(u);
}

Graph constructGraph() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    return g;
}

void Graph::greedyColoring() {
    // will hold colors for all vertices
    int result[V];
    result[0] = 0;
    for(int i = 1; i < V; i++) {
        result[i] = -1;
    }

    // will hold available colors
    // available[i] value as True means that color 'i' is assiged to one of its adjacent vertices
    bool available[V];
    for(int i = 0; i < V; i++) {
        available[i] = false;
    }

    // Assign colors to remaining V-1 vertices
    for(int u = 1; u < V; u++) {

        // Assign color to current vertex
        //   First flag colors of adjacent vertices as unavailable - since we cannot have that
        //   Then find minimum available color
        list<int>::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); i++) {
            int vertex_color = result[*i];
            if(vertex_color != -1) {
                available[vertex_color] = true;
            }
        }

        // find the lowest available color
        for(int j = 0; j < V; j++) {
            if(available[j] == false) {
                result[u] = j;
                break;
            }
        }

        // reset the available colors array to use for next vertex
        for(i = adj[u].begin(); i != adj[u].end(); i++) {
            int vertex_color = result[*i];
            if(vertex_color != -1) {
                available[vertex_color] = false;
            }
        }
    }

    // print colors
    for(int i = 0; i < V; i++) {
        cout << "Vertex " << i << " color " << result[i] << endl;
    }
}

int main() {

    Graph g = constructGraph();

    // Time Complexity: O(V^2 + E) in worst case
    g.greedyColoring();

    return 0;
}
