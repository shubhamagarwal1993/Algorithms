// compile using g++ -std=c++0x 2_3_4_array_sum.cpp

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

// Construct linked list
void construct_linkedList(Node* &head) {
	head								= newNode(1);
	Node* temp 							= head;
	temp->next							= newNode(2);
	temp 								= temp->next;
	temp->next							= newNode(3);
	temp 								= temp->next;
	temp->next							= newNode(4);
	temp 								= temp->next;
	temp->next							= newNode(5);
	temp->next->next					= newNode(6);
	temp->next->next->next				= newNode(7);
	temp->next->next->next->next		= newNode(8);
	temp->next->next->next->next->next	= temp;
	return;
}

//print linkedlist
void print_linkedList(Node* &head) {
	if (head == NULL)
		return;

//	cout << head->data << " ";
//	print_linkedList(head->next);
	Node* temp = head;
	for(int i = 0; i < 12; i++) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// check for loop in linked list
Node* check_loop(Node* &head) {
	if(head == NULL) {
		return NULL;
	}

	Node* slow_runner = head;
	Node* fast_runner = head;
	Node* collision = NULL;

	while((fast_runner != NULL) || (fast_runner->next != NULL)) {
		fast_runner = fast_runner->next->next;
		slow_runner = slow_runner->next;

		if (fast_runner == slow_runner) {
			collision = fast_runner;
			break;
		}

	}

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

int main() {
	//make head
	Node* head;
	cout << "constructing linked list" << endl;
	construct_linkedList(head);
	print_linkedList(head);

	cout << "Checking for loop in linked list" << endl;
	Node* temp = check_loop(head);
	if(temp == NULL) {
		cout << "Linked list does not have a loop" << endl;
	} else {
		cout << "Linked list collides at: " << temp->data << endl;
	}
	cout << endl;
	return 0;
}
