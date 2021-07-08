#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
#define MAX 10005

bool visisted[MAX];
vector<int> graph[MAX];
int N, M;

int DFS(int x) {
  memset(visisted, false, sizeof(visisted)); // Clear visisted
  stack<int> s;
  visisted[x] = true;
  s.push(x);
  int countBoom = 0;
  while(!s.empty()) {
    int u = s.top();
    s.pop();
    countBoom++;
    for(int &v : graph[u]) {
      if(!visisted[v]) {
        visisted[v] = true;
        s.push(v);
      }
    }
  }
  return countBoom;
}

int main() {
  int u, v;
  cin >> N >> M;
  for(int i=0; i<M; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
  }
  int maxBoom = 0;
  for(int i=1; i<=N; i++) {
    maxBoom = max(maxBoom, DFS(i));
  }
  cout << maxBoom;
  return 0;
}
