#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Node { 
  struct Node *child[10];
  bool isEnd;
};

struct Node *createNode() {
  struct Node *node = new Node();
  node->isEnd = false;
  for(int i=0; i<10; i++) {
    node->child[i] = nullptr;
  }
  return node;
}

bool addWord(Node *root, string s) {
  int ch;
  Node *temp = root;
  bool s_prefix_other = false;
  bool other_prefix_s = true;
  for(int i=0; i<s.size(); i++) {
    ch = s[i] - '0';
    if(temp->child[ch] == nullptr) {
      temp->child[ch] = createNode();
      other_prefix_s = false;
    }
    temp = temp->child[ch];
    if(temp->isEnd) {
      s_prefix_other = true;
    }
  }
  temp->isEnd = true;
  return (s_prefix_other || other_prefix_s);
}

int main() {
  int T, N, cnt=1;
  string s;
  cin >> T;
  while(T--) {
    cin >> N;
    bool isPrefix = false;
    Node *root = createNode();
    for(int i=0; i<N; i++) {
      cin >> s;
      if(!isPrefix) {
        isPrefix = addWord(root, s);
      }
    }
    cout << "Case " << cnt++ << ": " << (isPrefix ? "NO" : "YES") << endl;
  }

  return 0;
}
