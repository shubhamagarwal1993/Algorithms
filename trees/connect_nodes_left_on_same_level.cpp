#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* nextLeft;
};

Node* newNode(int data) {
    Node* root = new Node();
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    // leave nextLeft garbage value
    return root;
}

Node* constructTree() {
    Node* root              = newNode(5);

    root->left              = newNode(6);
    root->left->left        = newNode(2);
    root->left->left->right = newNode(3);

    root->right             = newNode(7);
    root->right->left       = newNode(5);
    root->right->left->right= newNode(8);

    return root;
}

Node* getNextLeft(Node* root) {
    if(root == NULL) {
        return NULL;
    }

    Node* temp = root->nextLeft;
    while(temp != NULL) {
        if(temp->right) {
            return temp->right;
        } else if(temp->left) {
            return temp->left;
        } else {
            temp = temp->nextLeft;
        }
    }
    return NULL;
}

void connectLevelIter(Node* root) {

    if(root == NULL) {
        return;
    }

    // make nextLeft NULL for root
    root->nextLeft = NULL;

    while(root != NULL) {

        Node* temp = root;

        while(temp != NULL) {
            // start from the right most child and go left
            if(temp->right) {
                if(temp->left) {
                    temp->right->nextLeft = temp->left;
                } else {
                    temp->right->nextLeft = getNextLeft(temp);
                }
            }
            if(temp->left) {
                temp->left->nextLeft = getNextLeft(temp);
            }
            temp = temp->nextLeft;
        }

        // start assigning elements from left most
        if(root->right) {
            root = root->right;
        } else if(root->left) {
            root = root->left;
        } else {
            root = getNextLeft(root);
        }
    }
}

void printTreeLevelOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    while(root != NULL) {

        Node* temp = root;
        cout << temp->data << " ";
        temp = temp->nextLeft;

        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->nextLeft;
        }
        cout << endl;

        if(root->right) {
            root = root->right;
        } else if(root->left) {
            root = root->left;
        } else {
            root = getNextLeft(root);
        }
    }
}

int main() {
    Node* root = constructTree();
    connectLevelIter(root);
    printTreeLevelOrder(root);
    return 0;
}
