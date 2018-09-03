// compile using g++ -std=c++0x 2_3_4_array_sum.cpp

// First List:        5->6->3  // represents number  563
// Second List:    1->8->4->2  // represents number 1842
// Resultant list: 2->4->0->5  // represents number 2405

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

        void constructLinkedList1() {
            this->head                   = new Node(5);
            this->head->next             = new Node(6);
            this->head->next->next       = new Node(3);
            return;
        }

        void constructLinkedList2() {
            this->head                   = new Node(6);
            this->head->next             = new Node(8);
            this->head->next->next       = new Node(4);
            //this->head->next->next->next = new Node(2);
            return;
        }

        void swapPointer(Node** a, Node** b) {
            Node* temp = *a;
            *a = *b;
            *b = temp;
        }

        int getLength(LinkedList l) {
            if(l.head == NULL) {
                return 0;
            }

            int size = 0;
            while(l.head != NULL) {
                size++;
                l.head = l.head->next;
            }
            return size;
        }

        LinkedList add(LinkedList l1, LinkedList l2) {
            if(l1.head == NULL) {
                return l2;
            } else if(l2.head == NULL) {
                return l1;
            }

            int l1_size = getLength(l1);
            int l2_size = getLength(l2);

            int carry = 0;

            // this linkedlist will hold the final result
            LinkedList sum_list;

            // same size linkedlist
            if(l1_size == l2_size) {
                sum_list.head = addSameSizeLinkedlist(l1.head, l2.head, carry);
            } else {
                int diff = abs(l1_size - l2_size);

                // First list should always be larger than second list; if not, swap pointers
                if(l1_size < l2_size) {
                    swapPointer(&l1.head, &l2.head);
                }

                // move diff number of nodes in first list
                Node* l1_temp_head = l1.head;
                for(int i = 0; i < diff; i++) {
                    l1_temp_head = l1_temp_head->next;
                }

                // get addition of same size lists
                sum_list.head = addSameSizeLinkedlist(l1_temp_head, l2.head, carry);

                // get addition of remaining first list and carry
                addCarryToRemaining(l1.head, l1_temp_head, carry, sum_list); 
            }

            if(carry > 0) {
                sum_list = prependNode(carry, sum_list);
            };
            sum_list.printLinkedlist();
            return l1;
        }

        void addCarryToRemaining(Node* head1, Node* cur, int &carry, LinkedList result) {
            int sum;
         
            // If diff. number of nodes are not traversed, add carry
            if(head1 != cur) {
                addCarryToRemaining(head1->next, cur, carry, result);

                sum = head1->data + carry;
                carry = sum/10;
                sum %= 10;
         
                // add this node to the front of the result
                result = prependNode(carry, sum);
            }
        }

        LinkedList prependNode(int carry, LinkedList sum_list) {
            Node* new_head = new Node(carry);
            new_head->next = sum_list.head;
            sum_list.head = new_head;
            return sum_list;
        }

        Node* addSameSizeLinkedlist(Node* l1, Node* l2, int &carry) {

            if(l1 == NULL) {
                return NULL;
            }

            int sum;

            // Recursively add remaining nodes and get the carry
            Node* curr_sum = addSameSizeLinkedlist(l1->next, l2->next, carry);

            // add digits of current nodes and propagated carry
            sum = l1->data + l2->data + carry;
            carry = sum / 10;
            sum = sum % 10;

            // Assigne the sum to current node of resultant list
            Node* result = new Node(sum);
            result->next = curr_sum;

            return result;
        }

        void printLinkedlist() {
            if(head == NULL) {
                return;
            }

            Node* temp = head;
            while(temp != NULL) { 
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }

//        // reverse linkedlist iteratively
//        void iterative_reverse() {
//            if((head == NULL) || (head->next == NULL)) {
//                return;
//            }
//
//            Node* temp = head->next;
//            Node* temp1 = NULL;
//
//            while(head->next != NULL) {
//                head->next = temp1;
//                temp1 = head;
//                head = temp;
//                temp = temp->next;        
//            }
//            head->next = temp1;
//
//            return;
//        }
};

int main() {
    // make an empty linked list, and add data to it
    LinkedList linkedlist1;
    linkedlist1.constructLinkedList1();

    LinkedList linkedlist2;
    linkedlist2.constructLinkedList2();

    LinkedList resultantlist;
    resultantlist.add(linkedlist1, linkedlist2);

//    // print linked list
//    linkedlist.print_linkedList();
//
//    cout << "reversing linked list" << endl;
//    linkedlist.iterative_reverse();
//
//    // print linked list
//    linkedlist.print_linkedList();

    return 0;
}
