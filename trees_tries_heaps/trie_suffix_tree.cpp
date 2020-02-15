// Count of distinct substrings of a string using Suffix Trie

#include <iostream>

using namespace std;

#define MAX_CHAR 26

class Node {
    public:
        Node *children[MAX_CHAR];

        Node() {
            // Initialize all child pointers as NULL
            for(int i = 0; i < MAX_CHAR; i++) {
                children[i] = NULL;
            }
        }

        void insertSuffix(string s) {
            // If string has more characters
            if(s.length() > 0) {
                // Find the first character and convert it into 0-25 range
                char cIndex = s[0] - 'a';
 
                // If there is no edge for this character, add a new edge
                if(children[cIndex] == NULL) {
                    children[cIndex] = new Node();
                }

                // Recur for next suffix
                children[cIndex]->insertSuffix(s.substr(1));
            }
        }
};

class SuffixTrie {
    public:
        Node* root;

        SuffixTrie(string str) {
            this->root = new Node();

            for(int i = 0; i < str.length(); i++) {
                root->insertSuffix(str.substr(i));
            }
        }

        // count total nodes in suffix trie
        int countNodesInTrie(Node* root) {
            if(root == NULL) {
                return 0;
            }

            int count = 0;
            for(int i = 0; i < MAX_CHAR; i++) {
                // if children is not NULL then find count of all nodes in this subtrie
                if(root->children[i] != NULL) {
                    count += countNodesInTrie(root->children[i]);
                }
            }

            return (1 + count);
        }

        //          root
        //         /    \
        //        a a    b b
        //       /        \
        //      b ab       a ba
        //     /          /
        //    a aba      b bab
        //     \         \
        //      b abab    a baba
        //     /
        //    a ababa
        //    Each root to node path represents a prefix of words present in Trie
        void printNodesInTrie(Node* root) {
            if(root == NULL) {
                return;
            }

            for(int i = 0; i < MAX_CHAR; i++) {
                // if children is not NULL then find count of all nodes in this subtrie
                if(root->children[i] != NULL) {

                    cout << root->children[i] << endl;
                    printNodesInTrie(root->children[i], ans);
                }
            }

            return;
        }
};

int main() {

    // lowercase alphabet characters
    // Input: str = "ababa"
    // Output: 10
    // Total distinct substrings are 10
    // "", "a", "b", "ab", "ba", "aba", "bab", "abab", "baba", ababa"
    // Construct a Trie of all suffixes of given string, answer is total number of nodes
    string str = "ababa";
    SuffixTrie sTrie(str);
    cout << sTrie.countNodesInTrie(sTrie.root) << endl;
    string ans = "";
    sTrie.printNodesInTrie(sTrie.root);

    return 0;
}
