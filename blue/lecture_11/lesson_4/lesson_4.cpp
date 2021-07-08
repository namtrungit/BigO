#include<iostream>
const int MAX = 20;
const int INF = 1e9;
using namespace std;
int dist[MAX][MAX];

void FloydWarshall() {
  for(int k=1; k<=MAX; k++) {
    for(int i=1; i<=MAX; i++) {
      for(int j=1; j<=MAX; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

// Important
string formatted(int n) {
  return (n >= 10 ? to_string(n) : " " + to_string(n));
}

int main() {
  int n, x, y, Q;
  int count = 1;
  while(true) {
    for(int i=1; i<=MAX; i++) {
      for(int j=1; j<=MAX; j++) {
        dist[i][j] = INF;
        if(i == j)
          dist[i][j] = 0;
      }
    }
    for(int i=1; i<MAX; i++) {
      if(!(cin >> n)) {
        return 0;
      }
      while(n--) {
        cin >> x;
        dist[i][x] = dist[x][i] = 1;
      }
    }
    FloydWarshall();
    cout << "Test Set #" << count++ << endl;
    cin >> Q;
    for(int i=0; i<Q; i++) {
      cin >> x >> y;
      cout << formatted(x) <<  " to " << formatted(y) << ": " << dist[x][y] << endl;
    }
    cout << endl;
  }
  return 0;
}
