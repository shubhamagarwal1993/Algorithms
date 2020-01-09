#include <iostream>
#include <queue>

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

        void destroyTree() {
            if(root == NULL) {
                return;
            }

            Node* root = this->root;
            this->destroyTreeUtil(root);
            root = NULL; 
        }

        void printInorder() {
            Node* root = this->root;
            if(this->root == NULL) {
                cout << "empty root" << endl;
            }
            this->printInorderUtil(root);
            cout << endl;
            return;
        }

        void printInorderUtil(Node* root) {
            if(root == NULL) {
                return;
            }

            printInorderUtil(root->left);
            cout << root->data << " ";
            printInorderUtil(root->right);
        }

        void insertBST(int data) {
            if(this->root == NULL) {
                this->root = new Node(data);
                return;
            }

            // root has some data
            Node* root = this->root;
            this->insertBSTUtil(root, data);
            return;
        }

        void insertLowestLevel(int data) {
            if(this->root == NULL) {
                this->root = new Node(data);
                return;
            }

            // root has some data
            Node* root = this->root;
            this->insertLowestLevelUtil(root, data);
            return;
        }

        void deleteBST(int data) {
            if(this->root == NULL) {
                return;
            }

            // 3 cases
            //  Node to be deleted is leaf
            //  Node to be deleted is only one child
            //  Node to be deleted has two children
            this->deleteBSTUtil(root, data);
            return;
        }

        Node* deleteBSTUtil(Node* root, int data) {
            if(root == NULL) {
                return NULL;
            }

            // If left node is the node to be deleted
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
                    temp->right = deleteBSTUtil(root->right, temp->data);
                    return root;
                }
            }

            // If right node is the node to be deleted
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
                    temp->right = deleteBSTUtil(root->right, temp->data);
                    return root;
                }
            }

            if(data < root->data) {
                root->left = deleteBSTUtil(root->left, data);
            } else if(data > root->data) {
                root->right = deleteBSTUtil(root->right, data);
            }

            return root;
        }

    private:
        void insertBSTUtil(Node* root, int data) {
            if(root == NULL) {
                root = new Node(data);
                return;
            }

            if((data < root->data) && (root->left == NULL)) {
                root->left = new Node(data);
                return;
            } else if((data > root->data) && (root->right == NULL)) {
                root->right = new Node(data);
                return;
            }

            if(data < root->data) {
                insertBSTUtil(root->left, data);
            } else {
                insertBSTUtil(root->right, data);
            }

            return;
        }

        void insertLowestLevelUtil(Node* root, int data) {
            if(root == NULL) {
                root = new Node(data);
                return;
            }

            queue<Node*> level_order_queue;
            level_order_queue.push(root);

            while(!level_order_queue.empty()) {
                Node* front = level_order_queue.front();
                level_order_queue.pop();

                if(front->left == NULL) {
                    front->left = new Node(data);
                    return;
                } else if(front->right == NULL) {
                    front->right = new Node(data);
                    return;
                }

                level_order_queue.push(front->left);
                level_order_queue.push(front->right);
            }
            return;
        }

        void destroyTreeUtil(Node* root) {
            if(root == NULL) {
                return;
            }

            destroyTreeUtil(root->right);
            destroyTreeUtil(root->left);
            root->left = NULL;
            root->right = NULL;
            delete root;
        }

        Node* getInorderSuccessor(Node* root) {
            if(root == NULL) {
                return NULL;
            }

            while(root->left != NULL) {
                root = root->left;
            }
            return root; 
        }
};

int main() {

    Tree tree;

    tree.insertBST(50);
    tree.insertBST(30);
    tree.insertBST(20);
    tree.insertBST(40);
    tree.insertBST(70);
    tree.insertBST(80);
    tree.printInorder();

    // insert a node at lowerst possible level in the tree
    tree.insertLowestLevel(60);
    tree.printInorder();

    // delete a node
    tree.deleteBST(40);
    tree.printInorder();

    // free memory
    tree.destroyTree();

    return 0;
}
