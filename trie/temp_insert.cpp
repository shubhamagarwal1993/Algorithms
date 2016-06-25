//Trie - efficient information retrieval data structure
//Search for a key using Trie - O(M)		-M is maximum string length
//Search for a key using BST  - O(M logN)	-M is maximum string length, N is number of keys in tree.

//For Trie
//Insert - O(M)								-M is key length
//Search - O(M)								-M is key length
//Memory - O(ALPHABET_SIZE * M * N)			-M is key length, N is number of keys in Trie

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

using namespace std;

#define ALPHABET_SIZE 26

//tree node
struct TrieNode
{
	std::map<char, TrieNode*> mymap;
	bool isLeaf;
};

//constructor for new node
TrieNode* newTrieNode()
{
	TrieNode* trieNode = new TrieNode;
	trieNode->mymap.clear();
	trieNode->isLeaf = false;
	return trieNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(TrieNode *root, string key)
{
	int level = 0;
	char index;
	for (int i = 0; i < key.length(); i++)
	{
		level++;
		index = key[i];
		std::map<char, TrieNode*>::iterator it;
		it = root->mymap.find(index);

		if (it != root->mymap.end())
		{
			//found char, move on to next char
			root = root->mymap[index];
		}
		else	// new character
		{
			TrieNode* temp = newTrieNode();
			root->mymap[index] = temp;
			if (level < key.length())
				root = root->mymap[index];
		}
	}

	// mark last node as leaf
	root->isLeaf = true;

	
}

// Returns true if key presents in trie, else false
bool search(TrieNode *root, string key)
{
	for (int i = 0; i < key.length(); i++)
	{
		char index = key[i];
		std::map<char, TrieNode*>::iterator it;
		it = root->mymap.find(index);

		if (it != root->mymap.end())
		{
			root = root->mymap[index];
		}
		else
		{
			cout << "word not found: " << key << endl;
			return false;
		}
	}

	if (root->isLeaf)
		cout << "word found: " << key << endl;
	else
		cout << "word not found: " << key << endl;
}

bool delete_trie(TrieNode *root, string key, int level, int key_length)
{
	if (root == NULL)
	{
		cout << "root is null" << endl;
		return false;
	}

	// Base case
	if( level == key_length - 1)
	{
		//we are on the last letter of key
		char index = key[level];
		std::map<char, TrieNode*>::iterator it;
		it = root->mymap.find(index);

		if (it != root->mymap.end())
		{
			if (root->isLeaf)
			{
				//make leaf false
				root->isLeaf = false;

//				cout << temp->mymap.size() << endl;

				//check if mymap has children
				TrieNode* curr = root;
				curr = curr->mymap[index];
				cout << curr->mymap.size() << endl;
				if (curr->mymap.size() != 0)
					cout << "some more letters" << endl;
				else
					cout << "not more letters" << endl;
			}
		}

		return true;
	}

	char index = key[level];
	std::map<char, TrieNode*>::iterator it;
	it = root->mymap.find(index);

	if (it != root->mymap.end())
	{
		root = root->mymap[index];
		if( delete_trie(root, key, level+1, key_length) )
		{
			// check keys in upward manner
			cout << "in recursion" << endl;
			return true;
		}
	}

	return false;
}

int main()
{
	TrieNode* root = newTrieNode();				//will be the root
	cout << root->mymap.size() << endl;

	string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	int keys_size = sizeof(keys)/sizeof(keys[0]);

	// Construct trie
	for (int i = 0; i < keys_size; i++)
		insert(root, keys[i]);

	cout << "------" << endl;
	search(root, "there");
	search(root, "ther");
	search(root, "the");
	cout << "------" << endl;


	cout << delete_trie(root, keys[2], 0, keys[0].length()) << endl;

	cout << "======" << endl;
	search(root, "ther");
	cout << "======" << endl;


	return 0;
}
