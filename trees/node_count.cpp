#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* root = new Node();
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

Node* constructTree() {
    Node* root = newNode(1);

    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right = newNode(3);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);
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

int main() {
    Node* root = constructTree();

    // O(n) time and O(1) space
    countBelowEachNode(root);

    return 0;
}

