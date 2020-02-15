#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Tree node
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

        void inorder() {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;
            inorderUtil(root);
            cout << endl;
            return;
        }

        void constructTree() {

            vector<int> inorder{5, 10, 20, 50, 51, 55, 60, 65, 70, 80};
            vector<int> levelorder{50, 10, 60, 5, 20, 55, 70, 51, 65, 80};

            int inorder_start = 0;
            int inorder_end = inorder.size() - 1;

            this->root = constructTreeUtil(inorder, levelorder, inorder_start, inorder_end);
            return;
        }

    private:
        void inorderUtil(Node* root) {
            if(root == NULL)
                return;

            inorderUtil(root->left);
            cout << root->data << " ";
            inorderUtil(root->right);
        }

        int search(vector<int> inorder, int in_start, int in_end, int data) {

            for(int i = in_start; i <= in_end; i++) {
                if(data == inorder[i]) {
                    return i;
                }
            }

            return -1;
        }

        vector<int> extractKeys(vector<int> inorder, vector<int> levelorder, int inorder_start, int inorder_end) {
            vector<int> levelorder_new;
            int index = 0;

            for(int i = 0; i < levelorder.size(); i++) {
                int search_idx = search(inorder, inorder_start, inorder_end, levelorder[i]);
                if(search_idx != -1) {
                    levelorder_new.push_back(levelorder[i]);
                }
            }
            return levelorder_new;
        }

        // construct a bst using inorder & levelorder traversals.
        // inorder    - 5, 10, 20, 50, 51, 55, 60, 65, 70, 80
        // levelorder - 50, 10, 60, 5, 20, 55, 70, 51, 65, 80
        //         50
        //      /      \
        //    10        60
        //   /  \       /  \
        //  5   20    55    70
        //            /     /  \
        //          51     65    80
        Node* constructTreeUtil(vector<int> inorder, vector<int>levelorder, int inorder_start, int inorder_end) {

            if(inorder_start > inorder_end) {
                return NULL;
            }

            // The first node in level order traversal is root
            Node* root = new Node(levelorder[0]);
            if(inorder_start == inorder_end) {
                return root;
            }

            // find index of root in inorder array
            // All nodes to left of in_index belong to left subtree, and right to right subtree
            int inorder_index = search(inorder, inorder_start, inorder_end, root->data);
            if(inorder_index == -1) {
                return NULL;
            }

            // separate keys from levelorder traversal in the same order
            vector<int> levelorder_left = extractKeys(inorder, levelorder, inorder_start, inorder_index - 1);
            vector<int> levelorder_right = extractKeys(inorder, levelorder, inorder_index + 1, inorder_end);

            root->left = constructTreeUtil(inorder, levelorder_left, inorder_start, inorder_index - 1);
            root->right = constructTreeUtil(inorder, levelorder_right, inorder_index + 1, inorder_end);

            return root;
        }

        bool in_vector(vector<int> vec, int data) {
            if(std::count(vec.begin(), vec.end(), data)) {
                return true;
            }

            return false;
        }
};

int main() {
    Tree tree;
    tree.constructTree();
    tree.inorder();

    return 0;
}

