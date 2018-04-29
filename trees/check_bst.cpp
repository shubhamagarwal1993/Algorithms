#include <iostream>

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
    Node* root = newNode(8);

    root->left = newNode(3);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    root->right = newNode(12);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    root->right->right->left = newNode(14);

    return root;
}

void printTree(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

bool checkBST(Node* root, int min, char min_char, int max, char max_char) {
    if(root == NULL) {
        return true;
    }

    if( ((min_char != 'a') && (root->data < min)) || ((max_char != 'a') && (root->data > max)) ) {
        return false;
    }

    return checkBST(root->left, min, min_char, root->data, 'b') && checkBST(root->right, root->data, 'b', max, max_char);
}

int main() {
    Node* root = constructTree();
    printTree(root);
    cout << endl;
    if(checkBST(root, 0, 'a', 0, 'a')) {
        cout << "IS BST" << endl;
    } else {
        cout << "IS not BST" << endl;
    }

    return 0;
}
