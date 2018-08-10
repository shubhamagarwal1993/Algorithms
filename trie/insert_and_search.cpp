//Trie - efficient information retrieval data structure
//Search for a key using Trie - O(M)        -M is maximum string length
//Search for a key using BST  - O(M logN)    -M is maximum string length, N is number of keys in tree.

//For Trie
//Insert - O(M)                                -M is key length
//Search - O(M)                                -M is key length
//Memory - O(ALPHABET_SIZE * M * N)            -M is key length, N is number of keys in Trie

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
                TrieNode* temp = new TrieNode();
                this->root->mymap['k'] = temp;
                cout << this->root->isLeaf << endl;
                if(this->root->mymap.size() == 1) {
                    cout << "map has one key" << endl;
                }
            }
            return;


//            int level = 0;
//
//            // tempRoot already has a map defined
//            for(int i = 0; i < key.length(); i++) {
//                level++;
//                char index = key[i];
//                unordered_map<char, TrieNode*>::iterator it;
//                if(tempRoot == NULL) {
//                    tempRoot = new TrieNode();
//                }
//                it = tempRoot->mymap.find(index);
//
//                //found char, move on to next char
//                if(it != tempRoot->mymap.end()) {
//                    tempRoot = tempRoot->mymap[index];
//                // new character
//                } else {
//                    TrieNode* temp = new TrieNode();
//                    tempRoot->mymap[index] = temp;
//                    if (level < key.length()) {
//                        tempRoot = tempRoot->mymap[index];
//                    }
//                }
//            }
//
//            // mark last node as leaf
//            tempRoot->isLeaf = true;
        }

        // Prints whether key was found in trie
        void search(TrieNode *tempRoot, string key) {
            int level = 0;

            for (int i = 0; i < key.length(); i++) {
                level++;
                char index = key[i];
                unordered_map<char, TrieNode*>::iterator it;
                if(tempRoot == NULL) {
                    cout << "Trie does not exist" << endl;
                    return;
                }
                it = tempRoot->mymap.find(index);

                if (it != tempRoot->mymap.end()) {
                    if (level < key.length())
                        tempRoot = tempRoot->mymap[index];
                } else {
                    cout << "word not found: " << key << endl;
                    return;
                }
            }

            if (tempRoot->isLeaf)
                cout << "word found: " << key << endl;
            else
                cout << "word not found: " << key << endl;
            
            return;
        }

        bool delete_trie(TrieNode *root, string key, int level, int key_length) {
            if (root == NULL) {
                cout << "root is null" << endl;
                return false;
            }

            // Base case
            if( level == key_length - 1) {
                //we are on the last letter of key
                char index = key[level];
                unordered_map<char, TrieNode*>::iterator it;
                it = root->mymap.find(index);

                if (it != root->mymap.end()) {
                    if (root->isLeaf) {
                        //make leaf false
                        root->isLeaf = false;

                        //if no children of last letter
                        if (root->mymap[index]->mymap.size() == 0) {
                            //first delete the allocated map here so no memory leak
                            delete root->mymap[index];

                            //then remove element from map so that this map becomes and empty map in the end
                            root->mymap.erase(index);
                            return true;
                        } else {
                            cout << "some more letters" << endl;
                            return false;                
                        }
                    } else
                        return false;
                } else
                    return false;
            }

            char index = key[level];
            unordered_map<char, TrieNode*>::iterator it;
            it = root->mymap.find(index);

            if (it != root->mymap.end()) {
                root = root->mymap[index];
                if (delete_trie(root, key, level+1, key_length)) {
                    // check keys in upward manner
                    cout << "in recursion: " << index << endl;
                    if (flag == 1) {
                        flag = 0;
                        return true;
                    }
                    cout << root->mymap.size() << endl;

                    //if no children of last letter
                    if (root->mymap[index]->mymap.size() == 0) {
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
};

int main() {
    Trie trie;

    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int keys_size = sizeof(keys)/sizeof(keys[0]);

    // Construct trie
    //for(int i = 0; i < keys_size; i++) {
    //    TrieNode* temp = trie.root;
    //    trie.insert(temp, keys[i]);
    //}

    trie.insert("the");

    cout << "------" << endl;
    cout << trie.root->isLeaf << endl;
    cout << trie.root->mymap.size() << endl;
//    trie.search(temp, "the");
//    trie.search(trie.root, "these");
//    trie.search(trie.root, "their");
//    trie.search(trie.root, "thaw");
    cout << "------" << endl;
//
//    trie.delete_trie(trie.root, keys[2], 0, keys[2].length());
//    trie.delete_trie(trie.root, keys[0], 0, keys[0].length());
//     
//    cout << "======" << endl;
//    trie.search(trie.root, "there");
//    trie.search(trie.root, "their");
//    trie.search(trie.root, "the");
//    trie.search(trie.root, "ther");
//    cout << "======" << endl;

    return 0;
}

