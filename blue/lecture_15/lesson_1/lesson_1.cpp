#include<iostream>
#include<queue>
using namespace std;
const int MAX = 10005;
const int INF = 1e9;
vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
bool visisted[MAX];
int N, M;

struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
    return a.second > b.second;
  }
};

long long prim(int s) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
  pq.push(make_pair(s, 0));
  dist[s] = 0;
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
      }
    }
  }

  long long res = 0;
  for(int i=1; i<=N; i++) {
    if(!visisted[i]) continue;
    res += dist[i];
  }
  return res;
}

int main() {
  cin >> N >> M;
  int u, v;
  long long w;
  for(int i=0; i<M; i++) {
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
  }
  cout << prim(1) << endl;
}
