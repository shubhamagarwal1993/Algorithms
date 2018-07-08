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

        Node* construct_tree() {

            Node* root = new Node(50);
            root->left = new Node (40);
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

            return root;
        }
};

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


Node* getRightMostNode(Node* root) {
    if(root == NULL) {
        return NULL;
    }

    if(root->right == NULL) {
        return root;
    }
    return getRightMostNode(root->right);
}

Node* get2ndLargestInBST(Node* root) {
    // root cannot be null and must have at least 1 child
    if((root == NULL) || (root->right == NULL && root->left == NULL)) {
        return NULL;
    }

    Node* current = root;

    while(current) {
        // if tree does not have a right subtree, then largest in left subtree
        if(root->left && (root->right == NULL)) {
            return getRightMostNode(root->left);
        }

        // if current is the parent of the largest element, and the largest has no children
        if(current->right && (current->right->left == NULL) && (current->right->right == NULL)) {
            return current;
        }

        current = current->right;
    }
    return NULL;
}

int get2ndLargestInBSTInorder(Node* root, int node_count) {
    if(root == NULL) {
        return node_count;
    }

    node_count = get2ndLargestInBSTInorder(root->right, node_count);

    node_count++;
    if(node_count == 2) {
        cout << "2nd largest element = " << root->data << endl;
    }

    node_count = get2ndLargestInBSTInorder(root->left, node_count);
    return node_count;
}

int main() {

    Tree tree;
    tree.root = tree.construct_tree();

    // By using inorder method - 2nd node in reverse inorder
    // Running time O(n), Space O(1)
    int node_count = 0;
    get2ndLargestInBSTInorder(tree.root, node_count);

    // By finding largest node and then second largest
    // Running time O(n), Space O(1)
    Node* secondLargest = get2ndLargestInBST(tree.root);
    if(secondLargest == NULL) {
        cout << "Cannot find the 2nd largest element" << endl;
    } else {
        cout << "2nd largest element = " << secondLargest->data << endl;
    }

    return 0;
}

