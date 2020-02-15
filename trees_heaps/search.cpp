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
            this->root               = new Node(5);
            this->root->left         = new Node(3);
            this->root->left->right  = new Node(4);
            this->root->left->left   = new Node(2);
            this->root->right        = new Node(7);
            this->root->right->right = new Node(8);
            this->root->right->left  = new Node(6);
        }

        void printInorder() {
            printInorderUtil(this->root);
            cout << endl;
            return;
        }

        void printInorderUtil(Node* curr) {
            if(curr == NULL) {
                return;
            }

            printInorderUtil(curr->left);
            cout << curr->data << " ";
            printInorderUtil(curr->right);
        }

        void height() {
            cout << "Height of tree: " << heightUtil(this->root) << endl;
            return;
        }

        int heightUtil(Node* curr) {
            if(curr == NULL) {
                return 0;
            }

            int lHeight = heightUtil(curr->left);
            int rHeight = heightUtil(curr->right);

            return max(lHeight, rHeight) + 1;
        }

        void search(int val) {
            cout << "Search: " << searchUtil(this->root, val) << endl;
            return;
        }

        bool searchUtil(Node* curr, int val) {
            if(curr == NULL) {
                return false;
            }

            if(val == curr->data) {
                return true;
            }

            if(val > curr->data) {
                return searchUtil(curr->right, val);
            } else {
                return searchUtil(curr->left, val);
            }
        }

        ~Tree() {
            destroyTree(this->root);
            this->root = NULL;
        }
        void destroyTree(Node* curr) {
            if(curr == NULL) {
                return;
            }

            destroyTree(curr->left);
            destroyTree(curr->right);
            curr->left = NULL;
            curr->right = NULL;
            delete(curr);
        }

        void checkBST() {

            cout << "Tree BST check: " << checkBSTUtil(this->root, INT_MIN, 'a', INT_MAX, 'a') << endl;
        }

        bool checkBSTUtil(Node* curr, int max, char leftCheck, int min, char rightCheck) {
            if(curr == NULL) {
                return true;
            }

            // check for left tree
            if(leftCheck != 'a' && curr->data > max) {
                return false;
            }
            if(rightCheck != 'a' && curr->data < min) {
                return false;
            }

            // recurse in tree
            return checkBSTUtil(curr->left, curr->data, 'b', min, rightCheck) &&
            checkBSTUtil(curr->right, max, leftCheck, curr->data, 'b');
        }
};

int main() {
    Tree tree;

    tree.constructTree();
    tree.printInorder();
    tree.height();
    tree.search(9);
    tree.checkBST();
    return 0;
}
