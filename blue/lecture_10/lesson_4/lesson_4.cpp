#include<iostream>
#include <iomanip>
using namespace std;
#define MAX 105
const int INF = 1e9;
struct Edge {
  int source;
  int target;
  double weight;
};
Edge graph[MAX*MAX];
double prob[MAX];
int N, M;

void BellManFord() {
  fill(prob, prob + (N + 1), -1.0);
  prob[1] = 1.0;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      int u = graph[j].source;
      int v = graph[j].target;
      double w = graph[j].weight;

      prob[u] = max(prob[u], prob[v] * w);
      prob[v] = max(prob[v], prob[u] * w);
    }
  }
}

int main() {
  int u, v, w;
  while(cin >> N, N != 0) {
    cin >> M;
    for(int i=0; i<M; i++) {
      cin >> u >> v >> w;
      graph[i] = Edge {u, v, w / 100.0};
    }
    BellManFord();
    cout << fixed << setprecision(6) << prob[N] * 100.0 << " percent" << endl;
  }
  return 0;
}
