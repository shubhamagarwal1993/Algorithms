#include <iostream>
#include <vector>

using namespace std;

struct Node{
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

Node* constructTree(int inOrderArr[], int left, int right) {
    if(right < left) {
        return NULL;
    }
    
    int max_val = 0;
    int max_index = 0;

    for(int i = left; i <= right; i++) {
        if(inOrderArr[i] > max_val) {
            max_val = inOrderArr[i];
            max_index = i;
        }
    }

    Node* root = newNode(inOrderArr[max_index]);
    root->left = constructTree(inOrderArr, left, max_index - 1);
    root->right = constructTree(inOrderArr, max_index + 1, right);

    return root;
}

void printTree(Node* root) {
    if(root == NULL) {
        return;
    }

    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

bool treesAreIdentical(Node* main_tree, Node* sub_tree) {
    if(main_tree == NULL && sub_tree == NULL) {
        return true;
    }

    if(sub_tree == NULL) {
        return true;
    }

    if(main_tree == NULL) {
        return false;
    }

    return (main_tree->data == sub_tree->data) 
        && treesAreIdentical(main_tree->left, sub_tree->left)
        && treesAreIdentical(main_tree->right, sub_tree->right);
}

bool checkSubTree(Node* main_tree, Node* sub_tree) {
    if(sub_tree == NULL) {
        return true;
    }

    if(main_tree == NULL) {
        return false;
    }

    if(treesAreIdentical(main_tree, sub_tree)) {
        return true;
    }

    return checkSubTree(main_tree->left, sub_tree)
        || checkSubTree(main_tree->right, sub_tree);
}

void getInOrder(Node* main_tree, vector<int> &inOrder) {
    if(main_tree == NULL) {
        return;
    }

    getInOrder(main_tree->left, inOrder);
    inOrder.push_back(main_tree->data);
    getInOrder(main_tree->right, inOrder);
}

void getPreOrder(Node* main_tree, vector<int> &preOrder) {
    if(main_tree == NULL) {
        return;
    }

    getPreOrder(main_tree->left, preOrder);
    preOrder.push_back(main_tree->data);
    getPreOrder(main_tree->right, preOrder);
}

bool arrayFindSubArray(vector<int> A, vector<int> B) {

    if(B.empty()) {
        return true;
    }

    if(A.empty()) {
        return false;
    }

    int A_index = 0;
    int B_index = 0;
    while(A_index <= A.size()) {

        if(A[A_index] == B[B_index]) {
            if(B_index == B.size() - 1) {
                return true;
            }

            A_index++;
            B_index++;
        } else {
            A_index++;
            B_index = 0;
        }
    }
    return false;
}

int main() {
    int inOrderArr1[] = {1, 5, 10, 40, 30, 15, 28, 20};
    int inOrderArr1Length = sizeof(inOrderArr1)/sizeof(inOrderArr1[0]);
    Node* main_tree = constructTree(inOrderArr1, 0, inOrderArr1Length - 1);
    printTree(main_tree);
    cout << endl;

    int inOrderArr2[] = {30, 15, 28};
    int inOrderArr2Length = sizeof(inOrderArr2)/sizeof(inOrderArr2[0]);
    Node* sub_tree = constructTree(inOrderArr2, 0, inOrderArr2Length - 1);
    printTree(sub_tree);
    cout << endl;

    if(checkSubTree(main_tree, sub_tree)) {
        cout << "Subtree present" << endl;
    } else {
        cout << "Subtree not present" << endl;
    }

    cout << "==================================" << endl;

    vector<int> main_tree_inorder;
    getInOrder(main_tree, main_tree_inorder);

    vector<int> main_tree_preorder;
    getPreOrder(main_tree, main_tree_preorder);

    vector<int> sub_tree_inorder;
    getInOrder(sub_tree, sub_tree_inorder);

    vector<int> sub_tree_preorder;
    getPreOrder(sub_tree, sub_tree_preorder);

    if(arrayFindSubArray(main_tree_inorder, sub_tree_inorder)
    && arrayFindSubArray(main_tree_preorder, sub_tree_preorder)) {
        cout << "found subtree" << endl;
    } else {
        cout << "not found subtree" << endl;
    }

    return 0;
}
