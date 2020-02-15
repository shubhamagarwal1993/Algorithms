#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph {
    private:
        // Pointer to an array containing adjacency lists
        unordered_map<int, vector<int>> adj;

    public:
        // Constructor
        Graph() {
        }

        // function to add a directed edge to graph
        void addDirectedEdge(int v, int w) {
            // Add w to v’s list
            unordered_map<int, vector<int>>::iterator it;
            it = this->adj.find(v);

            if(it == this->adj.end()) {
                vector<int> temp;
                temp.push_back(w);
                this->adj[v] = temp;
                return;
            }

            vector<int> temp = this->adj[v];
            temp.push_back(w);
            this->adj[v] = temp;
        }

        // construct graph
        //
        //      4
        //     / \
        //    /   \
        //   2     6
        //  / \   / \
        // 1   3 5   7
        //
        void constructDirectedGraphAdjList() {
            addDirectedEdge(4, 2);
            addDirectedEdge(4, 6);
            addDirectedEdge(2, 1);
            addDirectedEdge(2, 3);
            addDirectedEdge(6, 5);
            addDirectedEdge(6, 7);
        }

        unordered_map<int, vector<int>> getAdjList() {
            return this->adj;
        }
};

class Node {
    private:

    public:
        int data;
        Node* left;
        Node* right;
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class Tree {
    private:
        Node* root;

    public:
        Tree() {
            this->root = NULL;
        }

        void constructTreeFromAdjList(unordered_map<int, vector<int>> adjList, int data){
            this->root = constructTreeFromAdjListUtil(adjList, data);
        }

        Node* constructTreeFromAdjListUtil(unordered_map<int, vector<int>> adjList, int data) {

            Node* root = new Node(data);

            unordered_map<int, vector<int>>::iterator it = adjList.find(data);
            if(it != adjList.end()) {
                int root_left_data = adjList[data][0];
                int root_right_data = adjList[data][1];

                root->left = constructTreeFromAdjListUtil(adjList, root_left_data); 
                root->right = constructTreeFromAdjListUtil(adjList, root_right_data);
            }
            return root;
        }

        void inorderTraversal() {
            Node * root = this->root;
            inorderTraversalUtil(root);
            cout << endl;
            return;
        }

        void inorderTraversalUtil(Node* root) {
            if(root == NULL) {
                return;
            }

            inorderTraversalUtil(root->left);
            cout << root->data << " ";
            inorderTraversalUtil(root->right);
        }
};

int main() {

    Graph g;
    g.constructDirectedGraphAdjList();

    unordered_map<int, vector<int>> adjList = g.getAdjList();
    Tree t;

    unordered_map<int, vector<int>>::iterator it_adj;
    vector<int>::iterator it_vec;

    for(it_adj = adjList.begin(); it_adj != adjList.end(); it_adj++) {
        cout << it_adj->first << ": ";
        for(it_vec = it_adj->second.begin(); it_vec != it_adj->second.end(); it_vec++) {
            cout << *it_vec <<  " ";
        }
        cout << endl;
    }

    t.constructTreeFromAdjList(adjList, 4);
    t.inorderTraversal();

    return 0;
}
