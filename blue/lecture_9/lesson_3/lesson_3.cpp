#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> items(n);
  for(int i=0; i<n; i++) {
    cin >> items[i];
  }
  sort(items.begin(), items.end());
  cout << items[n/2];
  return 0;
}
