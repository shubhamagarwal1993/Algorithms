#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

void construct_tree1(Node* Tree1) {
    Tree1->left               = newNode(3);
    Tree1->right              = newNode(12);

    Tree1->left->left         = newNode(1);
    Tree1->left->right        = newNode(6);
    Tree1->left->right->left  = newNode(4);
    Tree1->left->right->right = newNode(7);

    Tree1->right->left        = newNode(11);
    Tree1->right->right       = newNode(15);
    Tree1->right->right->left = newNode(14);

//         8
//        / \
//       /   \
//      3    12
//     / \   / \
//    1   6 11 15
//       / \   /
//      4   7 14
    return;
}

void inorder_traversal(Node* root) {
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

int height(Node* node) {
    if ( node == NULL)
        return 0;
    else
    {
        // compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);

        // use the larger one
        if (lheight > rheight)
            return(lheight+1);
        else
            return(rheight+1);
    }
}

// Print nodes at a given level
void printGivenLevel(Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

//print tree to check
void printLevelOrder(Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printGivenLevel(root, i);
}


int checkHeight(Node *Tree1, int &temp_hei) {
    if (Tree1 == NULL)
        return 0;

    int left_height = checkHeight(Tree1->left, temp_hei);
    if (left_height == -1)
        return -1;

    int right_height = checkHeight(Tree1->right, temp_hei);
    if (right_height == -1)
        return -1;

    int height_diff = abs(left_height - right_height);

    if (height_diff > 1)
        return -1;
    else
    {
        temp_hei = max(left_height, right_height) + 1;
        return temp_hei;
    }
}

bool check_bst(Node *Tree1, int min, char min_flag, int max, char max_flag) {
    if (Tree1 == NULL)
        return true;

    if ( (min_flag != 'a' && Tree1->data <= min) || (max_flag != 'a' && Tree1->data > max) )
        return false;

    // b is just anything random, can be NULL as well, it should basically not be a
    if ( !check_bst(Tree1->left, min, min_flag, Tree1->data, 'b') || !check_bst(Tree1->right, Tree1->data, 'b', max, max_flag) )
        return false;

    return true;
}

void maxSumPathHelper(Node *Tree1, int *max_sum, int curr_sum, stack <int>& curr_stack, stack <int>& final_stack) {
    if (Tree1 == NULL)
        return;

    // Update current sum to hold sum of nodes on path
    curr_sum = curr_sum + Tree1->data;
    //cout << " pos: " << Tree1->data;
    curr_stack.push(Tree1->data);

    // If this is a leaf node and path to this node has
    // maximum sum so far, then make this node target_leaf
    if (Tree1->left == NULL && Tree1->right == NULL) {
        if (curr_sum > *max_sum) {
            *max_sum = curr_sum;
            if(!final_stack.empty()) {
                final_stack.pop();
            }
            while(!curr_stack.empty()) {
                //cout << "stack: " << s.top() << endl;
                int temp_val = curr_stack.top();
                final_stack.push(temp_val);
                curr_stack.pop();
            }
        } else {
            //while(!curr_stack.empty()) {
                curr_stack.pop();
            //}
        }
    }
 
    // If this is not a leaf node, then recur down 
    // to find the target_leaf
    maxSumPathHelper(Tree1->left, max_sum, curr_sum, curr_stack, final_stack);
    maxSumPathHelper(Tree1->right, max_sum, curr_sum, curr_stack, final_stack);
}

int maxSumPath(Node *Tree1) {
    
    // base case
    if (Tree1 == NULL)
        return 0;
 
     // take the min possible for an int
    int max_sum = INT_MIN;

    // hold current sum
    int curr_sum = 0;

    stack <int> curr_stack;
    stack <int> final_stack;
    // find the target leaf and maximum sum
     maxSumPathHelper(Tree1, &max_sum, curr_sum, curr_stack, final_stack);
     while(!final_stack.empty()) {
         cout << "stack: " << final_stack.top() << endl;
         final_stack.pop();
     }
    // print the path from root to the target leaf
   // printPath (node, target_leaf);
 
    return max_sum;  // return maximum sum
}

int main() {
    // Make a tree - we will call it Tree1
    Node* Tree1 = newNode(8);
    construct_tree1(Tree1);

    // // Print tree
    // cout << "inorder traversal: ";
    // inorder_traversal(Tree1);
    // cout << endl;

    // // Get the longest height of the tree
    // cout << "longest height: " << height(Tree1) << endl;

    // // Check if tree is balanced
    // int temp_hei = 0;
    // if (checkHeight(Tree1, temp_hei) == -1) {
    //     cout << "tree not balanced" << endl;
    // } else {
    //     cout << "tree is balanced. Height of tree is: " << temp_hei << endl; //height(Tree1) << endl;
    // }

    // // Check if tree is BST
    // if (check_bst(Tree1, 0, 'a', 0, 'a'))
    //     cout << "tree is BST" << endl;
    // else
    //     cout << "tree is not BST" << endl;

    // Find the greatest sum from one path
    int max_sum = maxSumPath(Tree1);
    cout << "greatest sum from one path: " << max_sum << endl;
    return 0;
}

