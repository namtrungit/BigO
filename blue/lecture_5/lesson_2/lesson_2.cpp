#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define MAX 21

struct Cell {
  int x, y;
};
string maze[MAX];
bool visisted[MAX][MAX];
int T, N, M;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { -1, 1, 0, 0 };

bool isValid(int x, int y) {
  return x >= 0 && x < N && y >= 0 && y < M;
}

bool BFS(Cell s, Cell e) {
  queue<Cell> q;
  visisted[s.x][s.y] = true;
  q.push(s);
  while(!q.empty()) {
    Cell u = q.front();
    q.pop();
    if(u.x == e.x && u.y == e.y) {
      return true;
    }
    for(int i=0; i<4; i++) {
      int x = u.x + dr[i];
      int y = u.y + dc[i];
      if(isValid(x, y) && !visisted[x][y] && maze[x][y] == '.') {
        visisted[x][y] = true;
        q.push((Cell) { x, y });
      }
    }
  }
  return false;
}

int main() {
  cin >> T;
  while(T--) {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
      cin >> maze[i];
    }
    vector<Cell> entrances;
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        visisted[i][j] = false; // reinitial value;
        if(maze[i][j] == '.' && (i==0 || j==0 || i==N-1 || j==M-1)) {
          entrances.push_back((Cell) { i, j });
        }
      }
    }

    if(entrances.size() != 2) {
      cout << "invalid";
    } else {
      Cell s = entrances[0];
      Cell e = entrances[1];
      cout << (BFS(s,e) ? "valid" : "invalid");
    }
    cout << endl;
  }
  return 0;
}
