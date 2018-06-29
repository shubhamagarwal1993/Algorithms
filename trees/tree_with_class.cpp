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

Node* newNode(int data) {
    Node* root = new Node(data);
    return root;
}

class Tree {
    public:
        Node* root;

        Tree() {
            this->root = NULL;
        }

        Node* constructTree() {

            Node* root = newNode(50);

            root->left = newNode(30);
            root->right = newNode(70);

            root->left->left = newNode(20);
            root->left->right = newNode(40);

            root->right = newNode(70);
            root->right->left = newNode(60);
            root->right->right = newNode(80);

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
    // make a tree
    Tree tree;
    tree.root = tree.constructTree();

    // print tree inOrder
    tree.printInorder(tree.root);
    cout << endl;

    // delete tree
    tree.destroyTree(tree.root);
    tree.root = NULL;

    return 0;
}
