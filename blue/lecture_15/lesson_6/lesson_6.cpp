#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int MAX = 105;
const int INF = 1e9;
vector<pair<int, int>> graph[MAX];
bool visisted[MAX];
int dist[MAX];
int path[MAX];
vector<pair<int, int>> graphDFS[MAX];
int C, S, Q;

struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
    return a.second > b.second;
  }
};

void prim(int src) {
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
        path[v] = u;
        pq.push(make_pair(v, w));
      }
    }
  }

  for(int u=2; u<=C; u++) {
    if(path[u] != -1) {
      int v = path[u];
      int w = dist[u];
      graphDFS[u].push_back(make_pair(v, w));
      graphDFS[v].push_back(make_pair(u, w));
    }
  }
}

int dfs(int s, int f, int len) {
  if(s == f) return len;
  visisted[s] = true;
  for(int i=0; i<graphDFS[s].size(); i++) {
    int v = graphDFS[s][i].first;
    int w = graphDFS[s][i].second;
    if(!visisted[v]) {
      int lenTemp = dfs(v, f, max(len, w));
      if(lenTemp != INF) return lenTemp;
    }
  }
  return INF;
}

int main() {
  int u, v, w, cnt = 1;
  while(true) {
    cin >> C >> S >> Q;
    if(C == 0 && S == 0 && Q == 0) break;
    for(int i=1; i<=C; i++) {
      graph[i].clear();
      graphDFS[i].clear();
      dist[i] = INF;
      visisted[i] = false;
      path[i] = -1;
    }

    for(int i=0; i<S; i++) {
      cin >> u >> v >> w;
      graph[u].push_back(make_pair(v, w));
      graph[v].push_back(make_pair(u, w));
    }
    // Data co the la rung do thi nen phai chay prim qua tung diem
    for(int i=1; i<=C; i++) {
      if(!visisted[i])
        prim(i);
    }

    if(cnt != 1) cout << endl;
    cout << "Case #" << cnt++ << endl;

    for(int i=0; i<Q; i++) {
      memset(visisted, false, sizeof(visisted));
      cin >> u >> v;
      int len = dfs(u, v, 0);
      if(len != INF) {
        cout << len;
      } else {
        cout << "no path";
      }
      cout << endl;
    }
  }
  return 0;
}

