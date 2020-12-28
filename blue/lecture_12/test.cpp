#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main() {
  int a[] = {1, 1, 2 ,2 ,2 ,3 ,4 ,5 ,7};
  int n=9;
  vector<int> v(a, a+n);
  int x = 3;
  vector<int>::iterator low_value;
  low_value = lower_bound(v.begin(), v.end(), x);
  cout << *low_value << endl;
  cout << *v.begin() << endl;
  return 0;
}
