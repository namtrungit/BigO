#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define MAX 100
bool visisted[MAX];
int path[MAX];
vector<int> graph[MAX];
int V, E;

void DFS(int s) {
  for(int i=0; i<V; i++) {
    visisted[i] = false;
    path[i] = -1;
  }
  stack<int> stacks;
  visisted[s] = true;
  stacks.push(s);
  while(!stacks.empty()) {
    int u = stacks.top();
    stacks.pop();
    for(int i=0; i<graph[u].size(); i++) {
      int v = graph[u][i];
      if(!visisted[v]) {
        visisted[v] = true;
        path[v] = u;
        stacks.push(v);
      }
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
