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

        int height(Node* node) {
            if(node == NULL) {
                return 0;
            }
            
            // compute the height of each subtree
            int lheight = height(node->left);
            int rheight = height(node->right);

            // use the larger one
            return max(lheight, rheight) + 1;
        }

        // Print nodes at a given level
        void printGivenLevel(Node* root, int level) {
            if(root == NULL)
                return;

            if(level == 1)
                cout << root->data << " ";

            else if(level > 1) {
                printGivenLevel(root->left, level-1);
                printGivenLevel(root->right, level-1);
            }
        }

        //print tree to check
        void printLevelOrder(Node* root) {
            int h = height(root);
            for(int i = 1; i <= h; i++)
                printGivenLevel(root, i);
        }

        void in_order(Node* root) {
            if(root == NULL)
                return;

            in_order(root->left);
            cout << root->data << " ";
            in_order(root->right);
        }

        int search(int inorder[], int in_start, int in_end, int data) {

            for(int i = in_start; i <= in_end; i++) {
                if(data == inorder[i]) {
                    return i;
                }
            }

            return -1;
        }

        int *extractKeys(int inorder[], int levelorder[], int in_index, int size) {
            int *arr = new int [in_index];
            int j = 0;
            for(int i = 0; i < size; i++) {
                if(search(inorder, 0, in_index-1, levelorder[i]) != -1) {
                    arr[j] = levelorder[i];
                    j++;
                }
            }

            return arr;
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
        Node* construct_tree(int inorder[], int levelorder[], int in_start, int in_end, int size, int &level_index) {

            if(in_start > in_end) {
                return NULL;
            }

            // The first node in level order traversal is root
            Node* root = new Node(levelorder[level_index]);
            level_index++;

        //    if(in_start == in_end) {
        //        return root;
        //    }

            // find index of root in inorder array
            int in_index = search(inorder, in_start, in_end, root->data);
            if(in_index == -1) {
                return NULL;
            }

            // separate left keys from level order traversal - return an array
        //    int *left_index = extractKeys(inorder, levelorder, in_index, size);

            // separate right keys from level order traversal - return an array
        //    int *right_index = extractKeys(inorder + in_index + 1, levelorder, size - in_index - 1, size);

            //using in_index from inorder array, constructing left & right subtrees.
        //    root->left  = construct_tree(inorder, left_index, in_start, in_index-1, size);
        //    root->right = construct_tree(inorder, right_index, in_index+1, in_end, size);

            root->left  = construct_tree(inorder, levelorder, in_start, in_index-1, size, level_index);
            root->right = construct_tree(inorder, levelorder, in_index+1, in_end, size, level_index);
        //    delete [] left_index;
        //    delete [] right_index;

            return root;
        }
};

int main() {

    int inorder[10] = {5, 10, 20, 50, 51, 55, 60, 65, 70, 80};
    int levelorder[10] = {50, 10, 60, 5, 20, 55, 70, 51, 65, 80};
    int size = sizeof(inorder)/sizeof(inorder[0]);
    int in_start = 0;
    int in_end = size - 1;
    int level_index = 0;

    Tree tree;
    tree.root = tree.construct_tree(inorder, levelorder, in_start, in_end, size, level_index);
    tree.in_order(tree.root);
    cout << endl;

    return 0;
}

