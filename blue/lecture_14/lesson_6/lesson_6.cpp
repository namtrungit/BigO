#include<iostream>
#include<string>
using namespace std;

struct Node {
  Node *child[10];
  bool isWord;
};

string res;

Node *createNode() {
  Node *node = new Node();
  node->isWord = false;
  for(int i=0; i<10; i++) {
    node->child[i] = nullptr;
  }
  return node;
}

bool addWord(Node *root, string s) {
  int ch;
  bool s_prefix_other = false;
  bool other_prefix_s = true;
  Node *temp = root;
  for(int i=0; i<s.size(); i++) {
    ch = s[i] - 'a';
    if(temp->child[ch] == nullptr) {
      temp->child[ch] = createNode();
      other_prefix_s = false;
    }
    temp = temp->child[ch];
    if(temp->isWord) 
      s_prefix_other = true;
  }
  temp->isWord = true;
  return (s_prefix_other || other_prefix_s);
}

int main() {
  int N;
  string s;
  Node *root = createNode();
  bool isPrefix = false;
  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> s;
    if(!isPrefix) {
      isPrefix = addWord(root, s);
      res = s;
    }
  }
  if(isPrefix) {
    cout << "BAD SET" << endl;
    cout << res << endl;
  } else {
    cout << "GOOD SET" << endl;
  }
  return 0;
}
