#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<char> dna = { 'A', 'C', 'G', 'T' };
int res;
struct Node {
  struct Node *child[4];
  int count = 0;
};

struct Node *createNode() {
  struct Node *node = new Node;
  node->count = 0;
  for(int i=0; i<4; i++) {
    node->child[i] = nullptr;
  }
  return node;
}

void addWord(Node *root, string s) {
  Node *temp = root;
  for(int i=0; i<s.size(); i++) {
    int ch = find(dna.begin(), dna.end(), s[i]) - dna.begin();
    int len = i+1;
    if(temp->child[ch] == nullptr) {
      temp->child[ch] = createNode();
    }
    temp = temp->child[ch];
    temp->count++;
    res = max(res, temp->count*len);
  }
}

int main() {
  int T, N;
  string s;
  cin >> T;
  int cnt = 1;
  while(T--) {
    cin >> N;
    Node *root = createNode();
    res = 0;
    for(int i=0; i<N; i++) {
      cin >> s;
      addWord(root, s);
    }

    cout << "Case " << cnt++ << ": " << res << endl;
  }
  return 0;
}
