#include<iostream>
#include<stack>
#include <algorithm>
#define MAX 100
#include<cstring>

using namespace std;
int N, M;
bool visisted[MAX][MAX];
char graph[MAX][MAX];
string term = "ALLIZZWELL";
bool check;
const int dx[] = { 0, 0, 1, 1, 1, -1, -1, -1 };
const int dy[] = { 1, -1, 0, 1, -1, 0, 1, -1 };

struct Cell {
  int x, y;
};

bool isValid(int x, int y) {
  return x >= 0 && y >= 0 && x < N && y < M;
}

void DFS(int a, int b, int count) {
  if(count == term.size()) {
    check = true;
    return;
  }

  for(int i=0; i<8; i++) {
    int x = a + dx[i];
    int y = b + dy[i];
    if(isValid(x, y) && graph[x][y] == term[count] && !visisted[x][y]) {
      visisted[x][y] = true;
      DFS(x, y, count+1);
      visisted[x][y] = false;
    }
  }
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        cin >> graph[i][j];
        visisted[i][j] = false;
      }
    }
    check = false;
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        if(graph[i][j] == term[0] && !check) {
          DFS(i, j, 1);
        }
      }
    }

    cout << ( check ? "YES" : "NO" ) << endl;
  }
  return 0;
}
