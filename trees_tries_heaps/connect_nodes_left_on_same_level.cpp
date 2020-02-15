#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node* nextLeft;

        // don't set nextLeft to NULL
        // connect nodes logic will do that
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
            Node* root              = new Node(5);

            root->left              = new Node(6);
            root->left->left        = new Node(2);
            root->left->left->right = new Node(3);

            root->right             = new Node(7);
            root->right->left       = new Node(5);
            root->right->left->right= new Node(8);

            return root;
        }

        Node* getNextLeft(Node* root) {
            if(root == NULL) {
                return NULL;
            }

            Node* temp = root->nextLeft;
            while(temp != NULL) {
                if(temp->right) {
                    return temp->right;
                }
                if(temp->left) {
                    return temp->left;
                }
                temp = temp->nextLeft;
            }
            return NULL;
        }

        void connectLevelIter(Node* root) {

            if(root == NULL) {
                return;
            }

            // make nextLeft NULL for root
            root->nextLeft = NULL;

            while(root != NULL) {

                Node* temp = root;

                while(temp != NULL) {
                    // start from the right most child and go left
                    if(temp->right) {
                        if(temp->left) {
                            temp->right->nextLeft = temp->left;
                        } else {
                            temp->right->nextLeft = getNextLeft(temp);
                        }
                    }
                    if(temp->left) {
                        temp->left->nextLeft = getNextLeft(temp);
                    }
                    temp = temp->nextLeft;
                }

                // start assigning elements from left most
                if(root->right) {
                    root = root->right;
                } else if(root->left) {
                    root = root->left;
                } else {
                    root = getNextLeft(root);
                }
            }
        }

        void printTreeLevelOrder(Node* root) {
            if(root == NULL) {
                return;
            }

            while(root != NULL) {

                Node* temp = root;
                cout << temp->data << " ";
                temp = temp->nextLeft;

                while(temp != NULL) {
                    cout << temp->data << " ";
                    temp = temp->nextLeft;
                }
                cout << endl;

                if(root->right) {
                    root = root->right;
                } else if(root->left) {
                    root = root->left;
                } else {
                    root = getNextLeft(root);
                }
            }
        }

        void inOrder(Node* root) {
            if(root == NULL) {
                return;
            }

            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
};

int main() {
    Tree tree;
    tree.root = tree.constructTree();

    cout << " ====  Inorder ==== " << endl;
    tree.inOrder(tree.root);
    cout << endl << endl;

    cout << " ====  Connect Iter ==== " << endl;
    tree.connectLevelIter(tree.root);
    tree.printTreeLevelOrder(tree.root);
    cout << endl;

    return 0;
}

