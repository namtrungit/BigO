#include<iostream>
using namespace std;
const int MAX_N = 105;
const int MAX_M = 1005;
const int INF = 1e9;

struct Edge {
  int source, target, weight;
};

int dist[MAX_N];
Edge graph[MAX_M];
int N, M, T;

bool BellManFord(int s) {
  fill(dist, dist + N + 1, -INF);
  dist[s] = 0;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      int u = graph[j].source;
      int v = graph[j].target;
      int w = graph[j].weight;
      if(dist[u] != -INF && dist[v] < dist[u] + w) {
        dist[v] = dist[u] + w;
        if(i == N - 1) {
          return true;
        }
      }
    }
  }

  return false;
}

int main() {
  int u, v, w;
  cin >> T;
  while(T--) {
    cin >> N >> M;
    for(int i=0; i<M; i++) {
      cin >> u >> v >> w;
      graph[i] = Edge { u, v, w };
    }
    bool isInfinity = BellManFord(1);
    cout << (isInfinity ? "Yes" : "No") << endl;
  }
  return 0;
}
