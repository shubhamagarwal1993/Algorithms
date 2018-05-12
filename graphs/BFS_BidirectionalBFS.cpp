#include <iostream>
#include <list>
#include <vector>

using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph {
    private:
        // No. of vertices
        int V;

        // Pointer to an array containing adjacency lists
        list<int> *adj;

    public:
        // Constructor
        Graph(int V);

        // function to add an edge to graph
        void addEdge(int v, int w);

        // prints BFS traversal from a given source s
        void BFS(int s);

        // prints Bidirectional BFS traversal of the complete graph
        void BBFS(int s, int t);
};

Graph::Graph(int V) {
    this->V = V;
    this->adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    // Add w to v’s list
    this->adj[v].push_back(w);
    this->adj[w].push_back(v);
}

Graph construct_graph() {
    Graph g(15);
    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(8, 10);
    g.addEdge(9, 11);
    g.addEdge(9, 12);
    g.addEdge(10, 13);
    g.addEdge(10, 14);
    return g;
}

void Graph::BFS(int s) {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

// The function to do DFS traversal. It uses recursive DFSUtil()
void Graph::BBFS(int s, int t) {

    // Mark all the vertices as not visited
    bool s_visited[V];
    bool t_visited[V];
    for(int i = 0; i < V; i++) {
        s_visited[i] = false;
        t_visited[i] = false;
    }

    // keep track of parents to print path later on
    int s_parent[V];
    int t_parent[V];

    // Create a queue for BBFS - for front and backward search
    list<int> s_queue;
    list<int> t_queue;

    // flag to detect if s and t ever intersect
    int intersectNode = -1;

    // Mark the starting node as visited and enqueue it
    s_visited[s] = true;
    s_queue.push_back(s);
    s_parent[s] = -1;

    // Mark the target node as visited and enqueue it
    t_visited[t] = true;
    t_queue.push_back(t);
    t_parent[t] = -1;

    while(!s_queue.empty() && !t_queue.empty()) {

        // Dequeue starting vertex from queue and print it
        int s_current = s_queue.front();
        s_queue.pop_front();
        list<int>::iterator s_i;
        for(s_i = adj[s_current].begin(); s_i != adj[s_current].end(); s_i++) {
            if(!s_visited[*s_i]) {
                s_parent[*s_i] = s_current;
                s_visited[*s_i] = true;
                s_queue.push_back(*s_i);
            }
        }

        // Dequeue target vertex from queue and print it
        int t_current = t_queue.front();
        t_queue.pop_front();
        list<int>::iterator t_i;
        for(t_i = adj[t_current].begin(); t_i != adj[t_current].end(); t_i++) {
            if(!t_visited[*t_i]) {
                t_parent[*t_i] = t_current;
                t_visited[*t_i] = true;
                t_queue.push_back(*t_i);
            }
        }

        // check if any intersecting vertex
        for(int i = 0; i < V; i++) {
            if(s_visited[i] && t_visited[i]) {
                intersectNode = i;
            }
        }

        // if intersectNode, then we can stop BBFS and print path
        if(intersectNode != -1) {
            vector<int> path;
            path.push_back(intersectNode);

            int i = intersectNode;
            while(i != s) {
                path.push_back(s_parent[i]);
                i = s_parent[i];
            }

            std::reverse(path.begin(), path.end());

            i = intersectNode;
            while(i != t) {
                path.push_back(t_parent[i]);
                i = t_parent[i];
            }

            // print path
            vector<int>::iterator it;
            cout << endl << "*****Path*****" << endl;
            for(it = path.begin(); it != path.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << "No Path exists between " << s << " and " << t << endl;
    return;
}

int main() {
    // construct graph
    //   ___   0 - 1
    //   \ /    \ /
    //    3 ---- 2

    Graph g = construct_graph();

    // Time: O(V + E), Space: O(V^2), with branching factor b, running time is O(b^d)
    cout << "Breadth First Traversal" << "(starting from vertex 2): ";
    g.BFS(2);
    cout << endl;

    // Time: O(V + E), Space: O(V^2), with branching factor b, running time is O(b^(d/2) + b^(d/2))
    cout << "Bidirectional Breadth First Traversal: ";
    g.BBFS(0, 3);
    cout << endl;

    return 0;
}
