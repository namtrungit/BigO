#include<iostream>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;
const int MAX = 751;
const int INF = 1e9;
vector<pair<int, double>> graph[MAX];
vector<double> dist(MAX, INF);
bool visisted[MAX];
int N, M;
int x[MAX], y[MAX];
struct option {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
    return a.second > b.second;
  }
};

int calc(int i, int j) {
  return (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
}

double result() {
  double res = 0;
  for(int i=0; i<N; i++) {
    res += sqrt(dist[i]);
  }
  return res;
}

void prim(int s) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
  pq.push(make_pair(s, 0));
  dist[s] = 0;
  while(!pq.empty()) {
    int u = pq.top().first;
    pq.pop();
    visisted[u] = true;
    for(int i=0; i<graph[u].size(); i++) {
      int v = graph[u][i].first;
      int w = graph[u][i].second;
      if(!visisted[v] && dist[v] > w) {
        dist[v] = w;
        pq.push(make_pair(v, w));
      }
    }
  }
}

int main() {
  while(cin >> N) {
    for(int i=0; i<N; i++) {
      graph[i].clear();
      visisted[i] = false;
      dist[i] = INF;
    }
    int a, b;
    for(int i=0; i<N; i++) {
      cin >> a >> b;
      x[i] = a;
      y[i] = b;
    }
    cin >> M;
    bool edge[MAX][MAX] = { false };
    for(int i=0; i<M; i++) {
      cin >> a >> b;
      edge[a-1][b-1] = true;
      edge[b-1][a-1] = true;
    }

    for(int i=0; i<N-1; i++) {
      for(int j=i+1; j<N; j++) {
        if(edge[i][j]) {
          graph[i].push_back(make_pair(j, 0));
          graph[j].push_back(make_pair(i, 0));
        } else {
          int w = calc(i, j);
          graph[i].push_back(make_pair(j, w));
          graph[j].push_back(make_pair(i, w));
        }
      }
    }
    
    prim(0);
    cout << fixed << setprecision(2) << result() << endl;
  }
  return 0;
}
