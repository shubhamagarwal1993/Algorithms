#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// constructor for new tree node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//             1
//            / \
//           /   \
//          /     \
//         /       \
//        /         \
//      10           3
//     /  \         / \
//    /    \       /   \
//   4      6     2     9
//    \    / \   / \   / \
//    30  0   5 21  8 7  11
//

Node* constructTree() {

    Node* root               = newNode(1);
    root->left               = newNode(10);
    root->right              = newNode(3);

    root->left->left         = newNode(4);
    root->left->right        = newNode(6);

    root->right->left        = newNode(2);
    root->right->right       = newNode(9);

    root->left->left->right  = newNode(30);
    root->left->right->left  = newNode(0);
    root->left->right->right = newNode(5);

    root->right->left->left  = newNode(21);
    root->right->left->right = newNode(8);
    root->right->right->left = newNode(7);
    root->right->right->right= newNode(11);
    return root;
}

/**
 *
 */
void inOrderRecursive(Node* root) {
    if(root == NULL) {
        return;
    }

    inOrderRecursive(root->left);
    cout << root->data << " ";
    inOrderRecursive(root->right);
}

string inOrderRecursiveString(Node* root) {
    if(root == NULL) {
        return "";
    }

    string left = "";
    if(root->left) {
        left = inOrderRecursiveString(root->left);
    }

    string ans = to_string(root->data);

    string right = "";
    if(root->right) {
        right = inOrderRecursiveString(root->right);
    }

    return (left.empty() ? "" : left + " ") + ans + (right.empty() ? "" : " " + right);
}

void inOrderIterative(Node* root) {
    if(root == NULL) {
        return;
    }

    stack<Node*> s;
    Node* temp = root;
    s.push(temp);

    while(!s.empty()) {
        if(temp->left) {
            s.push(temp->left);
            temp = temp->left;
        } else {
            if(!s.empty()) {
                temp = s.top();
                s.pop();
                cout << temp->data << " ";
            }

            if(temp->right) {
                s.push(temp->right);
                temp = temp->right;
            }
        }
    }
}

void preOrderRecursive(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);
}

void preOrderIterative(Node* root) {
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

void postOrderRecursive(Node* root) {

    if(root == NULL) {
        return;
    }

    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    cout << root->data << " ";
}

// PostOrder iterative is the hardest traversal out of inOrder, and preOrder
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
void postOrderIterative(Node* root) {
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

int num_nodes(Node* root) {

    int count_nodes = 0;
    if(root == NULL) {
        return count_nodes;
    }

    num_nodes(root->left);
    count_nodes++;
    num_nodes(root->right);
    return count_nodes;
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

int main() {

    Node* root = constructTree();

    int num_of_nodes = num_nodes(root);
    cout << "NUM NODES: " << num_of_nodes << endl;

    // inOrder
    cout << "InOrder Recursive:";
    inOrderRecursive(root);
    cout << endl;
    cout << "inOrder Recurisve string: " << inOrderRecursiveString(root) << endl;
    cout << "InOrder Iterative:";
    inOrderIterative(root);
    cout << endl;

    // preOrder
    cout << "PreOrder Recursive:";
    preOrderRecursive(root);
    cout << endl;
    cout << "PreOrder Iterative:";
    preOrderIterative(root);
    cout << endl;

    // postOrder
    cout << "PostOrder Recursive:";
    postOrderRecursive(root);
    cout << endl;
    cout << "PostOrder Iterative:";
    postOrderIterative(root);
    cout << endl;

    // level order 
    cout << "LevelOrder Recursive:";
    levelOrderRecursive(root);
    cout << endl;
    cout << "LevelOrder Iterative:";
    levelOrderIterative(root);
    cout << endl;
    cout << "Reverse LevelOrder Iterative:";
    reverseLevelOrderIterative(root);
    cout << endl;

    return 0;
}
