#include<iostream>
#include<stack>
#include<vector>
using namespace std;
#define MAX 1001
int N, M;
int visisted[MAX], dist[MAX];
vector<int> graph[MAX];

void DFS(int s) {
  visisted[s] = true;
  for(int i=0; i<graph[s].size(); i++) {
    int v = graph[s][i];
    if(!visisted[v]) {
      dist[v] = dist[s] + 1;
      DFS(v);
    }
  }
}

int main() {
  cin >> N;
  int u, v, x;
  for(int i=0; i<N-1; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  DFS(1);
  cin >> M;
  int min_value = MAX, index_value = MAX;
  for(int i=0; i<M; i++) {
    cin >> x;
    if(dist[x] < min_value || (dist[x] == min_value && x < index_value) ) {
      min_value = dist[x];
      index_value = x;
    }
  }
  cout << index_value;
}


