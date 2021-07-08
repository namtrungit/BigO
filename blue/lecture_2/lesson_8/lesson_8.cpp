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
  int bob_count=0, alice_count=0;
  int bob_time=0, alice_time=0;
  int i=0, j=n-1;

  while(i<=j) {
    int alice_current_time = alice_time+a[i];
    int bob_current_time = bob_time+a[j];
    if(alice_current_time <= bob_current_time) {
      alice_time = alice_current_time;
      alice_count++;
      i++;
    } else {
      bob_time = bob_current_time;
      bob_count++;
      j--;
    }
  }
  cout << alice_count << ' ' << bob_count;
  return 0;
}

