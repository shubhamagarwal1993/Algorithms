/*
 * Inverting a binary tree is basically making it's mirror image
 *
 * Running Time: O(n) since all nodes are touched just once
 * Space Complexity: O(1) since no extra space is used, other than a pointer
 */
#include <iostream>

class Node {
    private:

    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->left = NULL;
            this->right = NULL;
            this->data = data;
        }
};

class Tree {
    private:
        Node* root;

    Node* invertUtil(Node* root) {
        if(root == NULL) {
            return NULL;
        }

        invertUtil(root->left);
        invertUtil(root->right);

        // both children exist
        if(root->left != NULL && root->right != NULL) {
            Node* temp = root->left;
            root->left = root->right;
            root->right = temp;
        } else if(root->left != NULL) {
        // left child exists
            root->right = root->left;
            root->left = NULL;
        } else if(root->right != NULL) {
        // right child exists
            root->left = root->right;
            root->right = NULL;
        }
        return root;
    }

    void inorderPrintUtil(Node* root) {
        if(root == NULL) {
            return;
        }

        inorderPrintUtil(root->left);
        std::cout << root->data << " ";
        inorderPrintUtil(root->right);
    }

    public:
        Tree() {
            this->root = NULL;
        }

        void constructTree() {
            Node* root = new Node(2);
            root->left = new Node(1);
            root->right = new Node(4);
            root->right->left = new Node(3);
            root->right->right = new Node(5);
            this->root = root;
            return;
        }

        Node* invert() {
            if(this->root == NULL) {
                return NULL;
            }

            Node* root = this->root;

            Node* root_invert = invertUtil(root);
            inorderPrintUtil(root_invert);
            std::cout << std::endl;

            return root_invert;
        }

        void inorderPrint() {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;
            inorderPrintUtil(root);
            std::cout << std::endl;
            return;
        }
};

int main() {
    Tree t;
    t.constructTree();
    t.inorderPrint();
    Node* t_inverted = t.invert();

    return 0;
}
