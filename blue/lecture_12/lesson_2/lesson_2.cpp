#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, N, M, price;

int find_total_pizza(const vector<int> &a, int pizza_price) {
  int top = 0;
  int bottom = N-1;
  int cnt = 0;
  while(top < bottom) {
    int pair = a[top] + a[bottom];
    if(pizza_price == pair) {
      top++;
      bottom--;
      cnt++;
    }
    else if(pizza_price > pair) top++;
    else bottom--;
  }
  return cnt;
}

int main() {
  cin >> T;
  while(T--) {
    cin >> N >> M;
    vector<int> prices;
    for(int i=0; i<N; i++) {
      cin >> price;
      prices.push_back(price);
    }
    sort(prices.begin(), prices.end());
    cout << find_total_pizza(prices, M) << endl;
  }
}
