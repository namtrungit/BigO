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

int lengthX(int x) {
	return x ? lengthX(x/10) : 0;
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

bool is_doi_xung(string s, int first, int second) {
	if(first < 0) {
		return true;
	}
	if(string[first] == string[second]) {
		first--;
		second++;
		is_doi_xung(string, first, second);
	}
	return false;
}

bool doixung(int x) {
	int length = lengthX(x);
	int first, second;
	int p = length/2;
	first = p-1;
	if(length%2 == 0) {
		second = p;
	} else {
		second = p+1; 
	}
	string s = to_string(x);
	bool check = is_doi_xung(s,first,second);
	return check;
}

void coutFunction(LinkedList lst) {
	Node *current = lst.head;
	int i = 0;
	while(current != NULL) {
		if(doixung(current->data)) {
			cout << i << " ";
		}
		current = current->next;
		i++;
	}
}

int main(){
	//LinkedList lst;
	//init(lst);
	//while(true) {
	//	int x;
	//	cin >> x;
	//	if(x == -1) {
	//		break;
	//	}
	//	insertTail(lst, x);
	//}
	//coutFunction(lst);
	auto s = to_string(42);
	cout << s[0];
	return 0;
}
