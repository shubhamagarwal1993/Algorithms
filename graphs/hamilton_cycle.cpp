#include <iostream>
#include <list>

using namespace std;

class Graph {
    public:
        int V;
        list<int> *adj;

        Graph(int V) {
            this->V = V;
            this->adj = new list<int>[V];
        }

        void addEdge(int v, int w) {
            adj[v].push_back(w);
        }

        void construct() {
            addEdge(0, 1);
            addEdge(0, 3);
            addEdge(1, 0);
            addEdge(1, 2);
            addEdge(1, 3);
            addEdge(1, 4);
            addEdge(2, 1);
            addEdge(2, 4);
            addEdge(3, 0);
            addEdge(3, 1);
            addEdge(3, 4);
            addEdge(4, 1);
            addEdge(4, 2);
            addEdge(4, 3);
        }

        void DFS() {
            bool visited[5] = {false};
            DFSUtil(0, visited);
            cout << endl;
        }

        void DFSUtil(int s, bool visited[]) {
            
            cout << s << " ";
            visited[s] = true;

            list<int>::iterator iter;
            for(iter = adj[s].begin(); iter != adj[s].end(); iter++) {
                if(!visited[*iter]) {
                    DFSUtil(*iter, visited);
                }
            }
        }
};

int main() {

    Graph g(5);
    g.construct();
    g.DFS();
    return 0;
}
