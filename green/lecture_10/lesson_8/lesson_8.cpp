#include<iostream>
using namespace std;

struct Position {
  int x;
  int y;
  int value;
};

int main() {
  int n, m, k;
  cin >> n >> m;
  cin >> k;
  Position array[k];
  for(int i=0; i<k; i++) {
    Position p;
    cin >> p.x >> p.y >> p.value;
    array[i] = p;
  }
  int count = 0;
  for(int i=0; i<k; i++) {
    if(array[i].value > 0) count++;
  }
  cout << count << endl;
  for(int i=0; i<k; i++) {
    if(array[i].value > 0) {
      cout << array[i].x << " " << array[i].y << endl;
    }
  }
  return 0;
}
