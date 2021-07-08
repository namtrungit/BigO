#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 505
const int INF = 1e9;
vector<pair<int, int>> graph[MAX], graphS[MAX], graphD[MAX];
struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b ) const {
    return a.second > b.second;
  }
};

vector<int> Dijkstra(int s, vector<pair<int, int>> (&graph)[MAX]) {
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

    for(pair<int, int> &neighboor : graph[u]) {
      if(w + neighboor.second < dist[neighboor.first]) {
        dist[neighboor.first] = w + neighboor.second;
        pq.push(make_pair(neighboor.first, dist[neighboor.first]));
      }
    }
  }
  return dist;
}

int main() {
  int N, M, S, D, u, v, w;
  while(true) {
    cin >> N >> M;
    if(N == 0 && M==0) break;
    for(int i=0; i<N; i++) {
      graphS[i].clear();
      graphD[i].clear();
      graph[i].clear();
    }
    cin >> S >> D;
    for(int i=0; i<M; i++) {
      cin >> u >> v >> w;
      graphS[u].push_back(make_pair(v, w));
      graphD[v].push_back(make_pair(u, w));
    }
    vector<int> distS = Dijkstra(S, graphS);
    vector<int> distD = Dijkstra(D, graphD);
    int shortPath = distS[D];
    for(int u=0; u<N; u++) {
      for(pair<int, int> &neighboor : graphS[u]) {
        int v = neighboor.first;
        int w = neighboor.second;
        if(distS[u] + w + distD[v] != shortPath) {
          graph[u].push_back(neighboor);
        }
      }
    }
    vector<int> dist = Dijkstra(S, graph);

    cout << (dist[D] == INF ? -1 : dist[D]) << endl;
  }
  return 0;
}
