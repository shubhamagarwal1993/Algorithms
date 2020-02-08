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

            // if root is to be deleted
            if(root->data == data) {
                Node* in_order_successor = getInorderSuccessor(root->right);
                root->data = in_order_successor->data;
                root->right = deleteBSTUtil(root->right, in_order_successor->data);
                return root;
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

        void totalNodes() {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;
            cout << "Total nodes in tree: " << totalNodesUtil(root) << endl;
            return;
        }

        void getMaximumWidth() {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;
            int height = getHeight(root);
            vector<int> widthCount;
            for(int i = 0; i < height; i++) {
                widthCount.push_back(0);
            }
            getMaximumWidthHelper(root, widthCount, 0);

            int maxWidth = 0;
            for(int i = 0; i < widthCount.size(); i++) {
                if(widthCount[i] > maxWidth) {
                     maxWidth = widthCount[i];
                }
            }

            cout << "Max width recursively: " << maxWidth << endl;
            return;
        }

        void diameter() {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;

            int sum = 0;
            diameterUtil(root, sum);
            cout << "Diameter: " << sum << endl;
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

        Node* getInorderSuccessor(Node* root) {
            if(root == NULL) {
                return NULL;
            }

            while(root->left != NULL) {
                root = root->left;
            }
            return root; 
        }

        int totalNodesUtil(Node* root) {
            if(root == NULL) {
                return 0;
            }

            return 1 + totalNodesUtil(root->left) + totalNodesUtil(root->right);
        }

        int getHeight(Node* root) {
            if(root == NULL) {
                return 0;
            }

            int lHeight = getHeight(root->left);
            int rHeight = getHeight(root->right);

            return max(lHeight, rHeight) + 1;
        }

        void  getMaximumWidthHelper(Node* root, vector<int> &widthCount, int level) {
            if(root == NULL) {
                return;
            }

            widthCount[level]++;
            getMaximumWidthHelper(root->left, widthCount, level+1);
            getMaximumWidthHelper(root->right, widthCount, level+1);
        }

        int diameterUtil(Node* root, int &sum) {
            if(root == NULL) {
                return 0;
            }

            int left = diameterUtil(root->left, sum);
            int right = diameterUtil(root->right, sum);

            if(left + right + 1 > sum) {
                sum = left + right + 1;
            }
            return std::max(left, right) + 1;
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
    tree.totalNodes();

    // insert a node at lowerst possible level in the tree
    tree.insertLowestLevel(60);
    tree.printInorder();

    // delete a node
    tree.deleteBST(50);
    tree.printInorder();

    // O(N) time and O(N) space
    tree.getMaximumWidth();

    // O(N) time complexity
    tree.diameter();

    // free memory
    tree.destroyTree();

    return 0;
}
