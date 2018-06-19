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
//    listNode* prev;
    listNode* next;
};

//constructor for new listNode
listNode* newNode(int data) {
    listNode* node = new listNode;
    node->data = data;
//    node->prev = NULL;
    node->next = NULL;
    return node;
}

//construct linked list
void construct_linkedList(listNode* &head) {
    head                   = newNode(1);
    head->next             = newNode(2);
    head->next->next       = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next  = newNode(5);
    head->next->next->next->next->next = newNode(6);
    return;
}

//print linkedlist
void print_linkedList(listNode* &head) {
    if (head == NULL)
        return;

    cout << head->data << " ";
    print_linkedList(head->next);
}

//reverse linkedlist iteratively
void iterative_reverse(listNode* &head) {
    if ((head == NULL) || (head->next == NULL))
        return;

    listNode* temp = head->next;
    listNode* temp1 = NULL;

    while(head->next != NULL) {
        head->next = temp1;
        temp1 = head;
        head = temp;
        temp = temp->next;        
    }
    head->next = temp1;

    return;
}

int main() {
    //make head
    listNode* head;
    cout << "constructing linked list" << endl;
    construct_linkedList(head);
    print_linkedList(head);
    cout << endl;
    cout << "reversing linked list" << endl;
    iterative_reverse(head);
    print_linkedList(head);
    cout << endl;
    return 0;
}
