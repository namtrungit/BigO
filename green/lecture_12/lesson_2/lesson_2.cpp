#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	float data;
	Node *next;
};

struct LinkedList {
	Node *head;
	Node *tail;
};

void init(LinkedList &lst) {
	lst.head = NULL;
	lst.tail = NULL;
}

Node* createNode(float x) {
	Node *p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}

void insertTail(LinkedList &lst, float x) {
	Node *p = createNode(x);
	if(lst.head == NULL) {
		lst.head = lst.tail = p;
	} else {
		lst.tail->next = p;
		lst.tail = p;
	}
}

void coutLower(LinkedList &lst) {
	if(lst.head == NULL) {
		cout << 0;
	}
	Node *current = lst.head;
	while(current != NULL) {
		if(current->data < 5) {
			cout << current->data << endl;
		}
		current = current->next;
	}
}

int main() {
	LinkedList lst;
	init(lst);
	while(true) {
		float n;
		cin >> n;
		if(n == -1) {
			break;
		}
		insertTail(lst, n);
	}
	coutLower(lst);
	return 0;
}
