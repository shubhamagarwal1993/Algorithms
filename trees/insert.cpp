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

        void destroyTree(Node* root) {
            if(root == NULL) {
                return;
            }

            destroyTree(root->right);
            destroyTree(root->left);
            root->left = NULL;
            root->right = NULL;
            delete root;
        }

        void printInorder(Node* root) {
            if(root == NULL) {
                return;
            }

            printInorder(root->left);
            cout << root->data << " ";
            printInorder(root->right);
        }

        Node* insertBST(Node* root, int data) {
            if(root == NULL) {
                Node* root = new Node(data);
                return root;
            }

            if((data < root->data) && (root->left == NULL)) {
                root->left = new Node(data);
                return root;
            } else if((data > root->data) && (root->right == NULL)) {
                root->right = new Node(data);
                return root;
            }

            if(data < root->data) {
                insertBST(root->left, data);
            } else {
                insertBST(root->right, data);
            }

            return root;
        }

        Node* insertLowestLevel(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }

            queue<Node*> myQ;
            myQ.push(root);

            while(!myQ.empty()) {
                Node* temp = myQ.front();
                myQ.pop();

                if(temp->left == NULL) {
                    temp->left = new Node(data);
                    return root;
                } else if(temp->right == NULL) {
                    temp->right = new Node(data);
                    return root;
                }

                myQ.push(temp->left);
                myQ.push(temp->right);
            }
            return root;
        }
};

int main() {

    Tree tree;

    tree.root = tree.insertBST(tree.root, 50);
    tree.insertBST(tree.root, 30);
    tree.insertBST(tree.root, 20);
    tree.insertBST(tree.root, 40);
    tree.insertBST(tree.root, 70);
    //insertBST(root, 60);
    tree.insertBST(tree.root, 80);

    tree.printInorder(tree.root);
    cout << endl;

    // insert a node at lowerst possible level in the tree
    tree.insertLowestLevel(tree.root, 60);

    tree.printInorder(tree.root);
    cout << endl;

    // free memory
    tree.destroyTree(tree.root);
    tree.root = NULL;

    return 0;
}
