#include<iostream>
#include<vector>
using namespace std;
const int MAX = 105;
const long long INF = (1LL << 30) * 100 + 7;
string monument[MAX];
struct Edge {
  int source, target;
  long long weight;
};
long long dist[MAX][MAX];
vector<Edge> graph;

int N, Q;

void BellManFord(int s) {
  dist[s][s] = 0;
  for(int i=0; i<N; i++) {
    for(Edge &edge: graph) {
      int u = edge.source;
      int v = edge.target;
      long long w = edge.weight;
      if(dist[s][u] != INF) {
        dist[s][v] = min(dist[s][v], dist[s][u] + w);
      }
    }
  }

  for(int i=0; i<N; i++) {
    for(Edge &edge: graph) {
      int u = edge.source;
      int v = edge.target;
      long long w = edge.weight;
      if(dist[s][u] != INF && dist[s][u] + w < dist[s][v]) {
        dist[s][v] = -INF;
      }
    }
  }
}

int main() {
  int u, v;
  long long w;
  int count = 1;
  while(cin >> N, N != 0) {
    graph.clear();
    for(int i=0; i<N; i++) {
      cin >> monument[i];
      for(int j=0; j<N; j++) {
        cin >> w;
        dist[i][j] = INF;
        if(i!=j && w == 0) {
          continue;
        }
        if( i==j && w>=0 ) {
          w = 0;
        }
        graph.push_back(Edge { i, j, w });
      }
    }

    for(int i=0; i<N; i++) {
      BellManFord(i);
    }
    cin >> Q;
    cout << "Case #" << count++ << ":" << endl;
    while(Q--) {
      cin >> u >> v;
      if(dist[u][v] <= -INF) {
        cout << "NEGATIVE CYCLE" << endl;
      }
      else {
        cout << monument[u] << "-" << monument[v] << " ";
        if(dist[u][v] != INF) {
          cout << dist[u][v] << endl;
        } else {
          cout << "NOT REACHABlE" << endl;
        }
      }
    }
  }
  return 0;
}
