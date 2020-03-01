/*
 * Given an array, sort using inorder recursion
 *
 * Steps:
 * - Create binary search tree from given array
 * - Perform an inorder traversal on new tree
 */
 
#include <iostream>
using namespace std;

class Node {
    public:
        Node* left;
        Node* right;
        int data;
        
        Node(int data) {
            this->left = NULL;
            this->right = NULL;
            this->data = data;
        }
};

class TreeSort {
    public:
        Node* root;

        TreeSort() {
            this->root = NULL;
        }

        void printInorder(Node* root) {
            if(root == NULL) {
                return;
            }

            printInorder(root->left);
            cout << root->data << " ";
            printInorder(root->right);
        }

        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }

            if(data <= root->data) {
                root->left = insert(root->left, data);
            } else if(data > root->data) {
                root->right = insert(root->right, data);
            }

            return root;
        }

        Node* treeSort(int arr[], int arr_size) {
            if(arr_size <= 0) {
                return NULL;
            }

            Node* root = NULL;
            root = insert(root, arr[0]);
            for(int i = 1; i < arr_size; i++) {
                insert(root, arr[i]);
            }

            return root;
            // return printInorder(root);
        }
};

int main() {
    int arr[] = {3, 7, 2, 9, 4};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    TreeSort tree;
    Node* root = tree.treeSort(arr, arr_size);
    tree.printInorder(root);
    cout << endl;

    return 0;
}
