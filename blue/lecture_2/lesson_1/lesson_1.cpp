#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
int fre[MAX];

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  int j = 0;
  int uniq = 0;
  for(int i=0; i<n; i++) {
    if(fre[a[i]] == 0) {
      uniq++;
    }
    fre[a[i]]++;
    while(uniq == k) {
      fre[a[j]]--;
      if(fre[a[j]] == 0) {
        cout << j+1 << " " << i+1;
        return 0;
      }
      j++;
    }
  }

  cout << "-1 -1";
  return 0;
}
