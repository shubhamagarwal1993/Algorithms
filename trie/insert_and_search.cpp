/*
 * Trie - efficient information storage, and retrieval data structure
 * Insert: O(M)                             M is the string length
 * Search: O(M)                             M is the string length
 *
 * Space Complexity: O(ALPHABET_SIZE * M * N)   M is the longest key length, N is number of keys in Trie
 */

#include <iostream>
#include <unordered_map>

using namespace std;

#define ALPHABET_SIZE 26
int flag = 1;

class TrieNode {
    public:
        unordered_map<char, TrieNode*> mymap;
        bool isLeaf;

        TrieNode() {
            this->isLeaf = false;
        }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            this->root = NULL;
        }

        // If not present, inserts key into trie
        // If the key is prefix of trie node, just marks leaf node
        void insert(string key) {

            if(this->root == NULL) {
                this->root = new TrieNode();
            }

            TrieNode* root = this->root;

            // iterator to use while traversing maps
            unordered_map<char, TrieNode*>::iterator it;

            // loop over characters in key and insert each one of them
            for(int i = 0; i < key.length(); i++) {
                char char_curr = key[i];

                // if it exists, then just continue down the path
                it = root->mymap.find(char_curr);
                if(it != root->mymap.end()) {
                    root = root->mymap[char_curr];
                    continue;
                }

                // Key does not exist, insert it
                TrieNode* temp = new TrieNode();
                root->mymap[char_curr] = temp;
                root = root->mymap[char_curr];
            }

            // mark last node as leaf
            root->isLeaf = true;
        }

        // Prints whether key was found in trie
        void search(string key) {

            TrieNode* root = this->root;

            for (int i = 0; i < key.length(); i++) {
                char index = key[i];
                unordered_map<char, TrieNode*>::iterator it;
                if(root == NULL) {
                    cout << "Trie does not exist" << endl;
                    return;
                }
                it = root->mymap.find(index);

                if (it != root->mymap.end()) {
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

        void delete_trie(string key) {

            TrieNode* root = this->root;

            for (int i = 0; i < key.length(); i++) {
                char index = key[i];
                unordered_map<char, TrieNode*>::iterator it;
                if(root == NULL) {
                    cout << "Trie does not exist" << endl;
                    return;
                }
                it = root->mymap.find(index);

                if (it != root->mymap.end()) {
                    root = root->mymap[index];
                } else {
                    cout << "word not found: " << key << endl;
                    return;
                }
            }

            if(root->isLeaf) {
                root->isLeaf = false;
            }

            return;
        }
};

int main() {
    Trie trie;

    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int keys_size = sizeof(keys)/sizeof(keys[0]);

    // Construct trie
    for(int i = 0; i < keys_size; i++) {
        TrieNode* temp = trie.root;
        trie.insert(keys[i]);
    }

    trie.search("the");
    trie.search("their");

    trie.delete_trie("the");
    trie.search("the");

    return 0;
}

