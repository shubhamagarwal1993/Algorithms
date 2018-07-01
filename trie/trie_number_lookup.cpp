#include<iostream>
#include<unordered_map>

using namespace std;

class TrieNode {
    public:
        bool isLeaf;
        unordered_map<int, TrieNode*> mymap;
        
        TrieNode() {
            TrieNode* trieNode = new TrieNode;
            trieNode->mymap.clear();
            trieNode->isLeaf = false;
        }
        
        bool keyExistsInMap(TrieNode* root, int key) {
            cout << "key: " << key << endl;
            std::unordered_map<int, TrieNode*>::iterator it;
            it = root->mymap.find(key);
            cout << "after find" << endl;
            return (it != root->mymap.end());
        }
};

void insert(TrieNode* root, int temp[], int temp_size) {
    cout << "inside insert func" << endl;
    cout << root->isLeaf << endl;
    //for(int i = 0; i < temp_size; i++) {
    //    // check of digit exists
    //    std::unordered_map<int, TrieNode*>::iterator it;

    //    if(it != root->mymap.find(temp[i])) {
    //        cout << "found" << endl;
    //    } else {
    //        cout << "not found" << endl;
    //    }

    //    bool test = root->keyExistsInMap(root, temp[i]);
    //    //cout << test << endl;
    //    //if(root->keyExistsInMap(root, temp[i])) {
    //    //    root = root->mymap[temp[i]];
    //    //} else {
    //    //    TrieNode* newTrieNode;
    //    //    root->mymap[temp[i]] = newTrieNode;
    //    //}
    //}
}

int main() {

    TrieNode* root = new TrieNode();

    int temp[] = {1, 2, 3};
    int temp_size = sizeof(temp)/sizeof(temp[0]);
    insert(root, temp, temp_size);
    return 0;
}
