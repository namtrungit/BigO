#include<iostream>
#include<vector>
using namespace std;
#define MAX 105
const int INF = 1e9;
int n, m;
struct Edge {
  int source;
  int target;
  int weight;
  Edge(int source = 0, int target =0, int weight = 0) {
    this->source = source;
    this->target = target;
    this->weight = weight;
  }
};
vector<Edge> graph;
vector<int> dist(MAX, INF);
vector<int> path(MAX, -1);

bool BellManFord(int s) {
  int u, v, w;
  dist[s] = 0;
  for(int i=1; i<=n-1; i++) {
    for(int j=0; j<m; j++) {
      u = graph[j].source;
      v = graph[j].target;
      w = graph[j].weight;
      if(dist[u] != INF && (dist[u] + w < dist[v])) {
        dist[v] = dist[u] + w;
        path[v] = u;
      }
    }
  }

  for(int i=0; i<m; i++) {
    u = graph[i].source;
    v = graph[i].target;
    w = graph[i].weight;
    if(dist[u] != INF && (dist[u] + w < dist[v]))
      return false;
  }
  return true;
}

int main() {
  int s, t, u, v, w;
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    cin >> u >> v >> w;
    graph.push_back(Edge(u, v, w));
  }
  s=0; t=4;
  bool res = BellManFord(s);
  if(!res) {
    cout << "Graph contains negative weight circle" << endl;
  } else
    cout << dist[t] << endl;
  return 0;
}
