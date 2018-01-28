#include <iostream>
#include <unordered_map>
using namespace std;

// Linkedlist Node
struct Node {
    int data;
    Node* next;
};

// Constructor for new Node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}

// linkedlist Node
struct listNode {
    int data;
//    listNode* prev;
    listNode* next;
};

// construct linked list
void construct_linkedList(listNode* &head) {
    head                      = newNode(1);
    head->next                = newNode(2);
    head->next->next          = newNode(3);
    head->next->next->next    = newNode(4);
    return;
}

// print linkedlist
void print_linkedList(listNode* &head) {
    if (head == NULL)
        return;

    cout << head->data << " ";
    print_linkedList(head->next);
}

// removed duplicates
void remove_duplicates(listNode* &head) {
    if ((head == NULL) || (head->next == NULL))
        return;

    unordered_map<int, int> mymap;

    listNode* temp = head;
    listNode* temp1 = head->next;

    while(temp->next != NULL) {
        temp = temp.next;
    }
}

int main() {
    // make head
    listNode* head;
    cout << "constructing linked list" << endl;
    construct_linkedList(head);
    print_linkedList(head);
    cout << endl;

    cout << "Removed duplicated from linked list" << endl;
    remove_duplicates(head);
    print_linkedList(head);
    cout << endl;

    return 0;
}

