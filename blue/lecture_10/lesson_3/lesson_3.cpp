#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 105
const int INF = 1e9;
vector<pair<int,int>> graph;
bool visisted[MAX];
int dist[MAX], energy[MAX];
int n, m;

bool hasPathBFS(int s, int f) {
  fill(visisted, visisted + (n+1), false);
  queue<int> q;
  visisted[s] = true;
  q.push(s);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(pair<int, int> &edge : graph) {
      if(edge.first == u) {
        int v = edge.second;
        if(!visisted[v]) {
          visisted[v] = true;
          q.push(v);
          if(v == f) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

bool BellManFord(int s, int f) {
  fill(dist, dist + (n + 1), -INF);
  dist[s] = 100;
  for(int i=1; i<=n; i++) {
    for(pair<int, int> &edge: graph) {
      int u  = edge.first;
      int v = edge.second;
      if(dist[u] > 0) {
        dist[v] = max(dist[v], dist[u] + energy[v]);
      }
    }
  }

  for(pair<int, int> &edge: graph) {
    int u = edge.first;
    int v = edge.second;
    if(dist[u] > 0 && dist[u] + energy[v] > dist[v] && hasPathBFS(u, f)) {
      return true;
    }
  }
  return dist[f] > 0;
}

int main() {
  int v;
  while(cin >> n, n != -1) {
    graph.clear();
    for(int u=1; u<=n; u++) {
      cin >> energy[u] >> m;
      for(int i=0; i<m; i++) {
        cin >> v;
        graph.push_back(make_pair(u, v));
      }
    }
    bool canGo = BellManFord(1, n);
    cout << (canGo ? "winnable" : "hopeless") << endl;
  }
  return 0;
}
