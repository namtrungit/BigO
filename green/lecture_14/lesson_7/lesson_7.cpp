#include <iostream>
#include <cstring>
#include <algorithm>
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

void sumNode(Node *root, int &sum, int x) {
	if(!root) {
		return;
	}
	if(root->data < x) {
		sum+=root->data;
	}
	sumNode(root->left, sum, x);
	sumNode(root->right, sum, x);
}

int main() {
	BST t;
	init(t);
	int n, x;
	cin >> n >> x;
	for(int i=0; i<n; i++) {
		int z;
		cin >> z;
		addToBST(t, z);
	}
	int sum = 0;
	sumNode(t.root, sum, x);
	cout << sum;
	return 0;
}
