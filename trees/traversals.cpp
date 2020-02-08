#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Tree node
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right=NULL;
        }
};

class Tree {
    public:
        Node* root;

        Tree() {
            this->root = NULL;
        }

        void construct() {
            //           1
            //          / \
            //         /   \
            //        /     \
            //       /       \
            //      /         \
            //    10           3
            //   /  \         / \
            //  /    \       /   \
            // 4      6     2     9
            //  \    / \   / \   / \
            //  30  0   5 21  8 7  11

            Node* root               = new Node(1);
            root->left               = new Node(10);
            root->right              = new Node(3);

            root->left->left         = new Node(4);
            root->left->right        = new Node(6);

            root->right->left        = new Node(2);
            root->right->right       = new Node(9);

            root->left->left->right  = new Node(30);
            root->left->right->left  = new Node(0);
            root->left->right->right = new Node(5);

            root->right->left->left  = new Node(21);
            root->right->left->right = new Node(8);
            root->right->right->left = new Node(7);
            root->right->right->right= new Node(11);

            this->root = root;
            return;
        }

        void inorderRecursive() {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;
            cout << "Inorder Recursive:";
            inorderRecursiveUtil(root);
            cout << endl;
            return;
        }

        void inorderRecursiveString() {
            if(root == NULL) {
                return;
            }

            Node* root = this->root;
            cout << "Inorder Recurisve string: " << inorderRecursiveStringUtil(root) << endl;
            return;
        }

        void inorderIterative() {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;
            cout << "Inorder Iterative:";
            inorderIterativeUtil(root);
            cout << endl;
            return;
        }

        void preorderRecursive() {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;
            cout << "Preorder Recursive:";
            preorderRecursiveUtil(root);
            cout << endl;
            return;
        }

        void preorderIterative() {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;
            cout << "Preorder Iterative:";
            preorderIterativeUtil(root);
            cout << endl;
        }

        void postorderRecursive() {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;
            cout << "Postorder Recursive:";
            postorderRecursiveUtil(root);
            cout << endl;
        }

        // Postorder iterative is the hardest traversal out of inorder, and preorder
        // Node* prev: keep track of the previously traversed node
        // Node* curr: current node that’s on top of the stack
        //
        // When prev is curr‘s parent:
        //         we are traversing down the tree
        //         In this case, we try to traverse to curr‘s left child if available (push left child to stack)
        //         If it is not available, we look at curr‘s right child
        //         If both left and right child do not exist (curr is a leaf node), print curr and pop it off stack
        //
        // When prev is curr's left child:
        //         we are traversing up the tree from the left
        //         look at curr‘s right child. If available, then traverse down right child (push right child to stack)
        //         If not available, print curr and pop it off stack
        //
        // When prev is curr‘s right child:
        //         we are traversing up the tree from the right
        //         print curr and pop it off stack
        void postorderIterative() {
            if(this->root == NULL) {
                return;
            }

            Node* root = this->root;
            cout << "Postorder Iterative:";
            postorderIterativeUtil(root);
            cout << endl;
            return;
        }

        //print tree to check
        void levelOrderRecursive(Node* root) {
            int h = height(root);
            for (int i = 1; i <= h; i++) {
                printGivenLevel(root, i);
            }
        }

        void levelOrderIterative(Node* root) {
            if(root == NULL) {
                return;
            }

            queue<Node*> myqueue;
            myqueue.push(root);
            int count = 0;

            while(!myqueue.empty()) {
                count = myqueue.size();
                while(count > 0) {
                    Node* temp = myqueue.front();
                    myqueue.pop();
                    cout << temp->data << " ";

                    if(temp->left != NULL) {
                        myqueue.push(temp->left);
                    }

                    if(temp->right != NULL) {
                        myqueue.push(temp->right);
                    }
                    count--;
                }
                cout << "| ";
            }
        }

