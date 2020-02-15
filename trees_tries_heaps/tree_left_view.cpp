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

        void construct() {
            Node* root = new Node(4);
            root->left = new Node(5);
            root->right = new Node(2);
            root->right->left = new Node(3);
            root->right->right = new Node(1);
            root->right->left->left = new Node(6);
            root->right->left->right = new Node(7);

            this->root = root;
        }

        void leftView() {
            int max = 0;
            this->leftViewUtil(root, 1, max);
        }

    private:
        void leftViewUtil(Node* root, int level, int &max) {
            if(root == NULL) {
                return;
            }

            if(level > max) {
                cout << root->data << endl;
                max = level;
            }
            leftViewUtil(root->left, level+1, max);
            leftViewUtil(root->right, level+1, max);
        }
};

int main() {
    Tree tree;
    tree.construct();

    tree.leftView();

    return 0;
}
