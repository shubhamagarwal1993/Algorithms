// We will get the median of a running stream of integers
// For total of odd numbers - return the middle position integer
// For total of even numbers - return the avg of the 2 middle position integers
//
// We will solve by maintaining a max heap for the left side of the integers of the median, and a min heap for the right side

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

//tree node
class Node {
    public:
        char data;
        int freq;
        Node* left;
        Node* right;

        Node(char data, int freq) {
            this->data = data;
            this->freq = freq;
            this->left = NULL;
            this->right = NULL;
        };
};

struct compare {
    bool operator() (Node* a, Node* b) const {
        return a->freq > b->freq;
    }
};

void calculateFreq(unordered_map<char, int> &freq, string str) {
    for(int i = 0; i < str.length(); i++) {
        freq[str[i]]++;
    }
}

Node* buildHuffmanTree(unordered_map<char, int> freq) {

    // minHeap will hold nodes
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    Node* root;
    for(auto v = freq.begin(); v != freq.end(); v++) {
        root = new Node(v->first, v->second);
        minHeap.push(root);
    }

    while(minHeap.size() != 1) {
        // Take 2 min elements
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        // Make new node with frequency as sum of left and right
        Node* top = new Node('#', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    return minHeap.top();
}

void getCodes(Node* root, unordered_map<char, string> &codes, string str) {
    if(root == NULL) {
        return;
    }
    if(root->data != '#') {
        codes[root->data] = str;
        return;
    }

    getCodes(root->left, codes, str + "0");
    getCodes(root->right, codes, str + "1");
}

int main() {

    string str = "abbcccddddeeeeeffffff";
    unordered_map<char, int> freq;
    calculateFreq(freq, str);
    for(auto v = freq.begin(); v != freq.end(); v++) {
        cout << v->first << '-' << v->second << " ";
    }
    cout << endl;

    Node* root = buildHuffmanTree(freq);

    unordered_map<char, string> codes;
    getCodes(root, codes, "");
    for(auto v = codes.begin(); v != codes.end(); v++) {
        cout << v->first << '-' << v->second << endl;
    }

    return 0;
}

