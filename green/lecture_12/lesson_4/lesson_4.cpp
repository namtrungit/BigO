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

void init(LinkedList &lst) {
	lst.head = NULL;
	lst.tail = NULL;
}

Node* createNode(int x){
	Node *p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
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

void appendIndex(LinkedList &lst) {
	Node *current = lst.head;
	Node *prev = lst.head;
	int i = 1;
	while(current != NULL) {
		Node *p = createNode(i);
		if(i == 1) {
			p->next = lst.head;
			lst.head = p;
		} else {
			prev->next = p;
			p->next = current;
		}
		i++;
		prev = current;
		current = current->next;
	}
}

void coutLinkedList(LinkedList &lst) {
	Node *current = lst.head;
	while(current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}
}

int main() {
	LinkedList lst;
	init(lst);
	while(true) {
		int n;
		cin >> n;
		if(n == 0) {
			break;
		}
		insertTail(lst, n);
	}
	appendIndex(lst);
	coutLinkedList(lst);
	return 0;
}
