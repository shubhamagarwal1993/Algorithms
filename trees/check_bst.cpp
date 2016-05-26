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
	Tree1->left               = newNode(3);
	Tree1->right              = newNode(10);

	Tree1->left->left         = newNode(1);
	Tree1->left->right        = newNode(6);
	Tree1->left->right->left  = newNode(4);
	Tree1->left->right->right = newNode(7);

	Tree1->right->right       = newNode(14);
	Tree1->right->right->left = newNode(13);

	return;
}

void print_tree1(Node* root)
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


int checkHeight(Node *Tree1, int &temp_hei)
{
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

bool check_bst(Node *Tree1, int min, char min_flag, int max, char max_flag)
{
	if (Tree1 == NULL)
		return true;

	if ( (min_flag != 'a' && Tree1->data <= min) || (max_flag != 'a' && Tree1->data > max) )
		return false;

	if ( !check_bst(Tree1->left, min, min_flag, Tree1->data, 'b') || !check_bst(Tree1->right, Tree1->data, 'b', max, max_flag) )
		return false;

	return true;
}

int main()
{
	Node* Tree1 = newNode(8);		// tree1
	construct_tree1(Tree1);

	int temp_hei = 0;

/*
	//check balanced
	if (checkHeight(Tree1, temp_hei) == -1)
	{
		cout << "tree not balanced" << endl;
		return 0;
	}
	else
		cout << "height of tree is " << temp_hei << endl; //height(Tree1) << endl;
*/

	//validate tree for BST
	if (check_bst(Tree1, 0, 'a', 0, 'a'))
		cout << "tree is BST" << endl;
	else
		cout << "tree is not BST" << endl;

	return 0;
}
