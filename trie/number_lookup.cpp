//Trie - efficient information retrieval data structure
//Search for a key using Trie - O(M)        -M is maximum string length
//Search for a key using BST  - O(M logN)   -M is maximum string length, N is number of keys in tree

//For Trie
//Insert - O(M)                             -M is key length
//Search - O(M)                             -M is key length
//Memory - O(ALPHABET_SIZE * M * N)         -M is key length, N is number of keys in Trie

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
int flag = 1;

//tree node
struct TrieNode {
    std::map<char, TrieNode*> mymap;
    bool isLeaf;
};

//constructor for new node
TrieNode* newTrieNode() {
    TrieNode* trieNode = new TrieNode;
    trieNode->mymap.clear();
    trieNode->isLeaf = false;
    return trieNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(TrieNode *root, string key) {
    int level = 0;

    // root already has a map defined
    for(int i = 0; i < key.length(); i++) {
        level++;
        char index = key[i];
        std::map<char, TrieNode*>::iterator it;
        it = root->mymap.find(index);

        //found char, move on to next char
        if(it != root->mymap.end()) {
            root = root->mymap[index];
        // new character
        } else {
            TrieNode* temp = newTrieNode();
            root->mymap[index] = temp;
            if(level < key.length())
                root = root->mymap[index];
        }
    }

    // mark last node as leaf
    root->isLeaf = true;
}

// Prints whether key was found in trie
void search(TrieNode *root, string key) {
    int level = 0;
    for(int i = 0; i < key.length(); i++) {
        level++;
        char index = key[i];
        std::map<char, TrieNode*>::iterator it;
        it = root->mymap.find(index);

        if(it != root->mymap.end()) {
            if(level < key.length())
                root = root->mymap[index];
        } else {
            cout << "word not found: " << key << endl;
            return;
        }
    }

    if(root->isLeaf) {
        cout << "word found: " << key << endl;
    } else {
        cout << "word not found: " << key << endl;
    }

    return;
}

bool delete_trie(TrieNode *root, string key, int level, int key_length) {
    if(root == NULL) {
        cout << "root is null" << endl;
        return false;
    }

    // Base case
    if(level == key_length - 1) {
        //we are on the last letter of key
        char index = key[level];
        std::map<char, TrieNode*>::iterator it;
        it = root->mymap.find(index);

        if(it != root->mymap.end()) {
            if(root->isLeaf) {
                //make leaf false
                root->isLeaf = false;

                //if no children of last letter
                if(root->mymap[index]->mymap.size() == 0) {
                    //first delete the allocated map here so no memory leak
                    delete root->mymap[index];

                    //then remove element from map so that this map becomes and empty map in the end
                    root->mymap.erase(index);
                    return true;
                } else {
                    cout << "some more letters" << endl;
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    char index = key[level];
    std::map<char, TrieNode*>::iterator it;
    it = root->mymap.find(index);

    if(it != root->mymap.end()) {
        root = root->mymap[index];
        if(delete_trie(root, key, level+1, key_length)) {
            // check keys in upward manner
            cout << "in recursion: " << index << endl;
            if(flag == 1) {
                flag = 0;
                return true;
            }
            cout << root->mymap.size() << endl;

            //if no children of last letter
            if(root->mymap[index]->mymap.size() == 0) {
                //cout << "level: " << level << endl;
                //cout << "not more letters" << endl;
                //cout << root->mymap.size() << endl;
                root->mymap.erase(index);
                //cout << root->mymap.size() << endl;
                return true;
            } else {
                //cout << "some more letters" << endl;
                return false;
            }
        }
        return false;
    }
    return false;
}

int main() {
    TrieNode* root = newTrieNode();

    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int keys_size = sizeof(keys)/sizeof(keys[0]);

    // Construct trie
    for(int i = 0; i < keys_size; i++) {
        insert(root, keys[i]);
    }

    cout << "------" << endl;
    search(root, "the");
    search(root, "these");
    search(root, "their");
    search(root, "thaw");
    cout << "------" << endl;

    delete_trie(root, keys[2], 0, keys[2].length());
    delete_trie(root, keys[0], 0, keys[0].length());

    cout << "======" << endl;
    search(root, "there");
    search(root, "their");
    search(root, "the");
    search(root, "ther");
    cout << "======" << endl;

    return 0;
}

