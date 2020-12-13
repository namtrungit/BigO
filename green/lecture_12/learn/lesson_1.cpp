#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	int data;
	Node* next; // Pointer
};

Node* createNode(int x) {
	Node *p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}

struct LinkedList {
	Node *head; // Pt dau tien cua list
	Node *tail; // Pt cuoi cung cua list
};

void init(LinkedList &lst) {
	// linked list
	lst.head = NULL;
	lst.tail = NULL;
}

void insertTail(LinkedList &lst, int x) {
	Node *p = createNode(x);
	if(lst.head == NULL) {
		lst.head = lst.tail = p;
	} else {
		lst.tail->next = p;
		lst.tail = p;
	}
}