        void reverseLevelOrderIterative(Node* root) {

            if(root == NULL) {
                return;
            }

            vector<Node*> vec;
            vec.push_back(root);
            queue<Node*> myqueue;
            myqueue.push(root);
            int count = 0;

            while(!myqueue.empty()) {
                count = myqueue.size();
                while(count > 0) {
                    Node* temp = myqueue.front();
                    myqueue.pop();

                    if(temp->left != NULL) {
                        myqueue.push(temp->left);
                        vec.push_back(temp->left);
                    }

                    if(temp->right != NULL) {
                        myqueue.push(temp->right);
                        vec.push_back(temp->right);
                    }
                    count--;
                }
            }

            reverse(vec.begin(), vec.end());
            for(int i = 0; i < vec.size(); i++) {
                cout << vec[i]->data << " ";
            }
        }
    private:
        void inorderRecursiveUtil(Node* root) {
            if(root == NULL) {
                return;
            }

            inorderRecursiveUtil(root->left);
            cout << root->data << " ";
            inorderRecursiveUtil(root->right);
        }

        string inorderRecursiveStringUtil(Node* root) {
            if(root == NULL) {
                return "";
            }

            string left = "";
            if(root->left) {
                left = inorderRecursiveStringUtil(root->left);
            }

            string ans = to_string(root->data);

            string right = "";
            if(root->right) {
                right = inorderRecursiveStringUtil(root->right);
            }

            return (left.empty() ? "" : left + " ") + ans + (right.empty() ? "" : " " + right);
        }

        void inorderIterativeUtil(Node* root) {
            if(root == NULL) {
                return;
            }

            stack<Node*> s;
            s.push(root);

            while(!s.empty()) {
                if(root->left) {
                    s.push(root->left);
                    root = root->left;
                } else {
                    if(!s.empty()) {
                        root = s.top();
                        s.pop();
                        cout << root->data << " ";
                    }

                    if(root->right) {
                        s.push(root->right);
                        root = root->right;
                    }
                }
            }
        }

        void preorderRecursiveUtil(Node* root) {
            if(root == NULL) {
                return;
            }

            cout << root->data << " ";
            preorderRecursiveUtil(root->left);
            preorderRecursiveUtil(root->right);
        }

        void preorderIterativeUtil(Node* root) {
            if(root == NULL) {
                return;
            }

            Node* temp = root;
            stack<Node*> s;
            s.push(temp);

            while(!s.empty()) {
                if(!s.empty()) {
                    temp = s.top();
                    s.pop();
                    cout << temp->data << " ";

                    if(temp->right) {
                        s.push(temp->right);
                    }
                    if(temp->left) {
                        s.push(temp->left);
                    }
                }
            }
        }

        void postorderRecursiveUtil(Node* root) {
            if(root == NULL) {
                return;
            }

            postorderRecursiveUtil(root->left);
            postorderRecursiveUtil(root->right);
            cout << root->data << " ";
        }

        void postorderIterativeUtil(Node* root) {
            if(root == NULL) {
                return;
            }

            // maintain parent pointer of root
            Node* prev = NULL;
            stack<Node*> s;
            s.push(root);

            while(!s.empty()) {
                Node* curr = s.top();
                if((prev == NULL) || (prev->left == curr) || (prev->right == curr)) {
                    if(curr->left) {
                        s.push(curr->left);
                    } else if(curr->right) {
                        s.push(curr->right);
                    } else {
                        cout << curr->data << " ";
                        s.pop();
                    }
                } else if(curr->left == prev) {
                    if(curr->right) {
                        s.push(curr->right);
                    } else {
                        cout << curr->data << " ";
                        s.pop();
                    }
                } else if(curr->right == prev) {
                    cout << curr->data << " ";
                    s.pop();
                }

                // set previous visited node for next iteration
                prev = curr;
            }
        }

        int height(Node* node) {
            if ( node == NULL) {
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
};

int main() {

    Tree tree;
    tree.construct();

    // inorder traversal
    tree.inorderRecursive();
    tree.inorderRecursiveString();
    tree.inorderIterative();
//
//    // preorder traversal
//    tree.preorderRecursive();
//    tree.preorderIterative();
//
//    // postorder traversal
//    tree.postorderRecursive();
//    tree.postorderIterative();

    // levelorder traversal

    //cout << "LevelOrder Recursive:";
    //levelOrderRecursive(root);
    //cout << endl;

    //cout << "LevelOrder Iterative:";
    //levelOrderIterative(root);
    //cout << endl;

    //cout << "Reverse LevelOrder Iterative:";
    //reverseLevelOrderIterative(root);
    //cout << endl;

    return 0;
}
