#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  int count = 1, can_kill = a[n-1];
  for(int i=n-2; i>=0; i--) {
    if(can_kill == 0) 
      count++;
    else
      can_kill--;
    can_kill = max(can_kill, a[i]);
  }

  cout << count;
  return 0;
}
