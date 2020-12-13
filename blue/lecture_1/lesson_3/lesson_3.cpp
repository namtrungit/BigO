#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  int result = 0;
  bool isBreak = false;
  for(int i=0; i<n; i++) {
    if(a[i] - result > 15) {
      result += 15;
      isBreak = true;
      break;
    } else {
      result = a[i];
    }
  }
  
  if(!isBreak) {
    if(result+15 <= 90) {
      cout << result+15;
    } else {
      cout << 90;
    }
    return 0;
  }
  cout << result;
}
