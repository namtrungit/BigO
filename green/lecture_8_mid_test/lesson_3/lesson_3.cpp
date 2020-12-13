#include<iostream>
using namespace std;

int table[9][9];

bool rowCol(int x, int y) {
  // Check Row
  for(int j=0; j<9; j++) {
    if(j != y && table[x][y] == table[x][j]) {
      return false;
    }
  }

  // Check Column
  for(int i=0; i<9; i++) {
    if(i !=x && table[x][y] == table[i][y]) {
      return false;
    }
  }

  return true;
}

bool checkBlock(int x, int y) {
  int blockX = x/3;
  int blockY = y/3;
  int count = 0;
  for(int i=3*blockX; i<3*(blockX+1); i++) {
    for(int j=3*blockY; j<3*(blockY+1); j++) {
      if(table[i][j] == table[x][y]) count++;
    }
  }

  if(count > 1)
    return false;
  return true;
}

int main() {
  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++)
      cin >> table[i][j];
  }

  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++)
      if(!checkBlock(i, j) || !rowCol(i, j)) {
        cout << "NO";
        return 0;
      }
  }
  cout << "YES";
  return 0;
}
