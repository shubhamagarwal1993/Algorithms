/*
 * Travelling Salesman Problem
 * Given a set of cities and distance between every pair of cities,
 * find the shortest possible route that visits every city exactly once and returns to the starting point
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
    private:
        int V;
        unordered_map <int, vector<tuple<int, int>> >adj;
        vector<int> nodes_vector;

        void addDirectedEdge(int src, int dest, int weight) {
            // key does not exist
            if(this->adj.find(src) == this->adj.end()) {
                tuple<int, int> val = tuple<int, int>{dest, weight};
                vector<tuple<int, int> > dest_vec;
                dest_vec.push_back(val);
                this->adj[src] = dest_vec;
                return;
            }

            // if key exists, search for existing val before inserting val
            vector<tuple<int, int> > dest_vec = this->adj[src];
            for(int i = 0; i < dest_vec.size(); i++) {
                // check if dest exists
                if(get<0>(dest_vec[i]) == dest) {
                    return;
                }
            }
            // Since dest does not exist, add it
            dest_vec.push_back(tuple<int, int>{dest, weight});
            this->adj[src] = dest_vec;
            return;
        }

        void addUndirectedEdge(int src, int dest, int weight) {
            addDirectedEdge(src, dest, weight);
            addDirectedEdge(dest, src, weight);
        }

        void getTsp(int src, int dest, unordered_map<int, bool> visited, vector<int> path, int path_weight, vector<int> &path_shortest, int &path_shortest_weight) {
            path.push_back(src);
            visited[src] = true;

            if(src == dest && (path.size() == this->V + 1)) {
                if(path_weight < path_shortest_weight) {
                    path_shortest_weight = path_weight;
                    path_shortest = path;
                }
                return;
            }

            // loop over all neighbors
            if(this->adj.find(src) != this->adj.end()) {
                vector<tuple<int, int> >adj_nodes = this->adj[src];
                for(int i = 0; i < adj_nodes.size(); i++) {
                    if((get<0>(adj_nodes[i]) == dest) && (path.size() == this->V)) {
                        path_weight += get<1>(adj_nodes[i]);
                        getTsp(get<0>(adj_nodes[i]), dest, visited, path, path_weight, path_shortest, path_shortest_weight);
                        path_weight -= get<1>(adj_nodes[i]);
                    } else if(!visited[get<0>(adj_nodes[i])]) {
                        path_weight += get<1>(adj_nodes[i]);
                        getTsp(get<0>(adj_nodes[i]), dest, visited, path, path_weight, path_shortest, path_shortest_weight);
                        path_weight -= get<1>(adj_nodes[i]);
                    }
                }
            }

            // backtrack
            path.pop_back();
            visited[src] = false;
            return;
        }

    public:
        void constructUndirectedGraph() {
            //    10      15
            //  |----- 1 -----|
            //  |      |20    |
            //  |      |      |
            //  | /--- 4 ---\ |
            //  |/25       30\|
            //  2 ----------- 3
            //        35

            addUndirectedEdge(1, 2, 10);
            addUndirectedEdge(1, 3, 15);
            addUndirectedEdge(1, 4, 20);
            addUndirectedEdge(2, 3, 35);
            addUndirectedEdge(2, 4, 25);
            addUndirectedEdge(3, 4, 30);

            nodes_vector = {1, 2, 3, 4};
            this->V = nodes_vector.size();

            cout << "--- 1 ---" << endl;
            unordered_map <int, vector<tuple<int, int>> >::iterator it;
            for(it = this->adj.begin(); it != this->adj.end(); it++) {
                cout << it->first << " ";
                vector<tuple<int, int>> adj_nodes = it->second;
                for(int i = 0; i < adj_nodes.size(); i++) {
                    cout << get<0>(adj_nodes[i]) << " ";
                }
                cout << endl;
            }
            cout << "--- 2 ---" << endl;
        }

        void tsp(int src) {
            // keep track of visited nodes
            unordered_map<int, bool> visited;
            for(int i = 0; i < this->nodes_vector.size(); i++) {
                visited[nodes_vector[i]] = false;
            }

            // path to store smallest path
            vector<int> path;
            int path_weight = 0;
            vector<int> path_shortest;
            int path_shortest_weight = INT_MAX;
            getTsp(src, src, visited, path, path_weight, path_shortest, path_shortest_weight);

            cout << "Travelling salesman path: ";
            for(int i = 0; i < path_shortest.size(); i++) {
                cout << path_shortest[i] << " ";
            }
            cout << " Path cost: " << path_shortest_weight << endl;

            return;
        }
};

int main() {
    Graph g;
    g.constructUndirectedGraph();
    g.tsp(1);
    return 0;
}
