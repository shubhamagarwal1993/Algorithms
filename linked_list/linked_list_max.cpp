#include <iostream>

using namespace std;

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
            head                   = new Node(-4);
            head->next             = new Node(-6);
            head->next->next       = new Node(-2);
            head->next->next->next = new Node(-7);
            return;
        }

        void printLinkedList() {
            if(head == NULL) {
                return;
            }

            Node* temp = head;
            while(temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }

        // find max in linkedlist recursively
        int findMax() {
            return findMaxUtil(head);
        }

        int findMaxUtil(Node* head) {
            if(head == NULL) {
                return 0;
            }

            if(head->next == NULL) {
                return head->data;
            }

            int curr_val = head->data;

            int max = findMaxUtil(head->next);

            if(curr_val > max) {
                max = curr_val;
            }
            return max;
        }
};


int main() {

    LinkedList linkedlist;
    linkedlist.constructLinkedList();

    linkedlist.printLinkedList();

    cout << "Max element = " << linkedlist.findMax() << endl;

    return 0;
}
