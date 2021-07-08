#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
#define MAX 100
const int INF = 1e9;
vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visisted[MAX];
int N, M;

struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
    return a.second > b.second;
  }
};

void prims(int src) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
  pq.push(make_pair(src, 0));
  dist[src] = 0;
  while(!pq.empty()) {
    int u = pq.top().first;
  }
}
