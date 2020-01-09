#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// tree node
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        // constructor
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class Tree {

    public:
        Node* root;

        // constructor
        Tree() {
            this->root = NULL;
        }

        void construct_tree() {

            //        50
            //        / \
            //       /   \
            //      /     \
            //     /       \
            //    10       60
            //   /  \     /  \
            //  5   20  55   70
            //          /   /  \
            //        51   65  80
            Node* root = new Node(50);
            root->left = new Node (40);
            root->left->right = new Node (45);
            root->left->left = new Node (30);
            root->left->left->left = new Node (20);
            //Node* temp = root;

            //temp->left = new Node(10);
            //temp->right = new Node(60);

            //temp = temp->left;
            //temp->left = new Node(5);
            //temp->right = new Node(20);

            //temp = root->right;
            //temp->left = new Node(55);
            //temp->right = new Node(70);

            //temp->left->left = new Node(51);
            //temp->right->left = new Node(65);
            //temp->right->right = new Node(80);

            this->root = root;
            return;
        }

        int get2ndLargestInBSTInorder() {
            int node_count = 0;
            return this->get2ndLargestInBSTInorderUtil(this->root, node_count);
        }

        void get2ndLargestInBST() {
            // a temp variable, so that the original root value does not change
            Node* root = this->root;

            // root cannot be null and must have at least 1 child
            if((root == NULL) || (root->right == NULL && root->left == NULL)) {
                cout << "Cannot find the 2nd largest element" << endl;
                return;
            }

            // if tree does not have a right subtree, then largest in left subtree
            if(root->left && (root->right == NULL)) {
                Node* secondLargest = this->getRightMostNode(root->left);
                cout << "2nd largest element = " << secondLargest->data << endl;
                return;
            }

            while(root) {
                // if current is the parent of the largest element, and the largest has no children
                if(root->right && (root->right->left == NULL) && (root->right->right == NULL)) {
                    cout << "2nd largest element = " << root->data << endl;
                    return;
                }

                root = root->right;
            }

            cout << "1 Cannot find the 2nd largest element" << endl;
            return;
        }

    private:
        // helper function for get2ndLargestInBSTInorder
        int get2ndLargestInBSTInorderUtil(Node* root, int node_count) {
            if(root == NULL) {
                return node_count;
            }

            node_count = get2ndLargestInBSTInorderUtil(root->right, node_count);

            node_count++;
            if(node_count == 2) {
                cout << "2nd largest element = " << root->data << endl;
            }

            node_count = get2ndLargestInBSTInorderUtil(root->left, node_count);
            return node_count;
        }

        Node* getRightMostNode(Node* root) {
            if(root == NULL) {
                return NULL;
            }

            if(root->right == NULL) {
                return root;
            }
            return getRightMostNode(root->right);
        }
};

int main() {

    Tree tree;
    tree.construct_tree();

    // Method1: Get inorder, and 2nd node in reverse inorder
    // Running time O(n), Space O(1)
    tree.get2ndLargestInBSTInorder();

    // Method2: Find the largest node, and then the second largest
    // Running time O(n), Space O(1)
    tree.get2ndLargestInBST();

    return 0;
}

