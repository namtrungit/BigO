#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define pi pair<int, int>
const int MAX = 100005;
const int INF = 1e9;
vector<pi> graph[MAX];
bool visisted[MAX];
int path[MAX];
vector<int> dist(MAX, INF);
int N, M, a, b, c, Q;
priority_queue<int> list;
priority_queue<int, vector<int>, greater<int>> Qlist;

struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
    return a.second > b.second;
  }
};

void prim(int s) {
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
        path[v] = u;
        pq.push(make_pair(v, w));
      }
    }
  }
}

void buildList() {
  for(int i=2; i<=N; i++) {
    list.push(dist[i]);
  }
}

int main() {
  cin >> N >> M;
  for(int i=0; i<M; i++) {
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }
  prim(1);
  buildList();
  cin >> Q;
  for(int i=0; i<Q; i++) {
    cin >> c;
    Qlist.push(c);
  }
  long long res = 0;
  while(!list.empty()) {
    int a = list.top();
    list.pop();
    if(!Qlist.empty() && a > Qlist.top()) {
      a = Qlist.top();
      Qlist.pop();
    }
    res += a;
  }
  cout << res;
  return 0;
}


