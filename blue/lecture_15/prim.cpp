#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 100
const int INF = 1e9;
vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visisted[MAX];
int N, M;

void printMST() {
  int ans = 0;
  for(int i=0; i<N; i++) {
    if(path[i] == -1) {
      continue;
    }
    ans += dist[i];
    cout << path[i] << " - " << i << ": " << dist[i] << endl;
  }
}

struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
    return a.second > b.second;
  }
};

void prims(int src) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
  pq.push(make_pair(src, 0));
  dist[src] = 0;
  while(!pq.empty()) {
    int u = pq.top().first;
    pq.pop();
    visisted[u] = true;
    for(int i=0; i<graph[u].size(); i++) {
      int v = graph[u][i].first;
      int w = graph[u][i].second;
      if(!visisted[v] && dist[v] > w) {
        dist[v] = w;
        pq.push(make_pair(v, w));
        path[v] = u;
      }
    }
  }
}

int main() {
  int u, v, w;
  cin >> N >> M;
  memset(path, -1, sizeof(path));
  for(int i=0; i<M; i++) {
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
  }
  int s = 0;
  prims(s);
  printMST();
  return 0;
}
