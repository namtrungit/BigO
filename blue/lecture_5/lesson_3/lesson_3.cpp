#include <iostream>
#include <queue>
using namespace std;
#define MAX 100000
vector<int> dist(MAX);
int N, keys[MAX];

long long BFS(int K, int R) {
  fill(dist.begin(), dist.end(), -1);
  queue<int> q;
  q.push(K);
  dist[K] = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int i=0; i<N; i++) {
      long long v = (1LL*u*keys[i])%100000;
      if(dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
        if( v == R ) {
           return dist[v];
        }
      }
    }
  }
  return -1;
}

int main() {
  int K, R;
  cin >> K >> R;
  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> keys[i];
  }
  cout << BFS(K, R);
  return 0;
}
