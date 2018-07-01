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

        void printInOrder(Node* root) {
            if(root == NULL) {
                return;
            }

            printInOrder(root->left);
            cout << root->data << " ";
            printInOrder(root->right);
        }

        int getHeight(Node* root) {
            if(root == NULL) {
                return 0;
            }

            int lHeight = getHeight(root->left);
            int rHeight = getHeight(root->right);

            return std::max(lHeight, rHeight) + 1;
        }

        int getWidthAtLevel(Node* root, int level) {
            if(root == NULL) {
                return 0;
            }

            if(level == 1) {
                return 1;
            }

            return getWidthAtLevel(root->left, level - 1) + getWidthAtLevel(root->right, level - 1);
        }

        int getMaxWidth(Node* root) {
            if(root == NULL) {
                return -1;
            }

            int height = getHeight(root);

            int max_width = 0;
            for(int level = 1; level <= height; level++) {
                int width = getWidthAtLevel(root, level);
                if(width > max_width) {
                    max_width = width;
                }
            }
            return max_width;
        }

        void  getMaximumWidthHelper(Node* root, vector<int> &widthCount, int level) {
            if(root) {
                widthCount[level]++;
                getMaximumWidthHelper(root->left, widthCount, level+1);
                getMaximumWidthHelper(root->right, widthCount, level+1);
            }
        }

        int getMaximumWidth(Node* root) {
            if(root == NULL) {
                return 0;
            }

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
            return maxWidth;
        }

        ~Tree() {
            cout << "Destroy tree" << endl;
        }
};
 
void help() {
    Tree tree;
    tree.root = tree.constructTree();
    cout << "Inorder Traversal: ";
    tree.printInOrder(tree.root);
    cout << endl;

    // O(n^2) time and O(1) space
    cout << "Max width iteratively: " << tree.getMaxWidth(tree.root) << endl;

    // O(n) time and O(n) space
    cout << "Max width recursively: " << tree.getMaximumWidth(tree.root) << endl;
}

int main() {
    help();
    cout << "after all logic" << endl;
    return 0;
}
