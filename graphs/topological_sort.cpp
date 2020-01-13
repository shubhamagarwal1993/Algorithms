#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class Graph {
    private:
        // no. of vertices
        int V;

        // adjacency list
        list<int> *adj;

        // indegree - how many nodes are pointing to current node
        vector<int> indegree;

        // helper functions
        void topologicalSortUtil(int vertex, bool* visited, stack<int> &s) {

            visited[vertex] = true;

            list<int>::iterator it;
            for(it = this->adj[vertex].begin(); it != this->adj[vertex].end(); it++) {
                if(visited[*it] != true) {
                    topologicalSortUtil(*it, visited, s);
                }
            }

            // recursion breaks here and last element in topological sort will be the first one here
            // Stock this in stack so that the latest / first element in sort is on top
            s.push(vertex);
            return;
        }

        void allTopologicalSortsUtil(bool* visited, vector<int> &vec) {

            // loop over all vertices and check for vertex with no indegree - first node to start with
            for(int i = 0; i < V; i++) {

                if(indegree[i] == 0 && visited[i] == false) {

                    // put current vertex as potential soln
                    vec.push_back(i);
                    visited[i] = true;

                    // reduce the indegree of vertex around it 
                    // This would be like getting rid of current vertex, so vectices with 0 indegree can be picked up in the next round
                    list<int>::iterator j;
                    for(j = adj[i].begin(); j != adj[i].end(); j++) {
                        indegree[*j]--;
                    }

                    // check for remaining vertices
                    allTopologicalSortsUtil(visited, vec);

                    // Backtrack to check for other possible topological sorts
                    // reset visited, remove element, and increate indegree
                    visited[i] = false;
                    //vec.pop_back();
                    vec.erase(vec.end() - 1);
                    for(j = adj[i].begin(); j != adj[i].end(); j++) {
                        indegree[*j]++;
                    }
                }
            }

            // if sort was found then print it
            if(vec.size() == V) {
                for(int i = 0; i < vec.size(); i++) {
                    cout << vec[i] << " ";
                }
                cout << endl;
            }
            return;
        }

    public:
        // Constructor
        Graph() {
        }

        void constructGraph(int V) {
            this->V = V;
            this->adj = new list<int>[V];

            for(int i = 0; i < V; i++) {
                indegree.push_back(0);
            }

            this->addEdge(5, 2);
            this->addEdge(5, 0);
            this->addEdge(4, 0);
            this->addEdge(4, 1);
            this->addEdge(2, 3);
            this->addEdge(3, 1);

            return;
        }

        // add edge
        void addEdge(int v, int w) {
            this->adj[v].push_back(w);

            // v points to w, so w has a new indegree
            this->indegree[w]++;
        }

        // print the graph
        void printGraph() {
            std::list<int>::iterator it;

            for(int vertex = 0; vertex < this->V; vertex++) {
                cout << vertex << ": ";
                for(it = this->adj[vertex].begin(); it != adj[vertex].end(); it++) {
                    cout << *it << " ";
                }
                cout << endl;
            }

            return;
        }

        // get any topological sort for the graph
        void topologicalSort() {

            // Will store topological sort to print later
            stack<int> s;

            bool visited[V];
            for(int i = 0; i < V; i++) {
                visited[i] = false;
            }

            for(int i = 0; i < V; i++) {
                if(visited[i] == false) {
                    topologicalSortUtil(i, visited, s);
                }
            }

            cout << "Any Topological Sort: ";
            while(!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
            cout << endl;

            return;
        }

        // get all topological sorts for the graph
        void allTopologicalSorts() {
            // vector to hold all the sorts
            vector<int> res;

            bool visited[V];
            for(int i = 0; i < V; i++) {
                visited[i] = false;
            }

            allTopologicalSortsUtil(visited, res);
        }
};

int main() {
    // construct graph
    //        5   4        5 -> 2  5 -> 0
    //       / \ / \       4 -> 1  4 -> 0
    //      2   0   1      2 -> 3
    //       \     /       3 -> 1
    //        \   /
    //          3

    Graph g;
    g.constructGraph(6);
    g.printGraph();

    g.topologicalSort();
    g.allTopologicalSorts();
    return 0;
}
