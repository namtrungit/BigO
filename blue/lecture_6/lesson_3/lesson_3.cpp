#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 51
using namespace std;

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };
struct Cell {
  int x, y;
};

int N, M, K;
string graph[MAX];
bool visisted[MAX][MAX];
vector<vector<Cell>> lakes;

bool onBorder(int x, int y) {
  return x == 0 || y == 0 || x == N-1 || y == M-1;
}

bool isValid(int x, int y) {
  return x >= 0 && y >= 0 && x < N  && y < M;
}

bool orderBySide(const vector<Cell> &a, const vector<Cell> &b) {
  return a.size() < b.size();
}

void DFS(Cell cell) {
  stack<Cell> s;
  visisted[cell.x][cell.y] = true;
  s.push(cell);

  bool isOcean = false;
  vector<Cell> temp;

  while(!s.empty()) {
    Cell a = s.top();
    temp.push_back(a);
    s.pop();

    if(onBorder(a.x, a.y)) {
      isOcean = true;
    }

    for(int i=0; i<4; i++) {
      int x = a.x + dx[i];
      int y = a.y + dy[i];
      if(isValid(x, y) && graph[x][y] == '.' && !visisted[x][y]) {
        visisted[x][y] = true;
        s.push((Cell) { x, y });
      }
    }
  }
  if(!isOcean) {
    lakes.push_back(temp);
  }
}

int main() {
  cin >> N >> M >> K;
  for(int i=0; i<N; i++) {
    cin >> graph[i];
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(!visisted[i][j] && graph[i][j] == '.')
        DFS((Cell) { i, j });
    }
  }
  
  sort(lakes.begin(), lakes.end(), orderBySide);
  int sum_cell = 0;
  for(int i=0; i<lakes.size() - K; i++) {
    sum_cell+=lakes[i].size();
    for(int j=0; j<lakes[i].size(); j++) {
      Cell u = lakes[i][j];
      graph[u.x][u.y] = '*';
    }
  }

  cout << sum_cell << endl;
  for(int i=0; i<N; i++) {
    cout << graph[i] << endl;
  }
  return 0;
}
