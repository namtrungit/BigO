#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a, b, k, m;
  vector<int> array_a;
  vector<int> array_b;
  cin >> a >> b;
  cin >> k >> m;
  for(int i=0; i<a; i++) {
    int x;
    cin >> x;
    array_a.push_back(x);
  }
  for(int i=0; i<b; i++) {
    int x;
    cin >> x;
    array_b.push_back(x);
  }

  for(int i=0; i<k; i++) {
    for(int j=b-m; j<b; j++) {
      if(array_a[i] >= array_b[j]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
