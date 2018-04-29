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

void leftView(Node* root, int level, int &max) {
    if(root == NULL) {
        return;
    }

    if(level > max) {
        cout << root->data << endl;
        max = level;
    }
    leftView(root->left, level+1, max);
    leftView(root->right, level+1, max);
}

int main() {
    Node* root = newNode(4);
    root->left = newNode(5);
    root->right = newNode(2);
    root->right->left = newNode(3);
    root->right->right = newNode(1);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);

    int max = 0;
    leftView(root, 1, max);

    return 0;
}
