#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#define MAX 50005
using namespace std;

struct Triad {
  int v, w;
};

int V, E, leaf;
long long dist[MAX];
long long max_dist;
vector<Triad> graph[MAX];

void DFS(int src) {
  memset(dist, -1, sizeof(dist));
  stack<int> s;
  dist[src] = 0;
  s.push(src);

  while(!s.empty()) {
    int u = s.top();
    s.pop();

    for(Triad &neighbor: graph[u]) {
      int v = neighbor.v;
      int w = neighbor.w;

      if(dist[v] == -1) {
        dist[v] = dist[u] + w;
        s.push(v);

        if(dist[v] > max_dist) {
          max_dist = dist[v];
          leaf = v;
        }
      }
    }
  }
}

int main() {
  int t, u, v, w;
  cin >> t;
  while(t--) {
    cin >> V;
    E = V - 1;
    for(int i=0; i<=V; i++) {
      graph[i].clear();
    }

    for(int i=0; i<E; i++) {
      cin >> u >> v >> w;
      graph[u].push_back((Triad) { v, w });
      graph[v].push_back((Triad) { u, w });
    }

    max_dist = 0;
    DFS(1);
    DFS(leaf);

    cout << max_dist << endl;
  }
  return 0;
}
