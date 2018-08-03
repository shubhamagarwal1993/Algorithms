#include <iostream>
#include <unordered_map>

using namespace std;

// Linkedlist Node
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
            head                                           = new Node(1);
            head->next                                     = new Node(2);
            head->next->next                               = new Node(3);
            head->next->next->next                         = new Node(4);
            head->next->next->next->next                   = new Node(2);
            head->next->next->next->next->next             = new Node(5);
            head->next->next->next->next->next->next       = new Node(6);
            head->next->next->next->next->next->next->next = new Node(2);
            return;
        }

        void printLinkedList() {
            if(head == NULL) {
                return;
            }

            Node*temp = head;
            while(temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }

        // removed duplicates
        void removeDuplicates() {
            if((head == NULL) || (head->next == NULL)) {
                return;
            }

            // map will store values seen, add first node
            unordered_map<int, bool> valuesMap;
            valuesMap[head->data] = true;

            // This pointer to delete the next node
            Node* prev = head;

            // This pointer to check for duplicates
            Node* curr = prev->next;

            while(curr != NULL) {
                auto search = valuesMap.find(curr->data);

                // if found delete node, else insert data into map
                if(search != valuesMap.end()) {
                    prev->next = curr->next;
                    curr->next = NULL;
                    delete(curr);
                } else {
                    valuesMap[curr->data] = true;
                    prev = curr;
                }

                curr = prev->next;
            }
        }
};

int main() {

    LinkedList linkedlist;
    cout << "constructing linked list" << endl;
    linkedlist.constructLinkedList();
    linkedlist.printLinkedList();
    cout << endl;

    cout << "Removed duplicated from linked list" << endl;
    linkedlist.removeDuplicates();
    linkedlist.printLinkedList();

    return 0;
}

