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

        void constructTree() {
            //      8
            //     / \
            //    /   \
            //   3     12
            //  / \    / \
            // 1   6  11  15
            //    / \    /
            //   4   7  14
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

            this->root = root;
            return;
        }

        void findLCA(Node* root, int node1, int node2) {
            if(root == NULL) {
                return;
            }

            bool node1_exists = false;
            bool node2_exists = false;

            Node* lca = findLCAUtil(root, node1, node1_exists, node2, node2_exists);
            if(node1_exists && node2_exists) {
                cout << "Found LCA: " << lca->data << endl;
            } else if(node1_exists && !node2_exists) {
                cout << node2 << " does not exist" << endl;
            } else if(!node1_exists && node2_exists) {
                cout << node1 << " does not exist" << endl;
            } else {
                cout << node1 << " and " << node2 << " do not exist" << endl;
            }

            return;
        }

        void findDistanceBetweenNodes(int node1, int node2) {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;
            int node1_height = -1;
            int node2_height = -1;
            int distance = -1;
            int level = 0;

            Node* lca = findDistanceBetweenNodesUtil(root, node1, node1_height, node2, node2_height, distance, level);
            if(lca != NULL && node1_height != -1 && node2_height != -1) {
                cout << "LCA: " << lca->data << ", Distance between node " << node1 << ", and " << node2 << " is " << distance << endl;
            } else if(node1_height != -1 && node2_height == -1) {
                cout << "Could not find " << node2 << endl;
            } else if(node1_height == -1 && node2_height != -1) {
                cout << "Could not find " << node1 << endl;
            } else {
                cout << "Could not find " << node1 << " and " << node2 << endl;
            }

            return;
        }

        void destroyTree(Node* root) {
            if(root == NULL) {
                return;
            }

            destroyTree(root->left);
            destroyTree(root->right);
            root->left = NULL;
            root->right = NULL;
            delete root;
        }

        void diameter() {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;
            int diameter = 0;
            diameterUtil(root, diameter);
            cout << "Diameter: " << diameter << endl;
            return;
        }

    private:
        Node* findLCAUtil(Node* root, int node1, bool &node1_exists, int node2, bool &node2_exists) {

            if(root == NULL) {
                return NULL;
            }

            // This will store LCA to return the search earlier
            Node* test = NULL;

            if(root->data == node1) {
                node1_exists = true;
                test = root;
            }

            if(root->data == node2) {
                node2_exists = true;
                test = root;
            }

            // If LCA already found, return it.
            if(node1_exists && node2_exists && test != NULL) {
                return test;
            }

            Node* LCALeft = findLCAUtil(root->left, node1, node1_exists, node2, node2_exists);
            Node* LCARight = findLCAUtil(root->right, node1, node1_exists, node2, node2_exists);

            // check if temp is set, which means LCA was found
            if(test != NULL) {
                return test;
            }

            if(LCALeft == NULL && LCARight == NULL) {
                return NULL;
            } else if(LCALeft != NULL && LCARight != NULL) {
                return root;
            } else {
                return (LCALeft != NULL) ? LCALeft : LCARight;
            }
        }

        Node* findDistanceBetweenNodesUtil(Node* root, int node1, int &node1_height, int node2, int &node2_height, int &distance, int level) {
            if(root == NULL) {
                return NULL;
            }

            // To find LCA
            Node* temp = NULL;

            // Check for node1
            if(root->data == node1) {
                temp = root;
                node1_height = level;
            }

            // Check for node2
            if(root->data == node2) {
                temp = root;
                node2_height = level;
            }

            // if found both nodes, return from here itself
            if(node1_height != -1 && node2_height != -1 && temp != NULL) {
                return temp;
            }

            Node* lca_left = findDistanceBetweenNodesUtil(root->left, node1, node1_height, node2, node2_height, distance, level+1);
            Node* lca_right = findDistanceBetweenNodesUtil(root->right, node1, node1_height, node2, node2_height, distance, level+1);

            if(temp != NULL) {
                return temp;
            }

            // Could not find LCA in both subtrees
            if(lca_left == NULL && lca_right == NULL) {
                return NULL;
            } else if(lca_left != NULL && lca_right != NULL) {
                distance = node1_height + node2_height - (2 * level) + 1;
                return root;
            } else {
                // Found LCA in one of the branches, return the one with the LCA
                return (lca_left != NULL) ? lca_left : lca_right;
            }
        }

        int diameterUtil(Node* root, int &diameter) {
            if(root == NULL) {
                return 0;
            }

            int diameter_left = diameterUtil(root->left, diameter);
            int diameter_right = diameterUtil(root->right, diameter);

            diameter = max(diameter, diameter_left + diameter_right + 1);

            return 1 + max(diameter_left, diameter_right);
        }
};

int main() {
    Tree tree;
    tree.constructTree();

    // Most common node as parent of 2 given nodes
    tree.findLCA(tree.root, 14, 11);
    tree.findLCA(tree.root, 8, 3);

    // Find distance between 2 given nodes
    tree.findDistanceBetweenNodes(4, 14);
    tree.findDistanceBetweenNodes(3, 11);

    // Diameter - Find max distance between any nodes
    tree.diameter();

    tree.destroyTree(tree.root);
    tree.root = NULL;

    return 0;
}
