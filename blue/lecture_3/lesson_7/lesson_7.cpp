#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main() {
  int k;
  cin >> k;
  vector<int> list(12);
  for(int i=0; i<12; i++) {
    cin >> list[i];
  }
  sort(list.begin(), list.end(), greater<int>());
  int total = 0;
  int cnt = 0;
  for(int i=0; i<12; i++) {
    if(total >= k) break;
    else {
      total += list[i];
      cnt++;
    }
  }
  if(cnt == 12 && total < k) {
    cout << -1;
    return 0;
  } 
  cout << cnt;
  return 0;
}
