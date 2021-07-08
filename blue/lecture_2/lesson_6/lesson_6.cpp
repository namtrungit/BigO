#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10e5 + 5;
int numberList[MAX];
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  int j=0, max_length=0, diff=0;
  for(int i=0; i<n; i++) {
    if(numberList[a[i]] == 0) {
      diff++;
    }
    numberList[a[i]]++;

    while(j<n && diff > 2) {
      if(numberList[a[j]] == 1) {
        diff--;
      }
      numberList[a[j]]--;
      j++;
    }
    max_length = max(max_length, i-j+1);
  }
  cout << max_length;
  return 0;
}
