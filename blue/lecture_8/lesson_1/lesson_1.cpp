#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 501
const int INF = 1e9;
vector<int> dist(MAX, INF);
vector<vector<pair<int,int>>> graph;

void Dijkstra(int s) {
  priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
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
    int size = graph[u].size();
    for(int i=0; i<size; i++) {
      pair<int, int> neighbor = graph[u][i];
      if(w + neighbor.second < dist[neighbor.first]) {
        dist[neighbor.first] = w + neighbor.second;
        pq.push(pair<int, int> (neighbor.first, dist[neighbor.first]));
      }
    }
  }
}

int main() {
  int n, x, y, a, s, vector_total, b;
  graph = vector<vector<pair<int, int>>> (MAX, vector<pair<int, int>> ());
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> x >> y >> a;
    graph[x].push_back(pair<int, int> (y, a));
    graph[y].push_back(pair<int, int> (x, a));
  }
  cin >> s;
  Dijkstra(s);
  cin >> vector_total;
  for(int i=0; i<vector_total; i++) {
    cin >> b;
    if(dist[b] == INF)
      cout << "NO PATH" << endl;
    else
      cout << dist[b] << endl;
  }
  return 0;
}
