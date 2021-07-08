#include<iostream>
const int MAX = 85;
const int INF = 1e9;
using namespace std;
int dist[MAX][MAX];
int cost[MAX];
int maxCost[MAX][MAX];
int C, R, Q;
void FloydWarshall() {
  int times = 2;
  while(times--) {
    for(int k=1; k<=C; k++) {
      for(int i=1; i<=C; i++) {
        for(int j=1; j<=C; j++) {
          int maxFeast = max(maxCost[i][k], maxCost[k][j]);
          if(dist[i][j] + maxCost[i][j] > dist[i][k] + dist[k][j] + maxFeast) {
            dist[i][j] = dist[i][k] + dist[k][j];
            maxCost[i][j] = maxFeast;
          }
        }
      }
    }
  }
}

int main() {
  int u, v, w, count = 1;
  while(true) {
    cin >> C >> R >> Q;
    if(C==0) break;
    for(int i=1; i<=C; i++) {
      cin >> cost[i];
    }

    for(int i=1; i<=C; i++) {
      for(int j=1; j<=C; j++) {
        dist[i][j] = INF;
        maxCost[i][j] = max(cost[i], cost[j]);
      }
    }

    for(int i=0; i<R; i++) {
      cin >> u >> v >> w;
      dist[u][v] = dist[v][u] = w;
    }

    FloydWarshall();
    if(count > 1) {
      cout << endl;
    }

    cout << "Case #" << count++ << endl;
    while(Q--) {
      cin >> u >> v;
      cout << (dist[u][v] == INF ? -1 : dist[u][v] + maxCost[u][v]) << endl;
    }
  }
  return 0;
}
