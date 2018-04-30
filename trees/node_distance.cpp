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

Node* getLCA(Node* root, int node1, int &node1_height, int node2, int &node2_height, int &dist, int level) {

    Node* temp = NULL;
    if(root == NULL) {
        return NULL;
    }

    if(root->data == node1) {
        node1_height = level;
        temp = root;
    }

    if(root->data == node2) {
        node2_height = level;
        temp = root;
    }

    Node* LCALeft = getLCA(root->left, node1, node1_height, node2, node2_height, dist, level+1);
    Node* LCARight = getLCA(root->right, node1, node1_height, node2, node2_height, dist, level+1);

    if(temp != NULL) {
        return temp;
    }

    // could not LCA in both subtrees
    if(LCALeft == NULL && LCARight == NULL) {
        return NULL;
    // found LCA, return it
    } else if(LCALeft != NULL && LCARight != NULL) {
        dist = node1_height + node2_height - (2&level);
        return root;
    // found LCA in either of the branches, return the one with the LCA
    } else {
        return (LCALeft != NULL) ? LCALeft : LCARight;
    }
}

void nodeDistance(Node* root, int node1, int node2) {
    if(root == NULL) {
        return;
    }

    // find LCA
    int node1_height = -1;
    int node2_height = -1;
    int dist = -1;
    Node* lca = getLCA(root, node1, node1_height, node2, node2_height, dist, 0);
    if(lca == NULL || (node1_height == -1) || (node2_height == -1)) {
        cout << "Cannot find LCA" << endl;
    }

    cout << "LCA: " << lca->data << endl;
    cout << "Dist between " << node1 << " and " << node2 << ": " << dist << endl;


    return;
}

void destroyTree(Node* root) {
    if(root) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

int main() {
    Node* root = constructTree();
    nodeDistance(root, 4, 14);
    destroyTree(root);
    return 0;
}
