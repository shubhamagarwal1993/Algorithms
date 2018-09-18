#include <iostream>
#include <vector>

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

        //       1
        //      / \
        //     /   \
        //    2     3
        //   / \     \
        //  4   5     8
        //           / \
        //          6   7
        Node* constructTree() {
            Node* root = new Node(1);

            root->left = new Node(2);
            root->left->left = new Node(4);
            root->left->right = new Node(5);

            root->right = new Node(3);
            root->right->right = new Node(8);
            root->right->right->left = new Node(6);
            root->right->right->right = new Node(7);


            //Node* root = new Node(1);
            //root->left = new Node(2);
            //root->left->left = new Node(4);
            //root->right = new Node(3);
            return root;
        }

        void findDeepestValue(Node* root) {
            int max_level = 0;
            int curr_level = 0;
            int result = 0;

            findDeepestValueUtil(root, curr_level, max_level, result);
            cout << result << endl;
            return;
        }

        void findDeepestValueUtil(Node* root, int curr_level, int &max_level, int &result) {

            if(root == NULL) {
                return;
            }

            if((root->right == NULL) && (root->left == NULL)) {
                if(curr_level > max_level) {
                    max_level = curr_level;
                    result = root->data;
                }
            }

            findDeepestValueUtil(root->right, curr_level + 1, max_level, result);
            findDeepestValueUtil(root->left, curr_level + 1, max_level, result);
        }
};

int main() {
    Tree tree;
    tree.root = tree.constructTree();
    tree.findDeepestValue(tree.root);

    return 0;
}
