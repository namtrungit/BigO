#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int MAX = 40;
double dist[MAX][MAX];
string currencies[MAX];
int N, M;

int findIndex(string word) {
  for(int i=0; i<N; i++) {
    if(currencies[i] == word)
      return i;
  }
  return -1;
}

void FloydWarshall() {
  for(int k=0; k<N; k++) {
    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
        dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
      }
    }
  }
}

int main() {
  string a, c;
  int count = 1;
  double b;
  while(true) {
    cin >> N;
    if(N == 0) break;
    // clear data
    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
        dist[i][j]= 0;
        if(i == j) dist[i][j] = 1;
      }
    }
    for(int i=0; i<N; i++) {
      cin >> currencies[i];
    }
    cin >> M;
    for(int i=0; i<M; i++) {
      cin >> a >> b >> c;
      dist[findIndex(a)][findIndex(c)] = b;
    }
    FloydWarshall();
    bool flag = false;
    for(int i=0; i<N; i++) {
      if(dist[i][i] > 1) {
        flag = true; 
        break;
      }
    }
    cout << "Case " << count++ << ": " << (flag ? "Yes" : "No") << endl;
  }
  return 0;
}
