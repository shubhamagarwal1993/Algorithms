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

int getHeight(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int lHeight = getHeight(root->left);
    int rHeight = getHeight(root->right);

    return std::max(lHeight, rHeight) + 1;
}

int getWidthAtLevel(Node* root, int level) {
    if(root == NULL) {
        return 0;
    }

    if(level == 1) {
        return 1;
    }

    return getWidthAtLevel(root->left, level - 1) + getWidthAtLevel(root->right, level - 1);
}

int getMaxWidth(Node* root) {
    if(root == NULL) {
        return -1;
    }

    int height = getHeight(root);

    int max_width = 0;
    for(int level = 1; level <= height; level++) {
        int width = getWidthAtLevel(root, level);
        if(width > max_width) {
            max_width = width;
        }
    }
    return max_width;
}

void  getMaximumWidthHelper(Node* root, vector<int> &widthCount, int level) {
    if(root) {
        widthCount[level]++;
        getMaximumWidthHelper(root->left, widthCount, level+1);
        getMaximumWidthHelper(root->right, widthCount, level+1);
    }
}

int getMaximumWidth(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int height = getHeight(root);
    vector<int> widthCount;
    for(int i = 0; i < height; i++) {
        widthCount.push_back(0);
    }
    getMaximumWidthHelper(root, widthCount, 0);

    int maxWidth = 0;
    for(int i = 0; i < widthCount.size(); i++) {
        if(widthCount[i] > maxWidth) {
             maxWidth = widthCount[i];
        }
    }
    return maxWidth;
}

int main() {
    Node* root = constructTree();
    // O(n^2) time and O(1) space
    cout << getMaxWidth(root) << endl;

    // O(n) time and O(n) space
    cout << getMaximumWidth(root) << endl;
    return 0;
}
