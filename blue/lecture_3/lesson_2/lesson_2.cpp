#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> chores(n);
  for(int i=0; i<n; i++) {
    cin >> chores[i];
  }
  sort(chores.begin(), chores.end());
  int first = chores[b-1];  
  int second = chores[n-a];  
  if(first == second) {
    cout << 0;
    return 0;
  }
  int cnt=0;
  for(int i=first; i<second; i++)
    cnt++;
  cout << cnt;
  return 0;
}
