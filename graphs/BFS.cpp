#include <iostream>
#include <list>
#include <vector>

using namespace std;

#define ROW 6
#define COL 4

class Point {
    public:
        int x;
        int y;
        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
};

// This class represents a directed graph using adjacency list representation
class Graph {
    private:
        // No. of vertices
        int V;

        // Pointer to an array containing adjacency lists
        list<int> *adj;

        void printAllPathsUtil(int src, int dest, bool visited[], vector<int> path, vector<int> &shortest_path);

    public:
        // Constructor
        Graph(int V) {
            this->V = V;
            this->adj = new list<int>[V];
        }

        // function to add a directed edge to graph
        void addDirectedEdge(int v, int w) {
            // Add w to v’s list
            this->adj[v].push_back(w);
        }

        // function to add an undirected edge to graph
        void addUndirectedEdge(int v, int w) {
            // Add w to v’s list and vice versa
            this->adj[v].push_back(w);
            this->adj[w].push_back(v);
        }

        // prints BFS traversal from a given source s
        void BFS(int s);
        void anyPath(int s, int d, bool visited[], vector<int> path);
        void allPaths(int s, int d);
        void findPathInMatrix();
        void BBFS(int s, int t);

        // construct graph
        //  ____   0 ---> 1
        //  \  /   ^\\   /
        //   ^v       v v
        //    3 <---- 2
        void constructDirectedGraph() {
            addDirectedEdge(0, 1);
            addDirectedEdge(0, 2);
            addDirectedEdge(0, 6);
            addDirectedEdge(1, 2);
            addDirectedEdge(1, 4);
            addDirectedEdge(2, 3);
            addDirectedEdge(2, 4);
            addDirectedEdge(3, 4);
            addDirectedEdge(4, 5);
            addDirectedEdge(5, 6);
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
            //addUndirectedEdge(4, 5);
            addUndirectedEdge(5, 6);
        }
};

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

void Graph::anyPath(int src, int dest, bool visited[], vector<int> path) {

    visited[src] = true;
    path.push_back(src);

    if(src == dest) {
        cout << endl << "Any path ";
        for(int it = 0; it < path.size(); it++) {
            cout << path[it] << " ";
        }
        cout << endl;
        return;
    }

    list<int>::iterator i;
    for(i = adj[src].begin(); i != adj[src].end(); i++) {
        if(!visited[*i]) {
            anyPath(*i, dest, visited, path);
        }
    }

    // Backtrack - Remove current vertex from path[] and mark it as unvisited
    path.pop_back();
    visited[src] = false;
    return;
}

void Graph::allPaths(int src, int dest) {

    // Mark all the vertices as not visited
    bool visited[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }
 
    // Create an array to store paths
    vector<int> path;
    vector<int> shortest_path;
 
    // Call the recursive helper function to print all paths
    printAllPathsUtil(src, dest, visited, path, shortest_path);
    cout << "Shortest Path from 1 to 5: ";
    for(int i = 0; i < shortest_path.size(); i++) {
        cout << shortest_path[i] << " ";
    }
    cout << endl;
}

void Graph::printAllPathsUtil(int src, int dest, bool visited[], vector<int> path, vector<int> &shortest_path) {

    // Mark the current node and store it in path
    visited[src] = true;
    path.push_back(src);

    // If current vertex is same as destination, then print current path
    if(src == dest) {
        if(shortest_path.size() == 0 || shortest_path.size() > path.size()) {
            shortest_path = path;
        }

        for(int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        // If current vertex is not destination, recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for(i = adj[src].begin(); i != adj[src].end(); i++) {
            if(!visited[*i]) {
                printAllPathsUtil(*i, dest, visited, path, shortest_path);
            }
        }
    }

    // Backtrack - Remove current vertex from path[] and mark it as unvisited
    path.pop_back();
    visited[src] = false;
    return;
}

