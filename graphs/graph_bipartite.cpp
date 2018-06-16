// Bipartite Graph: A graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U
// In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U
// We can also say that there is no edge that connects vertices of same set
//
// A bipartite graph is possible if graph coloring is possible using 2 colors
//
// Algorithm to check if graph is bipartite:
//   - Method 1: (using m coloring verification and backtracking)
//     - check if 2 colorable using (https://www.geeksforgeeks.org/backttracking-set-5-m-coloring-problem/)
//   - Method 2: (using BFS)
//     - Assign RED color to source vertex (putting into set U)
//     - Color all neighbors BLUE (putting into set V)
//     - Color all neighbor’s neighbor with RED color (putting into set U)
//     - This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2
//     - While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite)

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
        bool checkBipartite();
};

void Graph::addEdge(int u, int w) {
    adj[u].push_back(w);
    adj[w].push_back(u);
}

// 0----3
// |    |
// 1----2
Graph constructGraph3() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    return g;
}

//  0-------2
//  |      /|
//  |     / |
//  |    /  |
//  |   /   |
//  |  /    |
//  | /     |
//  |/      |
//  1-------3----------4
Graph constructGraph1() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    return g;
}

//      0
//    /   \
//   /     \
//  1       4
//  |       |
//  2 ----- 3
Graph constructGraph2() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    return g;
}

bool Graph::checkBipartite() {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // BFS queue
    list<int> queue;

    // mask the current node as visited
    int s = 0;
    visited[0] = true;
    queue.push_back(0);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    // array to maintain colors
    int colorArray[V];
    for(int i = 0; i < V; ++i) {
        colorArray[i] = -1;
    }
    colorArray[s] = 1;

    cout << s << " " << colorArray[s] << endl;

    while(!queue.empty()) {
        int s = queue.front();
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i) {

            // check if adjacent vertices have the same color
            if(colorArray[*i] == colorArray[s]) {
                return false;
            }

            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
                colorArray[*i] = 1 - colorArray[s];
                cout << *i << " " << colorArray[*i] << endl;
            }
        }
        cout << endl;
    }
    cout << endl;
    return true;
}

int main() {

    // check using BFS
    Graph g1 = constructGraph1();
    if(g1.checkBipartite()) {
        cout << "Graph is bipartite" << endl;
    } else {
        cout << "Graph is not partite" << endl;
    }

    // check using BFS
    Graph g2 = constructGraph2();
    if(g2.checkBipartite()) {
        cout << "Graph is bipartite" << endl;
    } else {
        cout << "Graph is not partite" << endl;
    }

    // check using BFS
    Graph g3 = constructGraph3();
    if(g3.checkBipartite()) {
        cout << "Graph is bipartite" << endl;
    } else {
        cout << "Graph is not partite" << endl;
    }

    return 0;
}
