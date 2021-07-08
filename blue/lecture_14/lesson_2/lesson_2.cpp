#include<iostream>
#include<string>
using namespace std;

#define MAX 26
struct Node {
  Node* child[MAX];
  int totalLeaf;
};

Node *newNode() {
  Node *node = new Node();
  node->totalLeaf = 0;
  for(int i=0; i<4; i++) {
    node->child[i] = NULL;
  }
  return node;
}
