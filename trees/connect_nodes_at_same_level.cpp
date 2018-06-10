#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};

Node* newNode(int data) {
    Node* root = new Node();
    root->data = data;
    root->right = NULL;
    root->left = NULL;
    // Do not set to NULL - any garbage value
    // We will manually set it to NULL in the code
    //root->nextRight = NULL;
    return root;
}

Node* constructTree() {
    Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);

    root->left->left = newNode(3);

    return root;
}

// This function returns the leftmost child of nodes at the same level as p
// This function is used to get nextRight of p's right child
// If right child of is NULL then this can also be used for the left child
Node* getNextRight(Node* root) {

    Node* temp = root->nextRight;
 
    // Traverse nodes at root's level and return the first node's first child
    while(temp != NULL) {
        if(temp->left != NULL) {
            return temp->left;
        } else if(temp->right != NULL) {
            return temp->right;
        } else {
            temp = temp->nextRight;
        }
    }
 
    // If all the nodes at p's level are leaf nodes then return NULL
    return NULL;
}

void connectLevelRecursiveUtil(Node* root) {
    if(root == NULL) {
        return;
    }

    // set nextRight of children of current level
    if(root->nextRight) {
        connectLevelRecursiveUtil(root->nextRight);
    }

    if(root->left) {
        if(root->right) {
            root->left->nextRight = root->right;
        } else {
            root->left->nextRight = getNextRight(root);
        }
        connectLevelRecursiveUtil(root->left);
    }

    if(root->right) {
        root->right->nextRight = getNextRight(root);
        connectLevelRecursiveUtil(root->right);
    } else {
        connectLevelRecursiveUtil(getNextRight(root));
    }
}

void connectLevelRecursive(Node* root) {
    if(root == NULL) {
        return;
    }

    // Set nextRight of root
    root->nextRight = NULL;
    connectLevelRecursiveUtil(root);
}

void connectLevelIter(Node* root) {
    if(root == NULL) {
        return;
    }

    // set nextRight of root
    root->nextRight = NULL;
    if(root->left) {
        root->left->nextRight = root->right;
    }

    // set nextRight of all levels one by one
    while(root != NULL) {

        Node* temp = root;

        // set nextRight for children of root and nodes on root's level
        while(temp) {
            if(root->left) {
                if(root->right) {
                    root->left->nextRight = root->right;
                } else {
                    root->left->nextRight = getNextRight(root);
                }
            }
            if(root->right) {
                root->right->nextRight = getNextRight(root);
            }

            temp = temp->nextRight;
        }

        // start from next level - find first children of current level
        if(root->left) {
            root = root->left;
        } else if(root->right) {
            root = root->right;
        } else {
            root = getNextRight(root);
        }
    }
}

int main() {
    Node* root = constructTree();
    connectLevelIter(root);
    connectLevelRecursive(root);
    return 0;
}
