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

            Node* root = new Node(50);

            root->left = new Node(30);
            root->right = new Node(70);

            root->left->left = new Node(20);
            root->left->right = new Node(40);

            root->right = new Node(70);
            root->right->left = new Node(60);
            root->right->right = new Node(80);

            return root;
        }

        void printInorder(Node* root) {
            if(root == NULL) {
                return;
            }

            printInorder(root->left);
            cout << root->data << " ";
            printInorder(root->right);
        }

        void destroyTree(Node* root) {
            if(root == NULL) {
                return;
            }

            destroyTree(root->right);
            destroyTree(root->left);
            root->left = NULL;
            root->right = NULL;
            delete root;
        }
};


int main() {
    Tree tree;
    tree.root = tree.constructTree();

    tree.printInorder(tree.root);
    cout << endl;

    // free memory
    tree.destroyTree(tree.root);
    tree.root = NULL;

    return 0;
}
