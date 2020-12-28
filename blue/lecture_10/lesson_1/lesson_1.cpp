#include<iostream>
#include<vector>
using namespace std;
#define MAX 1005
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
vector<Edge> graph;
vector<int> dist(MAX, INF);
int Q, n, m, u, v, w;

bool BellManFord() {
  int u, v, w;
  dist[0] = 0;
  for(int i=1; i<=n-1; i++) {
    for(int j=0; j<m; j++) {
      u = graph[j].source;
      v = graph[j].target;
      w = graph[j].weight;
      if(dist[u] != INF && (dist[u] + w < dist[v])) {
        dist[v] = dist[u] + w;
      }
    }
  }
  for(int i=0; i<m; i++) {
    u = graph[i].source;
    v = graph[i].target;
    w = graph[i].weight;
    if(dist[u] != INF && (dist[u] + w < dist[v])) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> Q;
  while(Q--) {
    graph.clear();
    dist.clear();
    cin >> n >> m;
    for(int i=0; i<m; i++) {
      cin >> u >> v >> w;
      graph.push_back(Edge(u, v, w));
    }
    bool res = BellManFord();
    if(!res) {
      cout << "possible" << endl;
    } else
      cout << "not possible" << endl;
  }
  return 0;
}
