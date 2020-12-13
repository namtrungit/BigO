#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Student {
	char id[7];
	char name[50];
	float grade;
};

struct Node {
	Student data;
	Node *left;
	Node *right;
};

struct BST {
	Node *root;
};

void init(BST &t) {
	t.root = NULL;
}

Node* createNode(Student stu) {
	Node *p = new Node;
	p->data = stu;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void addToNode(Node *&root, Student stu) {
	Node *p = createNode(stu);
	if(stu.grade < root->data.grade) {
		if(root->left == NULL) {
			root->left = p;
		} else {
			addToNode(root->left, stu);
		}
	}
	else if(stu.grade > root->data.grade) {
		if(root->right == NULL) {
			root->right = p;
		} else {
			addToNode(root->right, stu);
		}
	}
}

void addToBST(BST &t, Student stu) {
	if(t.root == NULL) {
		Node *p = createNode(stu);
		t.root = p;
	} else {
		addToNode(t.root, stu);
	}
}

void findMaxStudent(Node *root) {
	if(!root) {
		return;
	}
	if(!root->right) {
		Student stu = root->data;
		cout << stu.id << " " << stu.name << " " << stu.grade;
		cout << fixed;
		cout << setprecision(2);
	}
	findMaxStudent(root->right);
}

int main() {
	BST t;
	init(t);
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		Student stu;
		cin >> stu.id >> stu.name >> stu.grade;
		addToBST(t, stu);
	}
	findMaxStudent(t.root);
	return 0;
}
