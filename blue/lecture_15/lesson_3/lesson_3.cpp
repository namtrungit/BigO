#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 1005;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> graph[MAX];
int dist[MAX];
bool visisted[MAX];
struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
    return a.second > b.second;
  }
};

void prim(int s) {
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
}

int main() {
  int t, p, n, m, a, b, c;
  cin >> t;
  while(t--) {
    cin >> p >> n >> m;
    for(int i=1; i<=n; i++) {
      graph[i].clear();
      dist[i] = INF;
      visisted[i] = false;
    }

    for(int i=0; i<m; i++) {
      cin >> a >> b >> c;
      graph[a].push_back(make_pair(b, c));
      graph[b].push_back(make_pair(a, c));
    }
    prim(1);
    int res = 0;
    for(int i=1; i<=n; i++) {
      res += dist[i];
    }
    cout << res*p << endl;
  }
  return 0;
}
