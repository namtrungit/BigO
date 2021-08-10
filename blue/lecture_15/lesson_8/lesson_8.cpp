#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define pi pair<int, int>
#define MAX 3005
const int INF = 1e9;
int N, M, u, v, w, S;
vector<pi> graph[MAX];
vector<int> dist(MAX, INF);
bool visisted[MAX];

struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
    return a.second > b.second;
  }
};

int prim(int s) {
  priority_queue<pi, vector<pi>, option> pq;
  pq.push(make_pair(s, 0));
  dist[s] = 0;
  while(!pq.empty()) {
    int u = pq.top().first;
    visisted[u] = true;
    pq.pop();
    for(int i=0; i<graph[u].size(); i++) {
      int v = graph[u][i].first;
      int w = graph[u][i].second;
      if(!visisted[v] && dist[v] > w) {
        dist[v] = w;
        pq.push(make_pair(v, w));
      }
    }
  }
  long long res = 0;
  for(int i=1; i<=N; i++) {
    if(dist[i] != INF) 
      res += dist[i];
  }
  return res;
}
int main() {
  cin >> N >> M;
  for(int i=0; i<M; i++) {
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
  }

  cin >> S;
  cout << prim(S);
  return 0;
}
