#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 100005
const int INF = 1e9;
vector<pair<int, int>> graph[MAX];
struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b ) const {
    return a.second > b.second;
  }
};

vector<int> Dijkstra(int s) {
  vector<int> dist(MAX, INF);
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

    for(pair<int, int> &neighboor: graph[u]) {
      if(w + neighboor.second < dist[neighboor.first]) {
        dist[neighboor.first] = w + neighboor.second;
        pq.push(make_pair(neighboor.first, dist[neighboor.first]));
      }
    }
  }

  return dist;
}

int main() {
  int N, M, k, x;
  int u, v, w;
  int A, B;
  cin >> N >> M >> k >> x;
  vector<int> cities(k);
  for(int i=0; i<k; i++) {
    cin >> cities[i];
  }
  for(int i=0; i<M; i++) {
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
  }
  cin >> A >> B;
  vector<int> distA = Dijkstra(A);
  vector<int> distB = Dijkstra(B);
  int res = INF;
  for(int &city : cities) {
    if(distB[city] <= x) {
      res = min(res, distA[city] + distB[city]);
    }
  }

  cout << (res == INF ? -1 : res);
  return 0;
}
