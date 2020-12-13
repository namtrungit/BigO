#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> array(n);
  for(int i=0; i<n; i++) {
    cin >> array[i];
  }
  sort(array.begin(), array.end());
  int highest_tower = 1;
  int cnt_tower = 1;
  int current_tower = 1;
  for(int i=1; i<n; i++) {
    if(array[i] == array[i-1]) {
      current_tower++;
      highest_tower = max(highest_tower, current_tower);
    } else {
      cnt_tower++;
      current_tower = 1;
    }
  }
  cout << highest_tower << " " << cnt_tower;
  return 0;
}
