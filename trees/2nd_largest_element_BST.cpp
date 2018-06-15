#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// constructor for new node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

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

Node* construct_tree() {

    Node* root = newNode(50);
    Node* temp = root;

    temp->left = newNode(10);
    temp->right = newNode(60);

    temp = temp->left;
    temp->left = newNode(5);
    temp->right = newNode(20);

    temp = root->right;
    temp->left = newNode(55);
    temp->right = newNode(70);

    temp->left->left = newNode(51);
    temp->right->left = newNode(65);
    temp->right->right = newNode(80);

    return root;
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

    Node* root = construct_tree();

    // By using inorder method - 2nd node in reverse inorder
    // Running time O(n), Space O(1)
    int node_count = 0;
    get2ndLargestInBSTInorder(root, node_count);

    // By finding largest node and then second largest
    // Running time O(n), Space O(1)
    Node* secondLargest = get2ndLargestInBST(root);
    if(secondLargest == NULL) {
        cout << "Cannot find the 2nd largest element" << endl;
    } else {
        cout << "2nd largest element = " << secondLargest->data << endl;
    }

    return 0;
}

