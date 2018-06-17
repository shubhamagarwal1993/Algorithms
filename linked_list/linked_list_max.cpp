// compile using g++ -std=c++0x 2_3_4_array_sum.cpp

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

//linkedlist Node
struct listNode {
    int data;
    listNode* next;
};

//constructor for new listNode
listNode* newNode(int data) {
    listNode* node = new listNode;
    node->data = data;
    node->next = NULL;
    return node;
}

//construct linked list
void construct_linkedList(listNode* &head) {
    head                   = newNode(-4);
    head->next             = newNode(-6);
    head->next->next       = newNode(-2);
    head->next->next->next = newNode(-7);
    return;
}

//print linkedlist
void print_linkedList(listNode* head) {
    if (head == NULL)
        return;

    cout << head->data << " ";
    print_linkedList(head->next);
}

// find max in linkedlist recursively
int findMax(listNode* head) {
    if(head == NULL) {
        return 0;
    }

    if(head->next == NULL) {
        return head->data;
    }

    int curr_val = head->data;

    int max = findMax(head->next);

    if(curr_val > max) {
        max = curr_val;
    }
    return max;
}

int main() {

    // make linked list head
    listNode* head;
    cout << "constructing linked list" << endl;
    construct_linkedList(head);
    print_linkedList(head);
    cout << endl << "---------------" << endl;

    cout << "finding max in linked list" << endl;
    cout << "Max element = " << findMax(head) << endl;

    return 0;
}
