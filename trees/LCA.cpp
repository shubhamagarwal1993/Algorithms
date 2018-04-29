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

Node* findLCAUtil(Node* root, int node1, bool &node1_exists, int node2, bool &node2_exists) {

    Node* test = NULL;
    if(root == NULL) {
        return NULL;
    }

    if(root->data == node1) {
        node1_exists = true;
        test = root;
    }

    if(root->data == node2) {
        node2_exists = true;
        test = root;
    }

    Node* LCALeft = findLCAUtil(root->left, node1, node1_exists, node2, node2_exists);
    Node* LCARight = findLCAUtil(root->right, node1, node1_exists, node2, node2_exists);

    // check if temp is setm which means LCA was found
    if(test != NULL) {
        return test;
    }

    if(LCALeft == NULL && LCARight == NULL) {
        return NULL;
    } else if(LCALeft != NULL && LCARight != NULL) {
        return root;
    } else {
        return (LCALeft != NULL) ? LCALeft : LCARight;
    }
}

void findLCA(Node* root, int node1, int node2) {
    if(root == NULL) {
        return;
    }

    bool node1_exists = false;
    bool node2_exists = false;

    Node* lca = findLCAUtil(root, node1, node1_exists, node2, node2_exists);
    if(node1_exists && node2_exists) {
        cout << "Found LCA: " << lca->data << endl;
    } else if(node1_exists && !node2_exists) {
        cout << node2 << " does not exist" << endl;
    } else if(!node1_exists && node2_exists) {
        cout << node1 << " does not exist" << endl;
    } else {
        cout << node1 << " and " << node2 << " do not exist" << endl;
    }

    return;
}

int main() {
    Node* root = constructTree();
    findLCA(root, 14, 11);

    return 0;
}
