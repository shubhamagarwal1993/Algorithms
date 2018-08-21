#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph {
    public:
        int V;
        list<int> *adj;

        Graph(int V) {
            this->V = V;
            this->adj = new list<int> [V];
        }

        //  1   3
        //   \ /
        //    0
        //   / \
        //  2   4
        void constructGraph() {
            addEdge(0, 1);
            addEdge(0, 3);
            addEdge(2, 3);
            addEdge(1, 4);
        }

        void addEdge(int v, int w) {
            adj[v].push_back(w);
            adj[w].push_back(v);
        }

        void DFS(int start) {

            bool visited[5];
            for(int i = 0; i < V; i++) {
                visited[i] = false;
            }

            stack<int> s;
            s.push(start);
            visited[start] = true;
            cout << start << endl;

            list<int>::iterator iter;

            while(!s.empty()) {

                bool found_neighbor = false;
                int curr = s.top();
                for(iter = adj[curr].begin(); iter != adj[curr].end(); iter++) {
                    if(!visited[*iter]) {
                        found_neighbor = true;
                        s.push(*iter);
                        visited[*iter] = true;
                        cout << *iter << endl;
                        break;
                    }
                }

                if(!found_neighbor) {
                    s.pop();
                }
            }
        }
};

int main() {
    Graph g(5);
    g.constructGraph();
    g.DFS(0);
    return 0;
}
