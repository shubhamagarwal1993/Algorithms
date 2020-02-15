#include <iostream>

using namespace std;

class Node {
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
    public:
        Node* root;

        Tree() {
            this->root = NULL;
        }

        Node* constructTree() {
            Node* root = new Node(8);

            root->left = new Node(3);
            root->left->left = new Node(1);
            root->left->right = new Node(6);
            root->left->right->left = new Node(4);
            root->left->right->right = new Node(7);

            root->right = new Node(12);
            root->right->left = new Node(11);
            root->right->right = new Node(15);
            root->right->right->left = new Node(14);

            return root;
        }

        Node* getLCA(Node* root, int node1, int &node1_height, int node2, int &node2_height, int &dist, int level) {

            Node* temp = NULL;
            if(root == NULL) {
                return NULL;
            }

            if(root->data == node1) {
                node1_height = level;
                temp = root;
            }

            if(root->data == node2) {
                node2_height = level;
                temp = root;
            }

            Node* LCALeft = getLCA(root->left, node1, node1_height, node2, node2_height, dist, level+1);
            Node* LCARight = getLCA(root->right, node1, node1_height, node2, node2_height, dist, level+1);

            if(temp != NULL) {
                return temp;
            }

            // could not LCA in both subtrees
            if(LCALeft == NULL && LCARight == NULL) {
                return NULL;
            // found LCA, return it
            } else if(LCALeft != NULL && LCARight != NULL) {
                dist = node1_height + node2_height - (2*level);
                return root;
            // found LCA in either of the branches, return the one with the LCA
            } else {
                return (LCALeft != NULL) ? LCALeft : LCARight;
            }
        }

        void nodeDistance(Node* root, int node1, int node2) {
            if(root == NULL) {
                return;
            }

            // find LCA
            int node1_height = -1;
            int node2_height = -1;
            int dist = -1;
            Node* lca = getLCA(root, node1, node1_height, node2, node2_height, dist, 0);
            if(lca == NULL || (node1_height == -1) || (node2_height == -1)) {
                cout << "Cannot find LCA" << endl;
            }

            cout << "LCA: " << lca->data << endl;
            cout << "Dist between " << node1 << " and " << node2 << ": " << dist << endl;

            return;
        }

        void printTree(Node* root) {
            if(root == NULL) {
                return;
            }

            printTree(root->left);
            cout << root->data << " ";
            printTree(root->right);
        }

        void destroyTree(Node* root) {
            if(root) {
                destroyTree(root->left);
                destroyTree(root->right);
                delete root;
            }
        }
};

int main() {
    Tree tree;
    tree.root = tree.constructTree();
    Node* root_copy = tree.root;
    tree.nodeDistance(root_copy, 4, 14);
    tree.destroyTree(tree.root);
    return 0;
}
