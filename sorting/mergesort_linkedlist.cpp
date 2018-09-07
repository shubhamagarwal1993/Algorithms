#include <iostream>

using namespace std;

// Linked list node
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
            head                                           = new Node(1);
            head->next                                     = new Node(2);
            head->next->next                               = new Node(3);
            head->next->next->next                         = new Node(4);
            head->next->next->next->next                   = new Node(8);
            head->next->next->next->next->next             = new Node(7);
            head->next->next->next->next->next->next       = new Node(6);
            head->next->next->next->next->next->next->next = new Node(5);
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

        /**
         * Split the nodes of the given linked list into front and back halves
         * and return the two lists using the reference parameters
         *
         * If the length is odd, the extra node should go in the front list
         * Uses the fast/slow pointer strategy
         */
        void linkedListSplit(Node* head_ref, Node** front_ref, Node** back_ref) {

            Node* fast = head_ref->next;
            Node* slow = head_ref;
 
            // Advance 'fast' two nodes, and advance 'slow' one node
            while(fast != NULL) {
                fast = fast->next;
                if(fast != NULL) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            // 'slow' is before the midpoint in the list, so split it in two at that point
            *front_ref = head_ref;
            *back_ref = slow->next;
            slow->next = NULL;
        }
 
        Node* sortedMerge(Node* front_ref, Node* back_ref) {

            Node* result = NULL;

            if(front_ref == NULL) {
                return(back_ref);
            } else if(back_ref == NULL) {
                return(front_ref);
            }

            // Pick either head_ref or back_ref and recur
            if(front_ref->data <= back_ref->data) {
                result = front_ref;
                result->next = sortedMerge(front_ref->next, back_ref);
            } else {
                result = back_ref;
                result->next = sortedMerge(front_ref, back_ref->next);
            }

            return result;
        }

        void mergeSort(Node** head) {

            Node* head_ref = *head;
            Node* front_ref = NULL;
            Node* back_ref = NULL;

            // Base case, length 0 or 1
            if(head_ref == NULL || head_ref->next == NULL) {
                return;
            }

            // Split head into 'a' and 'b' sublists
            linkedListSplit(head_ref, &front_ref, &back_ref);

            mergeSort(&front_ref);
            mergeSort(&back_ref);

            // merge the two sorted lists together
            head_ref = sortedMerge(front_ref, back_ref);

            return;
        }
};

int main() {

    LinkedList linkedlist;
    linkedlist.constructLinkedList();

    linkedlist.printLinkedList();
    linkedlist.mergeSort(&linkedlist.head);
    linkedlist.printLinkedList();

    return 0;
}

