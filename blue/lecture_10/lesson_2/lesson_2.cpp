#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define MAX 205
const int INF = 1e9;
struct Edge {
  int source;
  int target;
  int weight;
  Edge(int source = 0, int target = 0, int weight = 0) {
    this->source = source;
    this->target = target;
    this->weight = weight;
  }
};
Edge graph[MAX*MAX];
int dist[MAX];
int points[MAX] = { 0 };
int T, N, M, u, v, w, Q, a;

int calculate(int x, int y) {
  return pow(points[y] - points[x], 3);
}

void BellManFord() {
  int u, v, w;
  fill(dist, dist + (N + 1), INF);
  dist[1] = 0;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      u = graph[j].source;
      v = graph[j].target;
      w = graph[j].weight;
      if(dist[u] != INF) {
        dist[v] = min(dist[v], dist[u] + w);
      }
    }
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      u = graph[j].source;
      v = graph[j].target;
      w = graph[j].weight;
      if(dist[u] != INF && (dist[u] + w < dist[v])) {
        dist[v] = -INF;
      }
    }
  }
}

int main() {
  cin >> T;
  int count = 1;
  while(T--) {
    cin >> N;
    for(int i=1; i<=N; i++) {
      cin >> points[i];
    }
    cin >> M;
    for(int i=0; i<M; i++) {
      cin >> u >> v;
      graph[i] = Edge(u, v, calculate(u, v));
    }
    BellManFord();
    cin >> Q;
    cout << "Case " << count << ":" << endl;
    for(int i=0; i<Q; i++) {
      cin >> a;
      if(dist[a] != INF && dist[a] >= 3)
        cout << dist[a] << endl;
      else
        cout << "?" << endl;
    }
    count++;
  }
}
