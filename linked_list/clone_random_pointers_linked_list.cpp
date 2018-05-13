#include <iostream>
#include <unordered_map>
using namespace std;

// Linkedlist Node
struct listNode {
    int data;
    listNode* next;
    listNode* prev;
};

// Constructor for new Node
listNode* newNode(int data) {
    listNode* node = new listNode;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// construct linked list
void construct_linkedList(listNode* &head) {
    head                               = newNode(1);
    head->next                         = newNode(2);
    head->next->next                   = newNode(4);
    head->next->next->next             = newNode(3);
    head->next->next->next->next       = newNode(2);
    head->next->next->next->next->next = newNode(1);
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
listNode* duplicate(listNode* head) {
    if(head == NULL) {
        return NULL;
    }

    // temp pointer for head, temp1 for head1
    listNode* temp_head = head;
    listNode* temp_end = head;

    while(temp_end != NULL) {
        temp_end = temp_end->next;
        temp_head->next = newNode(temp_head->data);
        temp_head = temp_head->next;
        temp_head->next = temp_end;
        temp_head = temp_head->next;
    }

    return head;
}

int main() {
    // make head
    listNode* head;
    cout << "constructing linked list" << endl;
    construct_linkedList(head);
    print_linkedList(head);
    cout << endl;

    cout << "Duplicat original linked list" << endl;
    listNode* newHead = duplicate(head);
    print_linkedList(newHead);
    cout << endl;

    return 0;
}

