#include <bits/stdc++.h>
using namespace std;
const int INF = 2049;
const int MAX = 101;
double dist[MAX][MAX];
int x[MAX];
int y[MAX];
int N;
double getDistance(int i, int j) {
  return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

void FloydWarshall() {
  for(int k=0; k<N; k++) {
    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

int main() {
  int T, count = 1;
  cin >> T;
  while(T--) {
    cin >> N;
    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
        dist[i][j] = INF;
        if(i == j) dist[i][j] = 0;
      }
    }
  
    for(int i=0; i<N; i++) {
      cin >> x[i] >> y[i];
    }  

    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
        double d = getDistance(i, j);
        if(d <= 10)
          dist[i][j] = d;
      }
    }

    FloydWarshall();
    double res = 0;

    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
        res = max(res, dist[i][j]);
      }
    }
    cout << "Case #" << count++ << ":" << endl;
    if(res != INF)
      cout << fixed << setprecision(4) << res << endl; 
    else
      cout << "Send Kurdy" << endl;
    cout << endl;
  }
  return 0;
}