bool samePoint(Point a, Point b) {
    return (a.x == b.x) && (a.y == b.y);
}

bool safeCell(int matrix[ROW][COL], int new_row, int new_col) {
    if(new_row >= ROW || new_row < 0) {
        return false;
    }
    if(new_col >= COL || new_col < 0) {
        return false;
    }
    if(!matrix[new_row][new_col]) {
        return false;
    }
    return true;
}

void anyPathInMatrix(int matrix[ROW][COL], Point src, Point dest, bool visited[ROW][COL], vector<Point> vec) {

    // Mark the current node as visited and add it to path
    vec.push_back(src);
    visited[src.x][src.y] = true;

    if(samePoint(src, dest)) {
        cout << "Any path in matrix" << endl;
        for(int i = 0; i < vec.size(); i++) {
            Point temp = vec[i];
            cout << "(" << temp.x << ", " << temp.y << ") ";
        }
        cout << endl;
        return;
    }

    int new_row = src.x - 1;
    int new_col = src.y;
    Point curr_point = Point(new_row, new_col);
    if(safeCell(matrix, new_row, new_col) && !visited[new_row][new_col]) {
        anyPathInMatrix(matrix, curr_point, dest, visited, vec);
    }

    new_row = src.x;
    new_col = src.y - 1;
    curr_point = Point(new_row, new_col);
    if(safeCell(matrix, new_row, new_col) && !visited[new_row][new_col]) {
        anyPathInMatrix(matrix, curr_point, dest, visited, vec);
    }

    new_row = src.x;
    new_col = src.y + 1;
    curr_point = Point(new_row, new_col);
    if(safeCell(matrix, new_row, new_col) && !visited[new_row][new_col]) {
        anyPathInMatrix(matrix, curr_point, dest, visited, vec);
    }

    new_row = src.x + 1;
    new_col = src.y;
    curr_point = Point(new_row, new_col);
    if(safeCell(matrix, new_row, new_col) && !visited[new_row][new_col]) {
        anyPathInMatrix(matrix, curr_point, dest, visited, vec);
    }

    vec.pop_back();
    visited[src.x][src.y] = false;
    return;
}

void Graph::findPathInMatrix() {
   int matrix[ROW][COL] = {{ 1, 0, 1, 1},
                           { 1, 0, 1, 0},
                           { 1, 1, 1, 0},
                           { 1, 0, 0, 0},
                           { 1, 1, 1, 0},
                           { 1, 0, 1, 1}};
    Point src(1, 2);
    Point dest(4, 1);

    // Mark all the vertices as not visited
    bool visited[ROW][COL];
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            visited[i][j] = false;
        }
    }

    // Create a queue for BFS
    vector<Point> vec;

    anyPathInMatrix(matrix, src, dest, visited, vec);

    return;
}

// The function to do Bi-directional BFS traversal
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

        // Dequeue starting vertex from queue and add neighbors to queue
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

        // Dequeue target vertex from queue and add neighbors to queue
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
                break;
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

    int V = 10;

    Graph g(V);
    g.constructDirectedGraph();

//    // simple BFS, Time: O(V + E), Space: O(V^2)
    cout << "Simple BFS starting from 2: ";
    g.BFS(2);
    cout << endl << endl;

    // BFS - any path from source node to dest node, Time: O(V + E), Space: O(V^2)
    cout << "BFS any path from 1 to 5: ";
    vector<int> path;
    bool visited[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }
    g.anyPath(0, 5, visited, path);
    cout << endl << endl;

    // BFS all paths from source node to dest node, Time: O(V + E), Space: O(V^2)
    cout << "BFS all paths from 1 to 5: " << endl;
    g.allPaths(1, 5);
    cout << endl << endl;

    // BFS - on matrix
    g.findPathInMatrix();

    // Bidirectional BFS
    Graph g1(10);
    g1.constructUndirectedGraph();
    g1.BBFS(1, 5);

    return 0;
}
