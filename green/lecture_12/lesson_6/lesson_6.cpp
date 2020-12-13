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

Node* createNode(int x) {
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

void removeHead(LinkedList &lst) {
	if(lst.head != NULL) {
		lst.head = lst.head->next;
	}
}

void coutList(LinkedList lst) {
	Node *cur = lst.head;
	while(cur != NULL) {
		cout << cur->data << " ";
		cur = cur->next;
	}
}

int main() {
	LinkedList lst;
	init(lst);
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x;
		if(x == 1)  {
			cin >> y;
			insertTail(lst, y);
		} else {
			removeHead(lst);
		} 
	}
	coutList(lst);
	return 0;
}
