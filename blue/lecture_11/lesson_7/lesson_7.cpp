#include<iostream>
using namespace std;

const int MAX = 49;
int dist[MAX][MAX];
int T, N, S, E, C;

void FloydWarshall() {
  for(int k=0; k<MAX; k++) {
    for(int i=0; i<MAX; i++) {
      for(int j=0; j<MAX; j++) {
        if(i <= k && k <= j) {
          dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
}

int main() {
  cin >> T;
  while(T--) {
    cin >> N;
    for(int i=0; i<MAX; i++) {
      for(int j=0; j<MAX; j++) {
        dist[i][j] = 0;
      }
    }

    for(int i=0; i<N; i++) {
      cin >> S >> E >> C;
      if(dist[S][E] < C)
        dist[S][E] = C;
    }

    FloydWarshall();
    cout << dist[0][MAX-1] << endl;
  }
  return 0;
}
