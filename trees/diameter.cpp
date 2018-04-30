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

    // 4 including root
    root->left = newNode(3);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    // 3 excluding root
    root->right = newNode(12);
    root->right->left = newNode(11);
    root->right->right = newNode(15);
    root->right->right->left = newNode(14);

    return root;
}

int diameter(Node* root, int &sum) {
    if(root == NULL) {
        return 0;
    }

    int left = diameter(root->left, sum);
    int right = diameter(root->right, sum);

    if(left + right + 1 > sum) {
        sum = left + right + 1;
    }
    return std::max(left, right) + 1;
}

int main() {
    Node* root = constructTree();
    int sum = 0;
    diameter(root, sum);
    cout << "Diameter: " << sum << endl;
    return 0;
}
