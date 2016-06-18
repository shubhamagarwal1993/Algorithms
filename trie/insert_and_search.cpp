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
	for (int i = 0; i < key.length(); i++)
	{
		char index = key[i];
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
	cout << "word found: " << key << endl;
}

void delete_trie(TrieNode *root, string key)
{
	/*
	During delete operation we delete the key in bottom up manner using recursion. The following are possible conditions when deleting key from trie,
	Key may not be there in trie. Delete operation should not modify trie.
	Key present as unique key (no part of key contains another key (prefix), nor the key itself is prefix of another key in trie). Delete all the nodes.
	Key is prefix key of another long key in trie. Unmark the leaf node.
	Key present in trie, having atleast one other key as prefix key. Delete nodes from end of key until first leaf node of longest prefix key.
	*/
}

int main()
{
	TrieNode* root = newTrieNode();				//will be the root

	string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	int keys_size = sizeof(keys)/sizeof(keys[0]);

	// Construct trie
	for (int i = 0; i < keys_size; i++)
		insert(root, keys[i]);

	cout << "------" << endl;
	search(root, "the");
	search(root, "these");
	search(root, "their");
	search(root, "thaw");
	cout << "------" << endl;

	delete_trie(root, keys[0]);

	cout << "======" << endl;
	search(root, "the");
	cout << "======" << endl;

	return 0;
}
