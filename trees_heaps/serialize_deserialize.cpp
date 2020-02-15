#include <iostream>
#include <string>
#include <sstream>
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

        void constructTree() {

            Node* root          = new Node(1);
            root->left          = new Node(2);
            root->right         = new Node(3);
            root->right->left   = new Node(4);
            root->right->right  = new Node(5);
            this->root = root;
            return;
        }

        // inorder as a string
        string getInorderString() {
            if(this->root == NULL) {
                return "";
            }

            Node* root = this->root;
            return getInorderStringUtil(root);
        }

        // preorder as a string
        string getPreorderString() {
            if(this->root == NULL) {
                return "";
            }

            Node* root = this->root;
            string preorder_string = getPreorderStringUtil(root);

            // Remove last comma if it exists
            string preorder_string_formatted = "";
            int preorder_string_size = preorder_string.size();
            if(preorder_string[preorder_string_size - 1] == ',') {
                preorder_string_formatted = preorder_string.substr(0, preorder_string.size()-1);
            } else {
                preorder_string_formatted = preorder_string;
            }

            return preorder_string_formatted;
        }

        void preorder() {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;
            preorderUtil(root);
            cout << endl;
            return;
        }

        string getSerializedTree() {
            if(this->root == NULL) {
                return "";
            }

            string inorder = getInorderString();
            string preorder = getPreorderString();
            if(inorder.empty() || preorder.empty()) {
                return "";
            }

            return inorder + "," + preorder;
        }

        void deserialize(string serializedTree) {
            if(serializedTree.empty()) {
                return;
            }

            // Get inorder string
            vector<int> inorder;
            for(int i = 0; i < serializedTree.length()/2; i++) {
                if(serializedTree[i] != ',') {
                    inorder.push_back(serializedTree[i] - '0');
                }
            }
            int inorder_start = 0;
            int inorder_end = inorder.size() - 1;

            // Get preorder string
            vector<int> preorder;
            for(int i = serializedTree.length()/2; i < serializedTree.length(); i++) {
                if(serializedTree[i] != ',') {
                    preorder.push_back(serializedTree[i] - '0');
                }
            }
            int preorder_idx = 0;

            this->root = deserializeUtil(inorder, preorder, inorder_start, inorder_end, preorder_idx);
            return;
        }

    private:
        string getInorderStringUtil(Node* root) {
            if(root == NULL) {
                return "";
            }

            string left = "";
            if(root->left) {
                left = getInorderStringUtil(root->left);
            }

            string res = to_string(root->data);

            string right = "";
            if(root->right) {
                right = getInorderStringUtil(root->right);
            }

            return (left.empty() ? "" : left + ",") + res + (right.empty() ? "" : "," + right);
        }

        string getPreorderStringUtil(Node* root) {
            if(root == NULL) {
                return "";
            }

            string res = to_string(root->data);

            string left = "";
            if(root->left) {
                left = getPreorderStringUtil(root->left);
            }

            string right = "";
            if(root->right) {
                right = getPreorderStringUtil(root->right);
            }

            return res + "," + (left.empty() ? "" : left) + (right.empty() ? "" : right);
        }

        Node* deserializeUtil(vector<int>inorder, vector<int>preorder, int inorder_start, int inorder_end, int &preorder_idx) {
            if(inorder_start > inorder_end) {
                return NULL;
            }

            Node* root = new Node(preorder[preorder_idx]);
            preorder_idx += 1;

            int inorder_idx = findIdx(inorder, root->data);
            if(inorder_idx == -1) {
                return NULL;
            }

            root->left = deserializeUtil(inorder, preorder, inorder_start, inorder_idx - 1, preorder_idx);
            root->right = deserializeUtil(inorder, preorder, inorder_idx + 1, inorder_end, preorder_idx);
            return root;
        }

        int findIdx(vector<int> vec, int data) {
            for(int i = 0; i < vec.size(); i++) {
                if(vec[i] == data) {
                    return i;
                }
            }

            return -1;
        }

        void preorderUtil(Node* root) {
            if(root == NULL) {
                return;
            }

            cout << root->data << " ";
            preorderUtil(root->left);
            preorderUtil(root->right);
        }
};

int main() {

    Tree tree;
    tree.constructTree();

    string serialized_tree = tree.getSerializedTree();
    tree.deserialize(serialized_tree);
    tree.preorder();
    return 0;
}
