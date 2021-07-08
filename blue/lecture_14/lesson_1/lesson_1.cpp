#include<iostream>
#include<string>
using namespace std;

#define MAX 26
struct Node {
  Node* child[MAX];
  int maxLength;
};

Node *newNode() {
  Node *node = new Node;
  node->maxLength = 0;
  for(int i=0; i<MAX; i++) {
    node->child[i] = NULL;
  }
  return node;
}

void addWord(struct Node *root, string s, int weight) {
  int ch;
  struct Node *temp = root;
  for(int i=0; i<s.size(); i++) {
    ch = s[i] - 'a';
    if(temp->child[ch] == NULL) {
      temp->child[ch] = newNode();
    }
    temp->maxLength = max(weight, temp->maxLength);
    temp = temp->child[ch];
  }
}

int findWord(Node *root, string s) {
  int ch;
  struct Node *temp = root;
  for(int i=0; i<s.size(); i++) {
    ch = s[i] - 'a';
    if(temp->child[ch] == NULL) {
      return -1;
    }
    temp = temp->child[ch];
  }
  return temp->maxLength;
}

int main() {
  int N, Q, weight;
  string s;
  cin >> N >> Q;
  Node *root = new Node();
  for(int i=0; i<N; i++) {
    cin >> s >> weight;
    addWord(root, s, weight);
  }

  for(int i=0; i<Q; i++) {
    cin >> s;
    cout << findWord(root, s) << endl;
  }
  return 0;
}
