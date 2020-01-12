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
//            1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
//                                ^______________|
            this->head                                                 = new Node(1);
            this->head->next                                           = new Node(2);
            this->head->next->next                                     = new Node(3);
            this->head->next->next->next                               = new Node(4);
            this->head->next->next->next->next                         = new Node(5);
            this->head->next->next->next->next->next                   = new Node(6);
            this->head->next->next->next->next->next->next             = new Node(7);
            this->head->next->next->next->next->next->next->next       = new Node(8);
            this->head->next->next->next->next->next->next->next->next = head->next->next->next->next;
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

        // check for loop in linked list
        void checkLoop() {

            Node* head = this->head;
            Node* loopNode = checkLoopUtil(head);
            if(loopNode == NULL) {
                cout << "Linked list does not have a loop" << endl;
            } else {
                cout << "Linked list collides at: " << loopNode->data << endl;
            }
            return;
        }

        Node* checkLoopUtil(Node* head) {
            if(head == NULL) {
                return NULL;
            }

            Node* slow_runner = head;
            Node* fast_runner = head;
            Node* collision = NULL;

            while((fast_runner != NULL) && (fast_runner->next != NULL)) {
                fast_runner = fast_runner->next->next;
                slow_runner = slow_runner->next;

                if(fast_runner == slow_runner) {
                    collision = fast_runner;
                    break;
                }
            }

            // No loop found
            if(collision == NULL) {
                return NULL;
            }

            // Reusing variables
            slow_runner = head;
            fast_runner = collision;

            while(slow_runner != fast_runner) {
                slow_runner = slow_runner->next;
                fast_runner = fast_runner->next;
            }

            return slow_runner;
        }
};

int main() {

    LinkedList linkedlist;
    linkedlist.constructLinkedList();

    // Do not print a list with a loop
    // linkedlist.printLinkedList();

    cout << "Checking for loop in linked list" << endl;
    linkedlist.checkLoop();

    return 0;
}
