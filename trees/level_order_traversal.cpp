//    binary tree. linked list of all nodes at each depth

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

//tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

//constructor for new node
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

void construct_tree1(Node* Tree1) {
    Tree1->left               = newNode(10);
    Tree1->right              = newNode(3);

    Tree1->left->left         = newNode(4);
    Tree1->left->right        = newNode(6);

    Tree1->right->left        = newNode(2);
    Tree1->right->right       = newNode(9);

    Tree1->left->left->right  = newNode(30);
    Tree1->left->right->left  = newNode(0);
    Tree1->left->right->right = newNode(5);

    Tree1->right->left->left   = newNode(21);
    Tree1->right->left->right  = newNode(8);
    Tree1->right->right->left  = newNode(7);
    Tree1->right->right->right = newNode(11);
    return;
}

void inorder_print_tree1(Node* root) {
    if (root == NULL)
        return;
    inorder_print_tree1(root->left);
    cout << root->data << " ";
    inorder_print_tree1(root->right);
}
void preorder_print_tree1(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder_print_tree1(root->left);
    preorder_print_tree1(root->right);
}
void postorder_print_tree1(Node* root) {
    if (root == NULL)
        return;
    postorder_print_tree1(root->left);
    postorder_print_tree1(root->right);
    cout << root->data << " ";
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
void printLevelOrder(Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
    }
}

void print_Level_Order_iter(Node* Tree1) {
    if (Tree1 == NULL)
        return;

    queue<Node*> myqueue;
    myqueue.push(Tree1);
    int count = 0;

    while(!myqueue.empty()) {
        count = myqueue.size();
        while(count > 0) {
            Node* temp = myqueue.front();
            myqueue.pop();
            cout << temp->data << " ";

            if(temp->left != NULL)
                myqueue.push(temp->left);
            
            if(temp->right != NULL)
                myqueue.push(temp->right);
            count--;
        }
        cout << endl;
    }
}

void num_nodes(Node* root, int &num_of_nodes) {
    if (root == NULL)
        return;
    num_nodes(root->left, num_of_nodes);
    num_of_nodes++;
    num_nodes(root->right, num_of_nodes);
}

void print_Reverse_Level_Order_iter(Node* Tree1) {
    if (Tree1 == NULL)
        return;
    int num_of_nodes = 0;
    num_nodes(Tree1, num_of_nodes);

    vector<Node*> myvec;
    myvec.push_back(Tree1);
    int count = 0;
    stack<int> mystack;
    mystack.push(1);
    int i = 0;
    int flag = 0;
    while(num_of_nodes > 0) {
        Node* temp = myvec[i];

        if(temp->left != NULL) {
            myvec.push_back(temp->left);
            num_of_nodes--;
            flag = 1;
        }
        
        if(temp->right != NULL) {
            myvec.push_back(temp->right);
            num_of_nodes--;
            flag = 1;
        }
        if(flag == 1)
            i++;
        flag = 0;
        cout << i << endl;
        cout << num_of_nodes << endl;
        cout << endl;
    }

    //my stack has nodes on each level
    //myvec has all nodes
    //reverse vec
    cout << "here" << endl;

    for(int i = 0; i < myvec.size(); i++)
        cout << myvec[i]->data << " ";
    cout << endl;
    cout << "after here" << endl;

    std::reverse(myvec.begin(), myvec.end());
    while(!mystack.empty()) {
        int temp = mystack.top();
        mystack.pop();
        while(temp > 0) {
            cout << myvec[0]->data << " ";
            myvec.erase(myvec.begin());
        }
        cout << endl;
    }
}

int main() {
    Node* Tree1 = newNode(1);        // tree1
    construct_tree1(Tree1);

    inorder_print_tree1(Tree1);
    cout << endl;
    preorder_print_tree1(Tree1);
    cout << endl;
    postorder_print_tree1(Tree1);
    cout << endl;

    // level order 
//    printLevelOrder(Tree1);
//    cout << endl;

    cout << "======" << endl;
    print_Level_Order_iter(Tree1);
    cout << "======" << endl;
    cout << endl;

//    cout << "------" << endl;
//    print_Reverse_Level_Order_iter(Tree1);
//    cout << "------" << endl;
//    cout << endl;

    return 0;
}
