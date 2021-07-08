#include<iostream>
#define MAX 55
using namespace std;
int N, M, total;
bool visisted[MAX][MAX];
char graph[MAX][MAX];
const int dx[] = { 0, 0, 1, 1, 1, -1, -1, -1 };
const int dy[] = { 1, -1, 1, -1, 0, 1, -1, 0 };

bool isValid(int x, int y) {
  return x>=0 && y >=0 && x < N && y < M;
}

void DFS(int a, int b, int count) {
  total = max(total, count);
  for(int i=0; i<8; i++) {
    int x = a + dx[i];
    int y = b + dy[i];
    if(isValid(x, y) && !visisted[x][y]
        && graph[x][y] - graph[a][b] == 1) {
      // cout << count << " " << graph[a][b] << graph[x][y] << endl;
      visisted[x][y] = true;
      DFS(x, y, count+1);
      visisted[x][y] = false;
    }
  }
}

int main() {
  int T = 0;
  while(true) {
    cin >> N >> M;
    if(N == 0 && M == 0) {
      break;
    }
    T++;
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        visisted[i][j] = false;
        cin >> graph[i][j];
      }
    }
    total = 0;
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        if(graph[i][j] == 'A') {
          visisted[i][j] = true;
          DFS(i, j, 1);
        }
      }
    }

    cout << "Case " << T  << ": " << total << endl;
  }

  return 0;
}
