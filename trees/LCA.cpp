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

        Node* findLCAUtil(Node* root, int node1, bool &node1_exists, int node2, bool &node2_exists) {

            Node* test = NULL;
            if(root == NULL) {
                return NULL;
            }

            if(root->data == node1) {
                node1_exists = true;
                test = root;
            }

            if(root->data == node2) {
                node2_exists = true;
                test = root;
            }

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
};

int main() {
    Tree tree;
    tree.root = tree.constructTree();
    tree.findLCA(tree.root, 14, 11);
    tree.findLCA(tree.root, 8, 3);
    tree.destroyTree(tree.root);
    tree.root = NULL;

    return 0;
}
