#include<iostream>

using namespace std;

// Khai bao Node
struct Node {
  int key;
  Node *left;
  Node *right;
};

// Create 1 Node O(1)
Node* createNode(int x) {
  Node *newNode = new Node;
  newNode->key = x;
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Insert Node O(h) *h = height of tree
Node* insertNode(Node* root, int x) {
  if(root == NULL)
    return createNode(x);
  if(x < root->key)
    root->left = insertNode(root->left, x);
  else if(x > root->key)
    root->right = insertNode(root->right, x);
  return root;
}

// Init BST O(N*h)
void createTree(Node* &root, int a[], int n) {
  for(int i=0; i<n; i++) { // O(n)
    root = insertNode(root, a[i]); // O(h)
  }
}

// searchNode O(h)
Node* searchNode(Node* root, int x) {
  if(root == NULL || root->key == x)
    return root;
  if(root->key < x)
    return searchNode(root->right, x);
  return searchNode(root->left, x);
}

// Find minValueNode ở cây con bên phải
Node* minValueNode(Node* node) {
  Node* current = node;
  while(current->left != NULL)
    current = current->left;
  return current;
}

// Delete Node
Node* deleteNode(Node* &root, int x) {
  if(root == NULL)
    return root;
  if(x < root->key)
    root->left = deleteNode(root->left, x);
  else if(x > root->key)
    root->right = deleteNode(root->right, x);
  else {
    if(root->left == NULL) {
      Node *temp = root->right;
      delete root;
      return temp;
    } else if(root->right == NULL) {
      Node *temp = root->left;
      delete root;
      return temp;
    }
    Node* temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Duyet BTS
void traversalTree(Node *root) {
  if(root != NULL) {
    traversalTree(root->left);
    cout << root->key << " ";
    traversalTree(root->right);
  }
}

// Kick thuoc BTS
int size(Node* node) {
  if(node == NULL) {
    return 0;
  }
  return (size(node->left) + 1 + size(node->right));
}

//Delete Tree
void deleteTree(Node* root) {
  if(root == NULL) {
    return;
  }
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

int main() {
  Node* root(NULL);
  int a[] = {1, 4, 4, 4, 5};
  createTree(root, a, 5);
  traversalTree(root);
  return 0;
}

