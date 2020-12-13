#include <iostream>
#include <queue>
#define MAX 251
using namespace std;
struct Cell {
  int x, y;
};
int N, M, cnt_sheep = 0, cnt_wolf = 0;
char a[MAX][MAX];
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

bool isValid(int x, int y) {
  return x>=0 && y>=0 && x<N && y<M;
}
void BFS(Cell s) {
  bool can_out = false;
  int sheep=(a[s.x][s.y] == 'k'), wolf=(a[s.x][s.y] == 'v');
  a[s.x][s.y] = '#';
  queue<Cell> q;
  q.push(s);
  while(!q.empty()) {
    Cell u = q.front();
    q.pop();
    for(int i=0; i<4; i++) {
      int x = u.x+dr[i];
      int y = u.y+dc[i];
      if(isValid(x, y)) {
        if(a[x][y] == '#')
          continue;
        else {
          if(x == 0 || x == N-1 || y == 0 || y == M-1)
            can_out = true;
          sheep += (a[x][y] == 'k');
          wolf += (a[x][y] == 'v');
          a[x][y] = '#';
          q.push((Cell) { x, y });
        }
      }
    }
  }
  if(can_out) {
    cnt_wolf += wolf;
    cnt_sheep += sheep;
  } else {
    (sheep <= wolf) ?
      cnt_wolf += wolf :
      cnt_sheep += sheep;
  }
}

int main() {
  cin >> N >> M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> a[i][j];
    }
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(a[i][j] != '#')
        BFS((Cell) { i, j });
    }
  }
  cout << cnt_sheep << " " << cnt_wolf;
  return 0;
}
