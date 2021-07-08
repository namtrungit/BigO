#include<iostream>
using namespace std;
const int MAX = 501;
int dist[MAX][MAX];
long long res[MAX];
int midle[MAX];

int main() {
  int N;
  cin >> N;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      cin >> dist[i][j];
    }
  }

  for(int i=0; i<N; i++) {
    cin >> midle[i];
  }

  for(int index=N-1; index>=0; index--) {
    int k = midle[index];
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }

    for(int i=index; i<N; i++) {
      int u = midle[i];
      for(int j=index; j<N; j++) {
        int v = midle[j];
        res[index]+=dist[u][v];
      }
    }
  }

  for(int i=0; i<N; i++) {
    cout << res[i] << endl;
  }
  return 0;
}
