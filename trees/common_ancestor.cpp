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
	Tree1->left               = newNode(10);
	Tree1->right              = newNode(3);
	Tree1->left->left         = newNode(4);
	Tree1->left->right        = newNode(6);
	Tree1->right->right       = newNode(3);
	Tree1->left->left->right  = newNode(30);
	return;
}

void construct_tree2(Node* Tree2)
{
	Tree2->left               = newNode(8);
	Tree2->right              = newNode(22);
	Tree2->left->left         = newNode(4);
	Tree2->left->right        = newNode(12);
	Tree2->left->right->left  = newNode(10);
	Tree2->left->right->right = newNode(14);
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

// when nodes in left/right subtrees, that is the ancestor. 
Node *LCA(Node *root, int n1, int n2)
{
	if (root == NULL)
		return root;
	
	if (root->data == n1 || root->data == n2)
		return root;
	
	Node *left_LCA = LCA(root->left, n1, n2);
	Node *right_LCA = LCA(root->right, n1, n2);

	//one node if left and one in right are present. Thus, we have ancestor
	if (left_LCA && right_LCA)
		return root;
	
	//else check which one is not null and go in that direction
	if (left_LCA != NULL)
		return left_LCA;
	else
		return right_LCA;
}

// This function returns pointer to LCA of two given values n1 and n2
// v1 is set as true by this function if n1 is found
// v2 is set as true by this function if n2 is found
Node *findLCAUtil(Node* root, int n1, int n2, bool &v1, bool &v2)
{
	// Base case
	if (root == NULL)
		return NULL;

	// If either n1 or n2 matches with root's key, report the presence
	// by setting v1 or v2 as true and return root (Note that if a key
	// is ancestor of other, then the ancestor key becomes LCA)
	if (root->data == n1)
	{
		v1 = true;
		return root;
	}
	
	if (root->data == n2)
	{
		v2 = true;
		return root;
	}

	// Look for keys in left and right subtrees
	Node *left_lca  = findLCAUtil(root->left, n1, n2, v1, v2);
	Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);

	// If both of the above calls return Non-NULL, then one key
	// is present in once subtree and other is present in other,
	// So this node is the LCA
	if (left_lca && right_lca)
		return root;

	// Otherwise check if left subtree or right subtree is LCA
	if (left_lca != NULL)
		return left_lca;
	else
		return right_lca;
}

// Returns true if key k is present in tree rooted with root
bool find(Node *root, int k)
{
	// Base Case
	if (root == NULL)
		return false;

	// If key is present at root, or in left subtree or right subtree,
	// return true;
	if (root->data == k || find(root->left, k) ||  find(root->right, k))
		return true;

	// Else return false
	return false;
}

// This function returns LCA of n1 and n2 only if both n1 and n2 are present
// in tree, otherwise returns NULL;
Node *findLCA(Node *root, int n1, int n2)
{
	// Initialize n1 and n2 as not visited
	bool v1 = false, v2 = false;

	// Find lca of n1 and n2 using the technique discussed above
	Node *lca = findLCAUtil(root, n1, n2, v1, v2);

	// Return LCA only if both n1 and n2 are present in tree
	if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
		return lca;

	// Else return NULL
	return NULL;
}

Node *lca(Node* root, int n1, int n2)
{
	if (root == NULL)
		return NULL;

	// If both n1 and n2 are smaller than root, then LCA lies in left
	if (root->data > n1 && root->data > n2)
		return lca(root->left, n1, n2);

	// If both n1 and n2 are greater than root, then LCA lies in right
	if (root->data < n1 && root->data < n2)
		return lca(root->right, n1, n2);

	return root;
}

int main()
{
	Node* Tree1 = newNode(26);		// tree1
	construct_tree1(Tree1);

/*
	//binary tree - 2 nodes - assumes both nodes are present in tree
	Node *ancestor = LCA(Tree1, 6, 4);
	cout << ancestor->data << endl;
	return 0;
*/
/*
	//binary tree - 2 nodes - using bool flags to check if value present in tree
	Node *ancestor = findLCA(Tree1, 4, 5);
	if (ancestor == NULL)
		cout << "key not present in tree" << endl;
	else
		cout << ancestor->data << endl;
*/

	//binary search tree - 2 nodes - assumes both noes are present in tree
	Node* Tree2 = newNode(20);
	construct_tree2(Tree2);
	Node *ancestor = findLCA(Tree2, 10, 14);
	cout << ancestor->data << endl;

	return 0;
}
