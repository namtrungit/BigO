#include<iostream>
#include<vector>
using namespace std;
#define MAX 10005

int visisted[MAX];
int path[MAX];
int N, M;
vector<int> graph[MAX];

bool DFS(int u) {
  visisted[u] = 1;
  for(int &v: graph[u]) {
    if(visisted[v] == 1) {
      return true;
    } else if(visisted[v] == 0) {
      if(DFS(v))
        return true;
    }
  }
  visisted[u] = 2;
  return false;
}

int main() {
  int T, u, v;
  cin >> T;
  while(T--) {
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
       graph[i].clear();
       visisted[i] = 0;
    }
    for(int i=0; i<M; i++) {
      cin >> u >> v;
      graph[u].push_back(v);
    }   
    bool isLoop = false;
    for(int i=1; i<=N; i++) {
      if(visisted[i] == 0) {
        isLoop = DFS(i);
        if(isLoop) break;
      }
    }

    if(isLoop) 
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
