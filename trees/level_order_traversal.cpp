//	binary tree. linked list of all nodes at each depth

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//tree node
struct Node
{
	int data;
	Node* left;
	Node* right;
};

//constructor for new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void construct_tree1(Node* Tree1)
{
	Tree1->right              = newNode(3);
    Tree1->right->right       = newNode(3);
    Tree1->left               = newNode(10);
    Tree1->left->left         = newNode(4);
    Tree1->left->left->right  = newNode(30);
    Tree1->left->right        = newNode(6);
	return;
}

void inorder_print_tree1(Node* root)
{
	if (root == NULL)
		return;
	print_tree1(root->left);
	cout << root->data << " ";
	print_tree1(root->right);
}

int height(Node* node)
{
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
void printGivenLevel(Node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1)
	{
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}
}

//print tree to check
void printLevelOrder(Node* root)
{
	int h = height(root);
	for (int i = 1; i <= h; i++)
		printGivenLevel(root, i);
}

int main()
{
	Node* Tree1 = newNode(1);		// tree1
	construct_tree1(Tree1);

	inorder_print_tree1(Tree1);
	cout << endl;

	// level order 
	printLevelOrder(Tree1);
	cout << endl;




	return 0;
}
