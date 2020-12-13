#include <iostream>
#include <queue>
using namespace std;
#define MAX 251
int N, M, cnt;
int a[MAX][MAX];
int slicks[MAX*MAX];
struct Cell {
  int x, y;
};
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

bool isValid(int x, int y) {
  return x>=0 && x<N && y>=0 && y<M;
}

void BFS(Cell s) {
  queue<Cell> q;
  q.push(s);
  a[s.x][s.y] = 0;
  int count = 1;
  while(!q.empty()) {
    Cell u = q.front();
    q.pop();
    for(int i=0; i<4; i++) {
      int x = u.x+dr[i];
      int y = u.y+dc[i];
      if(isValid(x, y) && a[x][y] == 1) {
        a[x][y] = 0;
        q.push((Cell) { x, y });
        count++;
      }
    }
  }
  slicks[count]++;
}

int main() {
  while(true) {
    cin >> N >> M;
    if(N==0 && M==0) {
      break;
    }
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        cin >> a[i][j];
        slicks[i*M + j + 1] = 0;
      }
    }
    cnt = 0;
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        if(a[i][j] == 1) {
          cnt++;
          BFS((Cell) { i, j });
        }
      }
    }

    cout << cnt << endl;
    for(int i=1; i<=N*M; i++) {
      if(slicks[i]) {
        cout << i << " " << slicks[i] << endl;
      }
    }
  }
}
