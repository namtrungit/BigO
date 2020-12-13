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

bool isPrime(int n) {
	if(n < 2) {
		return false;
	}
	int count = 0;
	for(int i=2; i<=n; i++){
		if(n%i == 0) {
			count++;
		}
	}
	if(count == 1) {
		return true;
	}
	return false;
}

int countPrime(LinkedList lst) {
	Node *current = lst.head;
	int count = 0;
	while(current != NULL) {
		if(isPrime(current->data)) {
			count++;
		}
		current = current->next;
	}
	return count;
}

int main() {
	LinkedList lst;
	init(lst);
	while(true) {
		int n;
		cin >> n;
		if(n == -1) {
			break;
		}
		insertTail(lst, n);
	}
	cout << countPrime(lst);
	return 0;
}
