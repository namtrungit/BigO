#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist[1001];
int visisted[1001];
vector<int> graph[1001];

void BFS(int s) {
  queue<int> q;
  visisted[s] = true;
  q.push(s);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int &v : graph[u]) {
      if(!visisted[v]) {
        visisted[v] = true;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  int Q, V, E, u, v, s;
  cin >> Q;
  while(Q--) {
    for(int k=0; k<1001; k++) {
      graph[k].clear();
      dist[k] = 0;
      visisted[k] = false;
    }
    cin >> V >> E;
    for(int i=0; i<E; i++) {
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    cin >> s;
    BFS(s);
    for(int i=1; i<=V; i++) {
      if(s == i) {
        continue;
      }
      cout << ( visisted[i] ? dist[i]*6 : -1 ) << " ";
    }
    cout << endl;
  }
  return 0;
}
