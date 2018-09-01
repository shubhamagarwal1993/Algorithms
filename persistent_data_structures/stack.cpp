#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

class Stack {

    public:
        Node* top;

        Stack() {
            this->top = NULL;
        }

        bool isEmpty() {
            return top == NULL;
        }

        Node* peek() {
            if(this->top == NULL) {
                return NULL;
            }
            return this->top;
        }

        void push(int data) {
            if(this->top == NULL) {
                this->top = new Node(data);
                return;
            }

            this->top->next = new Node(data);
            this->top->next->prev = this->top;
            this->top = this->top->next;
            return;
        }

        void pop() {
            if(this->top == NULL) {
                return;
            }

            Node* temp = this->top->prev;
            this->top->prev = NULL;

            if(temp != NULL) {
                temp->next = NULL;
            }
            delete(this->top);
            this->top = temp;
            temp = NULL;
            return;
        }
};

class InternalStack {
    public:
        Node* top;
        Stack s;

        InternalStack(Stack s) {
            this->top = NULL;
            this->s = s;
        }
};

class PersistentStack {

    public:
        int top;
        InternalStack is(Stack());

        PersistentStack() {
            this->top = -1;
        }

        bool isEmpty() {
            return (this->is.top == NULL;
        }

//        Node* peek() {
//            if(this->is.top == NULL) {
//                return NULL;
//            }
//            return this->is.top;
//        }
//
//        PersistentStack push(int data) {
//            return PersistentStack(data, this->is);
//        }
//
//        PersistentStack pop() {
//            return PersistentStack(this->is.top->data, this->is);
//        }
};

int main() {
    Stack s;
    cout << s.isEmpty() << endl;
    s.push(5);
    s.push(6);
    cout << s.top->data << endl;
    s.pop();
    Node* temp = s.peek();
    if(temp) {
        cout << temp->data << endl;
    } else {
        cout << "empty stack" << endl;
    }

    //
    InternalStack is(s);
    PersistentStack ps;
    return 0;
}
