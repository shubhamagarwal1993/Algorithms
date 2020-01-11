// compile using g++ -std=c++0x 2_3_4_array_sum.cpp

#include <iostream>

using namespace std;

// linkedlist Node
class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList {
    public:
        Node* head;
        LinkedList() {
            this->head = NULL;
        }

        void constructLinkedList() {
            this->head                               = new Node(1);
            this->head->next                         = new Node(2);
            this->head->next->next                   = new Node(3);
            this->head->next->next->next             = new Node(4);
            this->head->next->next->next->next       = new Node(5);
            this->head->next->next->next->next->next = new Node(6);
            return;
        }

        void print_linkedList() {
            if(this->head == NULL) {
                return;
            }

            Node* temp = this->head;
            while(temp != NULL) { 
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }

        // reverse linkedlist iteratively
        void iterative_reverse() {
            if((this->head == NULL) || (this->head->next == NULL)) {
                return;
            }

            Node* temp = this->head->next;
            Node* temp1 = NULL;

            while(this->head->next != NULL) {
                this->head->next = temp1;
                temp1 = this->head;
                this->head = temp;
                temp = temp->next;        
            }
            this->head->next = temp1;

            return;
        }
};

int main() {
    // make an empty linked list, and add data to it
    LinkedList linkedlist;
    linkedlist.constructLinkedList();

    // print linked list
    linkedlist.print_linkedList();

    cout << "reversing linked list" << endl;
    linkedlist.iterative_reverse();

    // print linked list
    linkedlist.print_linkedList();

    return 0;
}
