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

    // free memory
    tree.destroyTree();

    return 0;
}
