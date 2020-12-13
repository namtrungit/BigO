#include <iostream>
#include <cstring>
#include <iomanip> 
using namespace std;

struct Node {
	double data;
	Node *next;
};

struct LinkedList {
	Node* head;
	Node* tail;
};

void init(LinkedList &lst) {
	lst.head = NULL;
	lst.tail = NULL;
}

Node* createNode(double x) {
	Node *p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}

void insertTail(LinkedList &lst, double x) {
	Node *p = createNode(x);
	if(lst.head == NULL) {
		lst.head = lst.tail = p;
	} else {
		lst.tail->next = p;
		lst.tail = p;
	}
}

double findFirst(LinkedList lst) {
	Node *current = lst.head;
	double max = 0;
	while(current != NULL) {
		if(current->data > max) {
			max = current->data;
		}
		current = current->next;
	}
	return max;
}

double findSecond(LinkedList lst, double first) {
	double second = -1;
	if(lst.head->next == NULL) {
		return -1;
	}
	Node *current = lst.head;
	while(current != NULL) {
		if(current->data > second and current->data < first) {
			second = current->data;
		}
		current = current->next;
	}
	return second;
}

int main() {
	LinkedList lst;
	init(lst);
	double first, second;
	while(true) {
		double x;
		cin >> x;
		if(x == -1) {
			break;
		}
		insertTail(lst, x);
	}
	first = findFirst(lst);
	second = findSecond(lst, first);
	cout << setprecision(10) << second;
	return 0;
}
