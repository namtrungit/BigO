#include<iostream>
using namespace std;
const int MAX_N = 1005;
const int MAX_M = 5005;
const int INF = 1e9;
struct Edge {
  int source;
  int target;
  int weight;
};
int dist[MAX_N];
Edge graph[MAX_M];
int n, m, q, s;

void BellManFord(int s) {
  fill(dist, dist + n + 1, INF);
  dist[s] = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      int u = graph[j].source;
      int v = graph[j].target;
      int w = graph[j].weight;
      if(dist[u] != INF) {
        dist[v] = min(dist[u] + w, dist[v]);
      }
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      int u = graph[j].source;
      int v = graph[j].target;
      int w = graph[j].weight;
      if(dist[u] != INF && dist[u] + w < dist[v]) {
        dist[v] = -INF;
      }
    }
  }
}

int main () {
  int u, v, w, f;
  while(cin >> n, n != 0) {
    cin >> m >> q >> s;
    for(int i=0; i<m; i++) {
      cin >> u >> v >> w;
      graph[i] = Edge { u, v, w };
    }
    BellManFord(s);
    while(q--) {
      cin >> f;
      if(dist[f] == INF) {
        cout << "Impossible" << endl;
      } else if(dist[f] == -INF) {
        cout << "-Infinity" << endl;
      } else cout << dist[f] << endl;
    }
    cout << endl;
  }
}
