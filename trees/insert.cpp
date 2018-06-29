#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

};

Node* newNode(int data) {
    Node* root = new Node(data);
    return root;
}

void destroyTree(Node* root) {
    if(root == NULL) {
        return;
    }

    destroyTree(root->right);
    destroyTree(root->left);
    root->left = NULL;
    root->right = NULL;
    delete root;
}

void printInorder(Node* root) {
    if(root == NULL) {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

Node* insertBST(Node* root, int data) {
    if(root == NULL) {
        Node* root = newNode(data);
        return root;
    }

    if((data < root->data) && (root->left == NULL)) {
        root->left = newNode(data);
        return root;
    } else if((data > root->data) && (root->right == NULL)) {
        root->right = newNode(data);
        return root;
    }

    if(data < root->data) {
        insertBST(root->left, data);
    } else {
        insertBST(root->right, data);
    }

    return root;
}

Node* insertLowestLevel(Node* root, int data) {
    if(root == NULL) {
        return newNode(data);
    }

    queue<Node*> myQ;
    myQ.push(root);

    while(!myQ.empty()) {
        Node* temp = myQ.front();
        myQ.pop();

        if(temp->left == NULL) {
            temp->left = newNode(data);
            return root;
        } else if(temp->right == NULL) {
            temp->right = newNode(data);
            return root;
        }

        myQ.push(temp->left);
        myQ.push(temp->right);
    }
    return root;
}

int main() {
    Node* root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    //insertBST(root, 60);
    insertBST(root, 80);

    printInorder(root);
    cout << endl;

    // insert a node at lowerst possible level in the tree
    insertLowestLevel(root, 60);

    printInorder(root);
    cout << endl;

    // free memory
    destroyTree(root);
    root = NULL;

    return 0;
}
