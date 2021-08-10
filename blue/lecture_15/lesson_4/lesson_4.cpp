#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;
const int MAX = 255;
const int INF = 1e9;
vector<pair<int, int>> graph[MAX];
int dist[MAX];
bool visisted[MAX];
map<string, int> list;
int test, m, w, pos, cnt = 1;
string a, b;

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
    int size = graph[u].size();
    for(int i=0; i<size; i++) {
      int v = graph[u][i].first;
      int w = graph[u][i].second;
      if(!visisted[v] && dist[v] > w) {
        dist[v] = w;
        pq.push(make_pair(v, w));
      }
    }
  }

  long long res = 0;
  for(int i=0; i<pos; i++) {
    res += dist[i];
  }
  cout << "Case " << cnt << ": ";
  if(res >= INF) {
    cout << "Impossible" << endl;
  } else {
    cout << res << endl;
  }
}

int main() {
  cin >> test;
  while(test--) {
    cin >> m;
    list.clear();
    for(int i=0; i<m*2; i++) {
      graph[i].clear();
      dist[i] = INF;
      visisted[i] = false;
    }
    pos = 0;
    for(int i=0; i<m; i++) {
      cin >> a >> b >> w;
      if(list.find(a) == list.end()) {
        list[a] = pos++;
      }
      if(list.find(b) == list.end()) {
        list[b] = pos++;
      }
      graph[list[a]].push_back(make_pair(list[b], w));
      graph[list[b]].push_back(make_pair(list[a], w));
    }
    prim(0);
    cnt++;
  }
  return 0;
}
