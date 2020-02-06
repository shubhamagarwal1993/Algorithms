#include <iostream>
#include <unordered_map>
using namespace std;

// LinkedList Node
class Node {
    public:
        int data;
        Node* next;
        Node* random;

        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }
};

// LinkedList
class LinkedList {
    public:
        Node* head;
        Node* duplicateHead;

        LinkedList() {
            this->head = NULL;
            this->duplicateHead = NULL;
        }

        // construct linked list
        void constructLinkedList() {
            this->head                               = new Node(1);
            this->head->next                         = new Node(2);
            this->head->next->next                   = new Node(3);
            this->head->next->next->next             = new Node(4);
            this->head->next->next->next->next       = new Node(5);

            // set random pointers
            this->head->random                         = head->next->next;                // 1 -> 3
            this->head->next->random                   = head;                            // 2 -> 1
            this->head->next->next->random             = head->next->next->next->next;    // 3 -> 5
            this->head->next->next->next->random       = head->next->next->next->next;    // 4 -> 5
            this->head->next->next->next->next->random = head->next;                      // 5 -> 2
            return;
        }

        // print linkedlist
        void printLinkedList(Node* head) {
            if(head == NULL) {
                return;
            }

            Node* temp = head;
            while(temp) {
                cout << "Data: " << temp->data << " Random: " << temp->random->data << endl;
                temp = temp->next;
            }
            return;
        }

        // duplicate linkedlist
        void duplicateLinkedList() {
            if(head == NULL) {
                return;
            }

            // duplicate nodes, insert additional node after every node of original list
            Node* curr = head;
            Node* temp = NULL;

            while(curr) {
                temp = curr->next;
 
                // Inserting node
                curr->next = new Node(curr->data);
                curr->next->next = temp;
                curr = temp;
            }
 
            curr = head;
            temp = NULL;

            // adjust the random pointers of the newly added nodes
            while(curr) {
                curr->next->random = curr->random->next;

                // move to the next newly added node by
                // skipping an original node
                curr = curr->next?curr->next->next:curr->next;
            }

            duplicateHead = head->next;

            Node* originalHead = head;
            Node* copyHead = duplicateHead;

            // now separate the original list and copied list
            while(originalHead && copyHead) {
                originalHead->next = originalHead->next ? originalHead->next->next : originalHead->next;
                copyHead->next = copyHead->next ? copyHead->next->next : copyHead->next;
                originalHead = originalHead->next;
                copyHead = copyHead->next;
            }
        }
};

int main() {

    LinkedList linkedlist;
    linkedlist.constructLinkedList();
    linkedlist.printLinkedList(linkedlist.head);

    cout << "Duplicate original linked list" << endl;
    linkedlist.duplicateLinkedList();
    linkedlist.printLinkedList(linkedlist.duplicateHead);

    return 0;
}
