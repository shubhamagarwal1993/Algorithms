#include <iostream>
#include <vector>

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
            Node* root = new Node(1);

            root->left = new Node(2);
            root->left->left = new Node(4);
            root->left->right = new Node(5);

            root->right = new Node(3);
            root->right->right = new Node(8);
            root->right->right->left = new Node(6);
            root->right->right->right = new Node(7);
            return root;
        //              1
        //             / \
        //            2   3
        //           / \   \
        //          4   5   8
        //                 / \
        //                6   7
        }

        int countBelowEachNode(Node* root) {

            if(root == NULL) {
                return 0;
            }

            int left_count = countBelowEachNode(root->left);
            int right_count = countBelowEachNode(root->right);

            if(root->left != NULL) {
                left_count += 1;
            }
            if(root->right != NULL) {
                right_count += 1;
            }

            cout << root->data << " " << left_count + right_count << endl;
            return left_count + right_count;
        }
};

int main() {
    Tree tree;
    tree.root = tree.constructTree();

    // O(n) time and O(1) space
    tree.countBelowEachNode(tree.root);

    return 0;
}

