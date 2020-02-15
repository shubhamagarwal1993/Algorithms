#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

//tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

//constructor for new node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void construct_min_heap(Node* Tree1) {
    Tree1->left               = newNode(50);
    Tree1->right              = newNode(7);

    Tree1->left->left         = newNode(55);
    Tree1->left->right        = newNode(90);

    Tree1->right->left        = newNode(87);

//         4
//        / \
//       /   \
//      50    7
//     / \   /
//    55 90 87
    return;
}

void level_order_traversal(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> myqueue;
    myqueue.push(root);
    int count = 0;

    while(!myqueue.empty()) {

        count = myqueue.size();

        while(count > 0) {
            Node* curr_node = myqueue.front();
            cout << curr_node->data << " ";
            myqueue.pop();

            if(curr_node->left != NULL) {
                myqueue.push(curr_node->left);
            }

            if(curr_node->right != NULL) {
                myqueue.push(curr_node->right);
            }
            count--;
        }
        cout << endl;
    }
}

void min_heap_insert(Node* root, Node* newVal) {

    if(root->right != NULL) {
        min_heap_insert(root->right, newVal);
    }

    if(root->right == NULL) {
        root->right = newVal;
    }

    if(root->right->data < root->data) {
        int temp = root->data;
        root->data = root->right->data;
        root->right->data = temp;
    }
}

void boilDown(Node* root) {
    int left = root->data;
    int right = root->data;

    if(root->left != NULL && root->left->data < root->data) {
        left = root->left->data;
    }
    if(root->right != NULL && root->right->data < root->data) {
        right = root->right->data;
    }
    if((left < right) && (root->left->data < root->data)) {
        int temp = root->data;
        root->data = root->left->data;
        root->left->data = temp;
        boilDown(root->left);
    } else if((right < left) && (root->right->data < root->data)) {
        int temp = root->data;
        root->data = root->right->data;
        root->right->data = temp;
        boilDown(root->right);
    } else {
        return;
    }
}

void min_heap_remove_min(Node *root) {
    if(root == NULL) {
        return;
    }

    Node* pointer = root;
    while(pointer->right->right != NULL) {
        pointer = pointer->right;
    }
    int temp = pointer->right->data;

    root->data = temp;
    delete pointer->right;
    pointer->right = NULL;

    boilDown(root);
}

int main() {

    // Make a tree - we will call it Tree1
    Node* Tree1 = newNode(4);
    construct_min_heap(Tree1);

    // Print tree
    cout << "level order traversal: " << endl;
    level_order_traversal(Tree1);

    // insert element into min heap
    Node* temp = newNode(3);
    min_heap_insert(Tree1, temp);
    cout << endl;

    // Print tree
    cout << "level order traversal: " << endl;
    level_order_traversal(Tree1);

    // extract minimum element from min heap
    min_heap_remove_min(Tree1);
    cout << endl;

    // Print tree
    cout << "level order traversal: " << endl;
    level_order_traversal(Tree1);

    return 0;
}
