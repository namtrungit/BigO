#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> graph[100001];
int cats[100001];
int count_cats[100001];
bool visisted[100001];
int N, M, u, v, cnt = 0;

void BFS() {
  for(int i=1; i<N; i++) {
    visisted[i] = false;
    count_cats[i] = 0;
  }
  queue<int> q;
  q.push(1);
  visisted[1] = true;
  if(cats[1] == 1)
    count_cats[1] = 1;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int &v : graph[u]) {
      if(!visisted[v]) {
        visisted[v] = true;
        if(cats[v] == 1) {
          count_cats[v] = count_cats[u] + 1;
        }
        if(count_cats[v] <= M) {
          if(graph[v].size() == 1) {
            cnt++;
          }
          else {
            q.push(v);
          }
        }
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for(int i=1; i<=N; i++) {
    cin >> cats[i];
  }
  for(int i=0; i<N-1; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  BFS();
  cout << cnt;
  return 0;
}
