#include<iostream>
#include<string>
using namespace std;
const int MAX = 26;
struct Node {
  Node* child[MAX];
  bool isEnd;
};

Node *createNode() {
  Node *node = new Node();
  for(int i=0; i<MAX; i++) {
    node->child[i] = nullptr;
  }
  node->isEnd = false;
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
    if(temp->isEnd)
      s_prefix_other = true;
  }
  temp->isEnd = true;

  return s_prefix_other || other_prefix_s;
}

int main() {
  int N;
  string s;
  Node *root = createNode();
  cin >> N;
  bool hasPrefix = false;
  for(int i=0; i<N; i++) {
    cin >> s;
    if(!hasPrefix) {
      hasPrefix = addWord(root, s);
    }
  }

  cout << (hasPrefix ? "vulnerable" : "non vulnerable") << endl;
  return 0;
}
