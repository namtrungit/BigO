#include <iostream>
#include <vector>
using namespace std;

#define MAX 100
bool visisted[MAX];
int path[MAX];
vector<int> graph[MAX];
int V, E;

void DFS(int s) {
  visisted[s] = true;
  for(int i=0; i<graph[s].size(); i++) {
    int v = graph[s][i];
    if(!visisted[v]) {
      path[v] = s;
      DFS(v);
    }
  }
}

void printPath(int s, int f) {
  if(s == f) {
    cout << f << " ";
  }
  else {
    if(path[f] == -1) {
      cout <<  " No Path" << endl;
    } else {
      printPath(s, path[f]);
      cout << f << " ";
    }
  }
}

int main() {
  int u, v;
  cin >> V >> E;
  for(int i=0; i<E; i++){
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int s = 0;
  int f = 5;
  DFS(s);
  printPath(s, f);
  return 0;
}
