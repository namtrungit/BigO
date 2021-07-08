#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 10005
const int INF = 1e9+7;
vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
vector<string> cities;

int getIndex(string name) {
  for(int i=0; i<cities.size(); i++) {
    if(name == cities[i]) {
      return i;
    }
  }
  return -1;
}

struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b ) const {
    return a.second > b.second;
  }
};

void Dijkstra(int s, int f) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
  pq.push(make_pair(s, 0));
  dist[s] = 0;
 
  while (!pq.empty()) {
    pair<int, int> top = pq.top();
    pq.pop();
 
    int u = top.first;
    int w = top.second;
 
    if (u == f) {
      break;
    }
 
    for (pair<int, int> &neighbor : graph[u]) {
      if (w + neighbor.second < dist[neighbor.first]) {
        dist[neighbor.first] = w + neighbor.second;
        pq.push(make_pair(neighbor.first, dist[neighbor.first]));
      }
    }
  }
}

int main() {
  int T, N, Q;
  int v, w, neighbors;
  string sCity, fCity, city;
  cin >> T;
  while(T--) {
    cin >> N;

    for(int i=1; i<=N; i++) {
      graph[i].clear();
    }

    cities.clear();

    for(int u = 1; u <= N; u++) {
      cin >> city >> neighbors;
      cities.push_back(city);

      for(int i = 0; i < neighbors; i++) {
        cin >> v >> w;
        graph[u].push_back(make_pair(v, w));
      }
    }

    cin >> Q;

    for(int i=0; i<Q; i++) {
      cin >> sCity >> fCity;
      int s = getIndex(sCity)+1;
      int f = getIndex(fCity)+1;
      dist = vector<int> (N+1, INF);
      Dijkstra(s, f);
      cout << dist[f] << endl;
    }
  }
}
