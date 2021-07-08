#include<iostream>
#include<vector>
using namespace std;
const int INF = 1e9;
struct Edge {
  int source, target, weight;
};
int N;

void BellManFord(int N, vector<int> &dist, vector<Edge> &graph) {
  dist[1] = 0;
  for(int i=0; i<N; i++) {
    for(Edge &edge: graph) {
      int u = edge.source;
      int v = edge.target;
      int w = edge.weight;
      if(dist[u] != INF)
        dist[v] = min(dist[v], dist[u] + w);
    }
  }
}

int main() {
  cin >> N;
  vector<int> dist(N+1, INF);
  vector<Edge> graph;
  string temp;
  for(int i=2; i<=N; i++) {
    for(int j=1; j<i; j++) {
      cin >> temp;
      if(temp != "x") {
        int w = atoi(temp.c_str());
        graph.push_back({ i, j, w });
        graph.push_back({ j, i, w });
      }
    }
  }

  BellManFord(N, dist, graph);
  int res = 0;
  for(int i=1; i<=N; i++) {
    res = max(res, dist[i]);
  }
  cout << res;
  return 0;
}
