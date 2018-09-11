// The Diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes

#include <iostream>

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

class Tree {
    public:
        Node* root;

        Tree() {
            this->root = NULL;
        }

        Node* constructTree() {
            Node* root = new Node(8);

            // 4 including root
            root->left = new Node(3);
            root->left->left = new Node(1);
            root->left->right = new Node(6);
            root->left->right->left = new Node(4);
            root->left->right->right = new Node(7);

            // 3 excluding root
            root->right = new Node(12);
            root->right->left = new Node(11);
            root->right->right = new Node(15);
            root->right->right->left = new Node(14);

            return root;
        }

        // O(N) time complexity
        int diameter(Node* root, int &sum) {
            if(root == NULL) {
                return 0;
            }

            int left = diameter(root->left, sum);
            int right = diameter(root->right, sum);

            if(left + right + 1 > sum) {
                sum = left + right + 1;
            }
            return std::max(left, right) + 1;
        }

        int getHeight(Node* root) {
            if(root == NULL) {
                return 0;
            }

            int lHeight = getHeight(root->left);
            int rHeight = getHeight(root->right);
            return max(lHeight, rHeight) + 1;
        }

        // O(N^2) time complexity
        int diameter(Node* root) {
            if(root == NULL) {
                return 0;
            }

            int leftHeight = getHeight(root->left);
            int rightHeight = getHeight(root->right);

            int leftDiameter = diameter(root->left);
            int rightDiameter = diameter(root->right);

            return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
        }

};

int main() {
    Tree tree;
    tree.root = tree.constructTree();

    int sum = 0;
    tree.diameter(tree.root, sum);
    cout << "Diameter: " << sum << endl;
    cout << tree.diameter(tree.root) << endl;

    return 0;
}

