#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> cups(2*n);
  for(int i=0; i<2*n; i++) {
    cin >> cups[i];
  }
  sort(cups.begin(), cups.end());
  double m = min(1.0*cups[0], 1.0*cups[n]/2);
  double total = 3*m*n;
  cout << setprecision(9) << min(total, 1.0*w);
  return 0;
}
