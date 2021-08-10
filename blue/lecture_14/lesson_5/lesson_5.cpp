#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int MAX = 26;

struct Node {
  Node *child[MAX];
  int leafCount;
};

Node *createNode() {
  Node *node = new Node();
  for(int i=0; i<MAX; i++) {
    node->child[i] = NULL;
  }
  node->leafCount = 0;
  return node;
}
long long startWith[MAX];
long long suffixStateCount;
void addWord(Node *root, string s) {
  int ch;
  Node *temp = root;
  for(int i=0; i<s.size(); i++) {
    ch = s[i] - 'a';
    if(temp->child[ch] == NULL) {
      temp->child[ch] = createNode();
    }
    temp = temp->child[ch];
  }
  temp->leafCount++;
}

void suffixTraversal(Node *root, int level) {
  suffixStateCount++;
  for(int i=0; i<26; i++) {
    if(root->child[i] == NULL)
      continue;
    if(level > 0)
      startWith[i]++;
    suffixTraversal(root->child[i], level+1);
  }
}

long long prefixTraversal(Node *root, int level) {
  long long result = 0;
  if(level > 0) result += suffixStateCount;
  for(int i=0; i<26; i++) {
    if(root->child[i] == NULL)
      continue;
    if(level > 0)
      result -= startWith[i];
    result += prefixTraversal(root->child[i], level+1);
  }
  return result;
}

int main() {
  Node *suffixTrie, *prefixTrie;
  int p, s;
  string str;
  while(1) {
    cin >> p >> s;
    if(!p && !s) break;
    suffixTrie = new Node();
    prefixTrie = new Node();
    for(int i=0; i<26; i++)
      startWith[i] = 0;
    suffixStateCount = 0;

    for(int i=0; i<p; i++) {
      cin >> str;
      addWord(prefixTrie, str);
    }

    for(int i=0; i<s; i++) {
      cin >> str;
      reverse(str.begin(), str.end());
      addWord(suffixTrie, str);
    }
    suffixTraversal(suffixTrie, 0);
    suffixStateCount--;
    cout << prefixTraversal(prefixTrie, 0) << endl;
  }
  return 0;
}
