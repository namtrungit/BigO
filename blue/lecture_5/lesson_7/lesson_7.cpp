#include <iostream>
#include <queue>
#define MAX 501
using namespace std;

int N, M;
char a[MAX][MAX];
struct Cell {
  int x, y;
};
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

bool isValid(int x, int y) {
  return x >= 0 && y >=0 && x < N && y < M;
}

int BFS(Cell s, Cell e) {
  queue<Cell> q;
  q.push(s);
  a[s.x][s.y] = 'X';
  while(!q.empty()) {
    Cell u = q.front();
    q.pop();
    for(int i=0; i<4; i++) {
      int x = u.x+dr[i];
      int y = u.y+dc[i];
      if(e.x == x && e.y == y && a[x][y] == 'X') {
          return 1;
      }
      if(isValid(x, y)) {
        if(a[x][y] == '.') {
          a[x][y] = 'X';
          q.push((Cell) {x, y});
        }
      }
    }
  }
  return 0;
}

int main() {
  cin >> N >> M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> a[i][j];
    }
  }
  Cell s, e;
  cin >> s.x >> s.y;
  cin >> e.x >> e.y;
  s.x -= 1;
  s.y -= 1;
  e.x -= 1;
  e.y -= 1;
  cout <<  ( BFS(s, e)  ? "YES" : "NO" );
  return 0;
}
