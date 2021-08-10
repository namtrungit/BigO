#include<iostream>
#include<string>
using namespace std;
const int MAX = 26;
struct Node {
  Node *child[MAX];
  int count;
};

Node *createNode() {
  Node *node = new Node();
  node->count = 0;
  for(int i=0; i<MAX; i++) {
    node->child[i] = nullptr;
  }
  return node;
}

void addWord(Node *root, string s) {
  int ch;
  Node *temp = root;
  for(int i=0; i<s.size(); i++) {
    ch = s[i] - 'a';
    if(temp->child[ch] == nullptr) {
      temp->child[ch] = createNode();
    }
    temp = temp->child[ch];
    temp->count++;
  }
}

int findWord(Node *root, string s) {
  int ch;
  Node *temp = root;
  for(int i=0; i<s.size(); i++) {
    ch = s[i] - 'a';
    if(temp->child[ch] == nullptr) {
      return 0;
    }
    temp = temp->child[ch];
  }
  return temp->count;
}

int main() {
  int step;
  string action, word;
  cin >> step;
  Node *root = createNode();
  while(step--) {
    cin >> action >> word;
    if(action == "add") {
      addWord(root, word);
    } else {
      cout << findWord(root, word) << endl;
    }
  }
  return 0;
}
