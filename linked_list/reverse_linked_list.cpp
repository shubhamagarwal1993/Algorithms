// compile using g++ -std=c++0x 2_3_4_array_sum.cpp

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

//linkedlist Node
struct listNode
{
	int data;
//	listNode* prev;
	listNode* next;
};

//constructor for new listNode
listNode* newNode(int data)
{
	listNode* node = new listNode;
	node->data = data;
//	node->prev = NULL;
	node->next = NULL;
	return node;
}

//construct linked list
void construct_linkedList(listNode* &head)
{
	head					= newNode(1);
	head->next				= newNode(2);
	head->next->next		= newNode(3);
	head->next->next->next	= newNode(4);
	return;
}

//print linkedlist
void print_linkedList(listNode* head)
{
	if (head == NULL)
		return;

	cout << head->data << " ";
	print_linkedList(head->next);
}

//reverse linkedlist iteratively
void iterative_reverse(listNode* &head)
{
	if ((head == NULL) || (head->next == NULL))
		return;

	listNode* temp = head;
	while(temp->next != NULL)
	{
		listNode* temp1 = temp->next;
		
	}
	if (temp == NULL)
		return

	cout << head->data << " ";
	print_linkedList(head->next);
}

int main()
{
	//make head
	listNode* head;
	construct_linkedList(head);
	print_linkedList(head);
	
	iterative_reverse(head);
	
	cout << endl;
	return 0;
}
