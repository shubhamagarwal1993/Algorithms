// Check if given tree is a BST

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

        void printTree(Node* root) {
            if(root == NULL) {
                return;
            }

            cout << root->data << " ";
            printTree(root->left);
            printTree(root->right);
        }

        bool checkBST(Node* root, int min, bool min_char, int max, bool max_char) {

            if(root == NULL) {
                return true;
            }

            if( ((min_char == true) && (root->data < min)) || ((max_char == true) && (root->data > max)) ) {
                return false;
            }

            return checkBST(root->left, min, min_char, root->data, true) && checkBST(root->right, root->data, true, max, max_char);
        }
};

int main() {
    Tree tree;
    tree.constructTree();

    // print tree
    tree.printTree(tree.root);
    cout << endl;

    // check if tree is BST
    if(tree.checkBST(tree.root, 0, false, 0, false)) {
        cout << "IS BST" << endl;
    } else {
        cout << "IS not BST" << endl;
    }

    return 0;
}
