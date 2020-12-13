#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), sort_a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
    sort_a[i] = a[i];
  }
  sort(sort_a.begin(), sort_a.end());
  int l=0, r=0;
  for(int i=0; i<n; i++) {
    if(a[i] != sort_a[i]) {
      l = i;
      break;
    }
  }

  for(int i=n-1; i>=0; i--) {
    if(a[i] != sort_a[i]) {
      r = i;
      break;
    }
  }

  for(int i=l, j=r; i < j; i++, j--) 
    swap(a[i], a[j]);
  
  if(a == sort_a) {
    cout << "yes" << endl;
    cout << l+1 << " " << r+1;
    return 0;
  }
  cout << "no";
  return 0;
}
