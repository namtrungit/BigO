#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define MAX 100000+5
int Q, V, E;
vector<int> graph[MAX];
bool visisted[MAX];

void DFS(int s) {
  visisted[s] = true;
  for(int i=0; i<graph[s].size(); i++) {
    int v = graph[s][i];
    if(!visisted[v]) {
      visisted[v] = true;
      DFS(v);
    }
  }
}

int main() {
  cin >> Q;
  while(Q--) {
    cin >> V; 
    for(int i=0; i<V; i++) {
      visisted[i] = false;
      graph[i].clear();
    }
    cin >> E;
    if(E == 0) {
      cout << V << endl;
      return 0;
    }
    int u, v;
    for(int i=0; i<E; i++) {
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    int cnt = 0;
    for(int i=0; i<V; i++) {
      if(!visisted[i]) {
        cnt++;
        DFS(i);
      }
    }
    cout << cnt << endl;
  }
}
