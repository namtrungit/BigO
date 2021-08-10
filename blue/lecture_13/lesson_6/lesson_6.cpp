#include<iostream>
#include<set>
using namespace std;

int main() {
  int n;
  long long price, res = 1e18;
  set<long long> list;
  set<long long>::iterator nicePrice;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> price;
    nicePrice = list.upper_bound(price);
    if(nicePrice != list.end()) {
      long long lowPrice = *nicePrice - price;
      res = min(res, lowPrice);
    }
    list.insert(price);
  }
  cout << res;
  return 0;
}
