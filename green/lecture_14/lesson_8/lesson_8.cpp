#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

struct BST {
	Node *root;
};

void init(BST &t) {
	t.root = NULL;
}

Node* createNode(int x) {
	Node *p = new Node;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void addToNode(Node *&root, int x) {
	Node *p = createNode(x);
	if(x < root->data) {
		if(root->left == NULL) {
			root->left = p;
		} else {
			addToNode(root->left, x);
		}
	}
	else if(x > root->data) {
		if(root->right == NULL) {
			root->right = p;
		} else {
			addToNode(root->right, x);
		}
	}
}

void addToBST(BST &t, int x) {
	if(t.root == NULL) {
		Node *p = createNode(x);
		t.root = p;
	} else {
		addToNode(t.root, x);
	}
}

void printEven(Node *root) {
	if(root->left) {
		printEven(root->left);
	}
	if(root->right) {
		printEven(root->right);
	}
	if(root->data%2 == 0) {
		cout << root->data << " ";
	}
}

int main() {
	BST t;
	init(t);
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		addToBST(t, x);
	}
	printEven(t.root);
	return 0;
}
