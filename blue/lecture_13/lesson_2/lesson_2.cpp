#include<iostream>
#include<queue>
#include<map>
#include<string>
#include<vector>
using namespace std;
vector<int> graph[500];
bool visisted[1001];
int dist[1001];

void BFS(int s) {
  queue<int> q;
  q.push(s);
  visisted[s] = true;
  dist[s] = 0;
  
  while(!q.empty()) {
    int front = q.front();
    q.pop();

    for(int i=0; i<graph[front].size(); i++) {
      int u = graph[front][i];
      if(!visisted[u]) {
        visisted[u] = true;
        dist[u] += dist[front] + 1;
        q.push(u);
      }
    }
  }
}

int main() {
  int N, pos = 1;
  string a, b, c;
  map<string, int> dev;
  map<string, int>::iterator it;

  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> a >> b >> c;
    if(!dev[a]) dev[a] = pos++;
    if(!dev[b]) dev[b] = pos++;
    if(!dev[c]) dev[c] = pos++;

    graph[dev[a]].push_back(dev[b]);
    graph[dev[a]].push_back(dev[c]);
    graph[dev[b]].push_back(dev[a]);
    graph[dev[b]].push_back(dev[c]);
    graph[dev[c]].push_back(dev[a]);
    graph[dev[c]].push_back(dev[b]);
  }

  BFS(dev["Isenbaev"]);

  for(it=dev.begin(); it!=dev.end(); it++) {
    if(it->second == 0) {
      continue;
    }
    if(!visisted[it->second]) {
      cout << it->first << " undefined" << endl;
    } else {
      cout << it->first << " " << dist[it->second] << endl;
    }
  }
}
