#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    private:
        unordered_map <int, vector<int> > adj;
        int V;

        void addDirectedEdge(int src, int dest) {
            // Key does not exist
            if(this->adj.find(src) == this->adj.end()) {
                vector<int> dest_vec = {dest};
                this->adj[src] = dest_vec;
            } else {
                vector<int> dest_vec = this->adj[src];
                for(int idx = 0; idx < dest_vec.size(); idx++) {
                    if(dest_vec[idx] == dest) {
                        return;
                    }
                }
                this->adj[src].push_back(dest);
            }
        }

        void addUndirectedEdge(int src, int dest) {
            addDirectedEdge(src, dest);
            addDirectedEdge(dest, src);
        }

        void printAllPathsDFS(int src, int dest, unordered_map<int, bool> visited, vector<int> path) {

            // push current val
            path.push_back(src);
            visited[src] = true;

            if(src == dest) {
                for(int i = 0; i < path.size(); i++) {
                    cout << path[i] << " ";
                }
                cout << endl;
                return;
            }

            if(this->adj.find(src) != this->adj.end()) {
                vector<int> adj_nodes = this->adj[src];
                for(int i = 0; i < adj_nodes.size(); i++) {
                    if(!visited[adj_nodes[i]]) {
                        printAllPathsDFS(adj_nodes[i], dest, visited, path);
                    }
                }
            }
            path.pop_back();
            visited[src] = false;
            return;
        }

        void printAllPathsBFS(int src, int dest, unordered_map<int, bool> visited, vector<int> path) {

            // keep track of current path
            vector<int> path_curr;
            path_curr.push_back(src);

            // store all path possibilities
            vector<vector<int>> path_combinations;
            path_combinations.push_back(path_curr);

            while(!path_combinations.empty()) {
                path_curr = path_combinations.front();
                path_combinations.erase(path_combinations.begin());
                int path_curr_last_element = path_curr.back();

                // Check if path found
                if(path_curr_last_element == dest) {
                    for(int i = 0; i < path_curr.size(); i++) {
                        cout << path_curr[i] << " ";
                    }
                    cout << endl;
                }

                // go through all adjacent nodes, and make new path combinations
                if(this->adj.find(path_curr_last_element) != this->adj.end()) {
                    vector<int> adj_nodes = this->adj[path_curr_last_element];

                    for(int i = 0; i < adj_nodes.size(); i++) {
                        if(!visited[adj_nodes[i]]) {
                            visited[adj_nodes[i]] = true;
                            vector<int> path_new(path_curr);
                            path_new.push_back(adj_nodes[i]);
                            path_combinations.push_back(path_new);
                        }
                    }
                }
            }
            return;
        }

    public:
        Graph() {}
        void constructGraph() {
            //   ____________
            //  /            \
            // 4 -- 9 -- 2 -- 5
            //
            addUndirectedEdge(4, 9);
            addUndirectedEdge(9, 2);
            addUndirectedEdge(2, 5);
            // addUndirectedEdge(4, 5);

            this->V = 4;
        }

        void printAdjList() {
            unordered_map<int, vector<int>>::iterator it;
            for(it = this->adj.begin(); it != this->adj.end(); it++) {
                cout << it->first << ": ";
                for(int i = 0; i < it->second.size(); i++) {
                    cout << it->second[i] << " ";
                }
                cout << endl;
            }
        }

        void allPaths(int src, int dest) {
            unordered_map<int, bool> visited;
            visited[2] = false;
            visited[4] = false;
            visited[5] = false;
            visited[9] = false;

            vector<int> path;
            // printAllPathsDFS(src, dest, visited, path);
            printAllPathsBFS(src, dest, visited, path);
        }
};

int main() {
    Graph g;
    g.constructGraph();
    // g.printAdjList();
    g.allPaths(4, 5);

    return 0;
}
