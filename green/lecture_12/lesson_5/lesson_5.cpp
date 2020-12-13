#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	int data;
	Node *next;
};

struct LinkedList {
	Node *head;
	Node *tail;
};

Node* createNode(x) {
	Node *p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}

void init(LinkedList &lst) {
	lst.head = NULL;
	lst.tail = NULL;
}

void insertTail(LinkedList &lst, x) {
	Node *p = createNode(x);
	if(lst.head == NULL) {
		lst.head = lst.tail = p;
	} else {
		lst.tail->next = p;
		lst.tail = p;
	}
}

int main() {
	LinkedList lst;
	init(lst);
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int input;
		cin >> input;
		insertTail(lst, input);
	}
}
