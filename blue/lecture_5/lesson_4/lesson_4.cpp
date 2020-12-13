#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Cell {
  int x, y;
};

char lands[21][21];
int visisted[21][21];
int totalLand = 0;
int N, M;
int dr[] = { 0, 0, 1, -1 };
int dc[] = { -1, 1, 0, 0 };

bool isValid(int x, int y) {
  return x >= 0 && x<N && y>=0 && y<M;
}

void BFS(Cell s) {
  queue<Cell> q;
  q.push(s);
  totalLand = 1;
  visisted[s.x][s.y] = true;
  while(!q.empty()) {
    Cell u = q.front();
    q.pop();
    for(int i=0; i<4; i++) {
      int x = u.x+dr[i];
      int y = u.y+dc[i];
      if(isValid(x, y) && lands[x][y] == '.' && !visisted[x][y]) {
        visisted[x][y] = true;
        totalLand++;
        q.push((Cell) { x, y });
      }
    }
  }
}
int main() {
  int T;
  Cell s;
  cin >> T;
  int cnt = 0;
  while(T--) {
    cnt++;
    cin >> M >> N;
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        visisted[i][j] = false; // reinitial value;
        cin >> lands[i][j];
        if(lands[i][j] == '@') {
          s.x = i;
          s.y = j;
        }
      }
    }
    BFS(s);
    cout << "Case " << cnt << ": " << totalLand << endl;
  }
  return 0;
}
