#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX 105
const int INF = 1e9+7;
vector<int> dist(MAX, INF);
vector<vector<pair<int,int>>> graph;

void Dijkstra(int s) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(pair<int, int> (s, 0));
  dist[s] = 0;
  while(!pq.empty()) {
    pair<int, int> top = pq.top();
    pq.pop();
    int u = top.first;
    int w = top.second;
    if(dist[u] != w) {
      continue;
    }
    int size = graph[u].size();
    for(int i=0; i<size; i++) {
      pair<int, int> neigbor = graph[u][i];
      if(w+neigbor.second < dist[neigbor.first]) {
        dist[neigbor.first] = w + neigbor.second;
        pq.push(pair<int, int> (neigbor.first, dist[neigbor.first]));
      }
    }
  }
}

int main() {
  int N, E, T, LIST, u, v, a;
  cin >> N >> E >> T >> LIST;
  graph = vector<vector<pair<int, int>>> (MAX, vector<pair<int, int>> ());
  for(int i=0; i<LIST; i++) {
    cin >> u >> v >> a;
    graph[v].push_back(pair<int, int> (u, a));
  }
  int cnt = 0;
  Dijkstra(E);
  for(int i = 1; i<=N; i++) {
    if(dist[i] <= T) {
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}
