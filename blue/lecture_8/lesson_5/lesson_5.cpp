#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 10005
const int INF = 1e9+7;

vector<pair<int, int>> graph[MAX];
int dist[MAX] = { INF };

struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b ) const {
    return a.second > b.second;
  }
};

void Dijkstra(int s) {
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
        dist[neighbor.first] = w+neighbor.second;
        pq.push(make_pair(neighbor.first, dist[neighbor.first]));
      }
    }
  }
}

int main() {
  int T, n, m, s, t;
  int u, v, w;
  int count = 1;
  cin >> T;
  while(T--) {
    cin >> n >> m >> s >> t;
    for(int i=0; i<n; i++) {
      graph[i].clear();
      dist[i] = INF;
    }

    for(int i=0; i<m; i++) {
      cin >> u >> v >> w;
      graph[u].push_back(make_pair(v, w));
      graph[v].push_back(make_pair(u, w));
    }
    Dijkstra(s);
    cout << "Case #" <<  count << ": ";
    if(dist[t] == INF) {
      cout << "unreachable" << endl;
    } else cout << dist[t] << endl;
    count++;
  }
  return 0;
}
