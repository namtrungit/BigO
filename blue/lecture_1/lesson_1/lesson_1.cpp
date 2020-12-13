#include <vector>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  int zeroCount = 0;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }

  if(n == 1) {
    if(a[0] == 1) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    return 0;
  }

  for(int i=0; i<n; i++) {
    if(a[i] == 0) {
      zeroCount++;
    }
  }

  if(zeroCount > 1) {
    cout << "NO";
  } else {
    if(zeroCount == 0) {
       cout << "NO";
    } else {
      cout << "YES";
    }
  }

  return 0;
}
