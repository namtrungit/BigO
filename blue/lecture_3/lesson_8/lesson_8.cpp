#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1e6+5;

struct Point {
  int x;
  int y;
  bool operator < (const Point& another) {
    return ( x < another.x ||
        (x == another.x && y < another.y ));
  }
};
bool fre_x[MAX], fre_y[MAX];
int main() {
  int x, y;
  vector<int> uniq_x, uniq_y;
  vector<Point> point;

  for(int i=0; i<8; i++) {
    cin >> x >> y;
    point.push_back({x, y});
    if(!fre_x[x]) {
      fre_x[x] = true;
      uniq_x.push_back(x);
    }
    if(!fre_y[y]) {
      fre_y[y] = true;
      uniq_y.push_back(y);
    }
  }

  if(uniq_x.size() != 3 && uniq_y.size() != 3) {
    cout << "ugly";
    return 0;
  }
  sort(uniq_x.begin(), uniq_x.end());
  sort(uniq_y.begin(), uniq_y.end());
  sort(point.begin(), point.end());
  int index = 0;
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      if( i==j && i==1 ) {
        continue;
      }
      else if(uniq_x[i] == point[index].x 
          && uniq_y[j] == point[index].y) {
        index++;
      } else {
        cout << "ugly";
        return 0;
      }
    }
  }

  cout << "respectable";
  return 0;
}
