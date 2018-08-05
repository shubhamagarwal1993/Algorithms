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

        Node* constructTree() {
            Node* root = new Node(1);

            root->left = new Node(2);
            root->left->left = new Node(4);
            root->left->right = new Node(5);

            root->right = new Node(3);
            root->right->right = new Node(8);
            root->right->right->left = new Node(6);
            root->right->right->right = new Node(7);
            return root;
        }

        Node* getInorderSuccessor(Node* root) {
            if(root == NULL) {
                return root;
            }

            while(root->left != NULL) {
                root = root->left;
            }
            return root; 
        }

        Node* deleteNodeWithoutAdjustingParentPointers(Node* root, int data) {
            if(root == NULL) {
                return root;
            }

            if(data < root->data) {
                root->left = deleteNodeWithoutAdjustingParentPointers(root->left, data);
            } else if(data > root->data) {
                root->right = deleteNodeWithoutAdjustingParentPointers(root->right, data);
            // We are at the node to delete
            } else {
                // If no child
                if(root->left == NULL && root->right == NULL) {
                    delete root;
                    root = NULL;
                // if no left child, delete root and return right child
                } else if(root->left == NULL) {
                    Node* temp = root->right;
                    delete(root);
                    return temp;
                // if no right child, delete root and retunn left child
                } else if(root->right == NULL) {
                    Node* temp = root->left;
                    delete(root);
                    return temp;
                // Both child
                } else {
                    Node* temp = getInorderSuccessor(root->right);
                    root->data = temp->data;
                    root->right = deleteNodeWithoutAdjustingParentPointers(root->right, root->data);
                }
            }

            return root;
        }

//          1
//         / \
//        2   3
//       / \   \
//      4   5   8
//             / \
//            6   7
        Node* deleteNode(Node* root, int data) {
            if(root == NULL) {
                return root;
            }

            // if root is the node to delete
            if(root->data == data) {
                delete root;
                root = NULL;
                return root;
            }

            return deleteNodeUtil(root, data);
        }

        // root is not the node to check or delete
        Node* deleteNodeUtil(Node* root, int data) {

            Node* temp = root->left;
            if(temp && (temp->data == data)) {
                // If no child
                if(temp->left == NULL && temp->right == NULL) {
                    delete temp;
                    root->left = NULL;
                    return root;
                // if no left child, delete root and return right child
                } else if(temp->left == NULL) {
                    root->left = temp->right;
                    temp->right = NULL;
                    delete(temp);
                    return root;
                // if no right child, delete root and return left child
                } else if(temp->right == NULL) {
                    root->left = temp->left;
                    temp->left = NULL;
                    delete(temp);
                    return root;
                // Both child
                } else {
                    Node* in_order_successor = getInorderSuccessor(temp->right);
                    temp->data = in_order_successor->data;
                    temp->right = deleteNodeUtil(root->right, temp->data);
                    return root;
                }
            }

            temp = root->right;
            if(temp && (temp->data == data)) {
                // If no child
                if(temp->left == NULL && temp->right == NULL) {
                    delete temp;
                    root->right = NULL;
                    return root;
                // if no left child, delete root and return right child
                } else if(temp->left == NULL) {
                    root->right = temp->right;
                    temp->right = NULL;
                    delete(temp);
                    return root;
                // if no right child, delete root and return left child
                } else if(temp->right == NULL) {
                    root->right = temp->left;
                    temp->left = NULL;
                    delete(temp);
                    return root;
                // Both child
                } else {
                    Node* in_order_successor = getInorderSuccessor(temp->right);
                    temp->data = in_order_successor->data;
                    temp->right = deleteNodeUtil(root->right, temp->data);
                    return root;
                }
            }

            if(data < root->data) {
                root->left = deleteNodeUtil(root->left, data);
            } else if(data > root->data) {
                root->right = deleteNodeUtil(root->right, data);
            }

            return root;
        }

        int height(Node* node) {
            if (node == NULL) {
                return 0;
            } else {
                // compute the height of each subtree
                int lheight = height(node->left);
                int rheight = height(node->right);

                // use the larger one
                if (lheight > rheight) {
                    return(lheight+1);
                } else {
                    return(rheight+1);
                }
            }
        }

        // Print nodes at a given level
        void printGivenLevel(Node* root, int level) {
            if (root == NULL) {
                return;
            }

            if (level == 1) {
                cout << root->data << " ";
            } else if (level > 1) {
                printGivenLevel(root->left, level-1);
                printGivenLevel(root->right, level-1);
            }
        }

        //print tree to check
        void printLevelOrder(Node* root) {
            int h = height(root);
            for (int i = 1; i <= h; i++) {
                printGivenLevel(root, i);
                cout << endl;
            }

        }
};

int main() {
    Tree tree;
    tree.root = tree.constructTree();
    tree.printLevelOrder(tree.root);

    cout << "----------" << endl;

    // Delete node in O(n) time - not adjusting parent pointers
//    tree.root = tree.deleteNodeWithoutAdjustingParentPointers(tree.root, 3);

    // Delete node in O(n) time - adjusting parent pointers
    tree.root = tree.deleteNode(tree.root, 3);

    tree.printLevelOrder(tree.root);

    return 0;
}
