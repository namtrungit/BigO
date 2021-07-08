#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 10005
const int INF = 1e9+7;
vector<pair<int, int>> graphS[MAX], graphT[MAX];
vector<int> distS(MAX, INF), distT(MAX, INF);

struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b ) const {
    return a.second > b.second;
  }
};

void Dijkstra(int s, vector<int> &dist, vector<pair<int, int>> (&graph)[MAX]) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
  pq.push(make_pair(s, 0));
  dist[s] = 0;

  while(!pq.empty()) {
    pair<int, int> top = pq.top();
    pq.pop();

    int u = top.first;
    int w = top.second;

    if(dist[u] < w) {
      continue;
    }

    for(pair<int, int> &neighbor : graph[u]) {
      if(w + neighbor.second < dist[neighbor.first]) {
        dist[neighbor.first] = w + neighbor.second;
        pq.push(make_pair(neighbor.first, dist[neighbor.first]));
      }
    }
  }
}

int main() { 
  int T, n, m, k, s, t, u, v, d;
  cin >> T;
  while(T--) {
    cin >> n >> m >> k >> s >> t;
    for(int i=1; i<=n; i++) {
      graphS[i].clear();
      graphT[i].clear();
      distS[i] = INF;
      distT[i] = INF;
    }
    for(int i=0; i<m; i++) {
      cin >> u >> v >> d;
      graphS[u].push_back(make_pair(v, d));
      graphT[v].push_back(make_pair(u, d));
    }
    Dijkstra(s, distS, graphS);
    Dijkstra(t, distT, graphT);
    int res = distS[t];
    for(int i=0; i<k; i++) {
      cin >> u >> v >> d;
      int a = distS[u] + d + distT[v];
      int b = distS[v] + d + distT[u];
      res = min(res, min(a, b));
    }
    cout << (res == INF ? -1 : res ) << endl;
  }
}
