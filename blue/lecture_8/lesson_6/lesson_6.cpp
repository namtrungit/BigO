#include <iostream>
#include <vector>
#include <queue>
#define MAX 105
const int INF = 1e9+7;
using namespace std;

vector<pair<int, int>> graph[MAX];

struct option {
  bool operator() (const pair<int, int> &a, const pair<int ,int> &b) const {
    return a.second > b.second;
  }
};

vector<int> Dijkstra(int s, int N) {
  vector<int> dist(N, INF);
  priority_queue<pair<int,int>, vector<pair<int,int>>, option> pq;
  pq.push(make_pair(s, 0));
  dist[s] = 0;
  while(!pq.empty()) {
    pair<int, int> top = pq.top();
    pq.pop();
    int u = top.first;
    int w = top.second;
    if(dist[u] != w) {
      continue;
    }

    for(pair<int, int> &neighbor : graph[u]) {
      if(w + neighbor.second < dist[neighbor.first]) {
        dist[neighbor.first] = w + neighbor.second;
        pq.push(make_pair(neighbor.first, dist[neighbor.first]));
      }
    }
  }

  return dist;
}

int main() {
  int T, N, R, s, t;
  int count = 1;
  cin >> T;
  while(T--) {
    cin >> N;
    cin >> R;
    int u, v;
    for(int i=0; i<N; i++) {
      graph[i].clear();
    }
    for(int i=0; i<R; i++) {
      cin >> u >> v;
      graph[u].push_back(make_pair(v, 1));
      graph[v].push_back(make_pair(u, 1));
    }
    cin >> s >> t;
    vector<int> distS = Dijkstra(s, N);
    vector<int> distT = Dijkstra(t, N);
    int res = 0;
    for(int i=0; i<N; i++) {
      res = max(res, distS[i] + distT[i]);
    }
    cout << "Case " << count <<  ": " <<  res << endl;
    count++;
  }
  return 0;
}
