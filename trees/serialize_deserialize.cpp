#include <iostream>
#include <string>
#include <sstream>

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
    Node* root          = newNode(1);
    root->left          = newNode(2);
    root->right         = newNode(3);
    root->right->left   = newNode(4);
    root->right->right  = newNode(5);
    return root;
}

void getInOrder(Node* root, string &inOrder) {
    if(root == NULL) {
        return;
    }

    getInOrder(root->left, inOrder);
    if(!inOrder.empty()) {
        inOrder = inOrder + "," + to_string(root->data);
    } else {
        inOrder = to_string(root->data);
    }
    getInOrder(root->right, inOrder);
}

void getPreOrder(Node* root, string &preOrder) {
    if(root == NULL) {
        return;
    }

    if(!preOrder.empty()) {
        preOrder = preOrder + "," + to_string(root->data);
    } else {
        preOrder = to_string(root->data);
    }
    getPreOrder(root->left, preOrder);
    getPreOrder(root->right, preOrder);
}

string serialize(Node* root) {
    string inOrder = "";
    getInOrder(root, inOrder);

    string preOrder = "";
    getPreOrder(root, preOrder);

    return inOrder + "," + preOrder;;
}

Node* getBackTree(int inOrder[], int inOrder_l, int inOrder_r, int preOrder[], int &preOrder_index) {

    if(inOrder_l > inOrder_r) {
        return NULL;
    }

    int data = preOrder[preOrder_index];
    Node* root = newNode(data);
    preOrder_index++;

    // find index from inorder
    int k = -1;
    for(int i = inOrder_l; i <= inOrder_r; i++) {
        if(root->data == inOrder[i]) {
            k = i;
            break;
        }
    }

    root->left  = getBackTree(inOrder, inOrder_l, k - 1, preOrder, preOrder_index);
    root->right = getBackTree(inOrder, k + 1, inOrder_r, preOrder, preOrder_index);
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
        cout << "X" << " ";
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

int getNodeCount(string serializedTree) {

    int len = 0;
    for(int i = 0; i < serializedTree.length(); i++) {
        if(serializedTree[i] == ',') {
            len = len + 1;
        }
    }

    return (len == 0) ? len : len + 1;
}

void deserialize(string serializedTree) {

    int treeLength = getNodeCount(serializedTree);

    int* inOrder = new int[treeLength/2];
    int inOrder_index = 0;
    int* preOrder = new int[treeLength/2];
    int preOrder_index = 0;

    string word;
    int st_index = 0;
    cout << serializedTree << endl;
    while(inOrder_index < treeLength/2) {
        if(serializedTree[st_index] == ',') {
            inOrder[inOrder_index] = stoi(word);
            word = "";
            inOrder_index++;
        } else if(st_index == serializedTree.length()) {
            inOrder[inOrder_index] = stoi(word);
            word = "";
            inOrder_index++;
        } else {
            word = word + serializedTree[st_index];
        }
        st_index++;
    }

    while(preOrder_index < treeLength/2) {
        if(serializedTree[st_index] == ',') {
            preOrder[preOrder_index] = stoi(word);
            word = "";
            preOrder_index++;
        } else if(st_index + 1 == serializedTree.length()) {
            word = word + serializedTree[st_index];
            preOrder[preOrder_index] = stoi(word);
            word = "";
            preOrder_index++;
        } else {
            word = word + serializedTree[st_index];
        }
        st_index++;
    }

    preOrder_index = 0;
    Node* root = getBackTree(inOrder, 0, treeLength/2 - 1, preOrder, preOrder_index);
    cout << "=======================" << endl;
    printLevelOrder(root);
    cout << "=======================" << endl;
    return;
}

int main() {

    Node* root = constructTree();

    string serializedTree = serialize(root);
    deserialize(serializedTree);
    return 0;
}
