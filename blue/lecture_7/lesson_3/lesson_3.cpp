#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n, x, a, b;
  while(true) {
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    long long ans = 0;
    if(n == 0) {
      return 0;
    }
    for(int i=0; i<n; i++) {
      cin >> x;
      pq.push(x);
    }
    while(pq.size() >= 2) {
      a = pq.top();
      pq.pop();
      b = pq.top();
      pq.pop();
      ans += 1LL*(a+b);
      pq.push(1LL*(a+b));
    }
    cout << ans << endl;
  }
  return 0;
}

