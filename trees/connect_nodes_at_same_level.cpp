#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node* nextRight;

        // Do not set nextRight to NULL - any garbage value
        // We will manually set it to NULL in the code
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
            Node* root = new Node(10);
            root->left = new Node(8);
            root->right = new Node(2);

            root->left->left = new Node(3);
            root->left->right = new Node(1);

            root->right->left = new Node(6);
            root->right->right = new Node(7);

            return root;
        }

        // This function returns the leftmost child of nodes at the same level as p
        // This function is used to get nextRight of p's right child
        // If right child of is NULL then this can also be used for the left child
        Node* getNextRight(Node* root) {

            Node* temp = root->nextRight;

            // Traverse nodes at root's level and return the first node's first child
            while(temp != NULL) {
                if(temp->left != NULL) {
                    return temp->left;
                }
                if(temp->right != NULL) {
                    return temp->right;
                }
                temp = temp->nextRight;
            }

            // If all the nodes at p's level are leaf nodes then return NULL
            return NULL;
        }

        void connectLevelIter(Node* root) {
            if(root == NULL) {
                return;
            }

            // set nextRight of root
            root->nextRight = NULL;

            // set nextRight of all levels one by one
            while(root) {

                Node* temp = root;

                // set nextRight for children of root and nodes on root's level
                while(temp) {
                    if(temp->left) {
                        if(temp->right) {
                            temp->left->nextRight = temp->right;
                        } else {
                            temp->left->nextRight = getNextRight(temp);
                        }
                    }
                    if(temp->right) {
                        temp->right->nextRight = getNextRight(temp);
                    }

                    temp = temp->nextRight;
                }

                // start from next level - find first children of current level
                if(root->left) {
                    root = root->left;
                } else if(root->right) {
                    root = root->right;
                } else {
                    root = getNextRight(root);
                }
            }
        }

        void connectLevelRecursiveUtil(Node* root) {
            if(root == NULL) {
                return;
            }

            // set nextRight of children of current level
            if(root->nextRight) {
                connectLevelRecursiveUtil(root->nextRight);
            }

            if(root->left) {
                if(root->right) {
                    root->left->nextRight = root->right;
                } else {
                    root->left->nextRight = getNextRight(root);
                }
                connectLevelRecursiveUtil(root->left);
            }

            if(root->right) {
                root->right->nextRight = getNextRight(root);
                connectLevelRecursiveUtil(root->right);
            } else {
                connectLevelRecursiveUtil(getNextRight(root));
            }
        }

        void connectLevelRecursive(Node* root) {
            if(root == NULL) {
                return;
            }

            // Set nextRight of root
            root->nextRight = NULL;
            connectLevelRecursiveUtil(root);
        }

        void printTreeLevelOrder(Node* root) {
            if(root == NULL) {
                return;
            }

            while(root) {

                Node* temp = root;
                cout << temp->data << " ";
                temp = temp->nextRight;

                while(temp) {
                    cout << temp->data << " ";
                    temp = temp->nextRight;
                }
                cout << endl;

                if(root->left) {
                    root = root->left;
                } else if(root->right) {
                    root = root->right;
                } else {
                    root = getNextRight(root);
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

    cout << " ====  Connect Recursive ==== " << endl;
    tree.connectLevelRecursive(tree.root);
    tree.printTreeLevelOrder(tree.root);
    cout << endl;

    return 0;
}

