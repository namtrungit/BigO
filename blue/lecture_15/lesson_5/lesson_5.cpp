#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 105;
const int INF = 1e9;
vector<pair<int, int>> graph[MAX];
int dist[MAX];
bool visisted[MAX];
int path[MAX];
struct Edge {
  int u, v, w;
};
int test, n, m, u, v, w;
vector<Edge> save, tmp;
struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
    return a.second > b.second;
  }
};

int prim(int src) {
  for(int i=1; i<=n; i++) {
    dist[i] = INF;
    visisted[i] = false;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
  pq.push(make_pair(src, 0));
  dist[src] = 0;
  path[src] = src;
  while(!pq.empty()) {
    int u = pq.top().first;
    visisted[u] = true;
    int size = graph[u].size();
    for(int i=0; i<size; i++) {
      int v = graph[u][i].first;
      int w = graph[u][i].second;
      if(!visisted[v] && dist[v] > w) {
        dist[v] = w;
        path[v] = u;
        pq.push(make_pair(v, w));
      }
    }
  }

  int res = 0;
  for(int i=1; i<=n; i++) {
    if(dist[i] == INF) return -1;
    res += dist[i];
  }
  return res;
}

int main() {
  cin >> test;
  while(test--) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
      graph[i].clear();
    }
    for(int i=0; i<m; i++) {
      cin >> u >> v >> w;
      graph[u].push_back(make_pair(v, w));
      graph[v].push_back(make_pair(u, w));

    }   
    int min = prim(1);
    cout << min << endl;
  }
  return 0;
}
