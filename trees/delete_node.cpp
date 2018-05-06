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
}

Node* getInorderSuccessor(Node* root) {
    if(root == NULL) {
        return root;
    }

    while(root->left != NULL) {
        root = root->left;
    }
    return root; 
}

Node* deleteNode(Node* root, int data) {
    if(root == NULL) {
        return root;
    }

    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    // We are at the node to delete
    } else {
        // If no child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        // if no left child, delete root and return right child
        } else if(root->left == NULL) {
            Node* temp = root->right;
            delete(root);
            return temp;
        // if no right child, delete root and retunn left child
        } else if(root->right == NULL) {
            Node* temp = root->left;
            delete(root);
            return temp;
        // Both child
        } else {
            Node* temp = getInorderSuccessor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, root->data);
        }
    }

    return root;
}

int height(Node* node) {
    if ( node == NULL) {
        return 0;
    } else {
        // compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);

        // use the larger one
        if (lheight > rheight) {
            return(lheight+1);
        } else {
            return(rheight+1);
        }
    }
}

// Print nodes at a given level
void printGivenLevel(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    if (level == 1) {
        cout << root->data << " ";
    } else if (level > 1) {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

//print tree to check
void printLevelOrder(Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
        cout << endl;
    }

}

int main() {
    Node* root = constructTree();
    printLevelOrder(root);

    // Delete node in O(n) time
    root = deleteNode(root, 3);
    printLevelOrder(root);

    return 0;
}
