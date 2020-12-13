#include <iostream>
#include <queue>
using namespace std;
int main() {
  int n, x;
  int max_1, max_2, max_3;
  priority_queue<int> pq;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> x;
    pq.push(x);
    if(i < 2) {
      cout << -1 << endl;
    } else {
      max_1 = pq.top();
      pq.pop();
      max_2 = pq.top();
      pq.pop();
      max_3 = pq.top();
      pq.pop();
      cout << 1LL*max_1*max_2*max_3 << endl;
      pq.push(max_1);
      pq.push(max_2);
      pq.push(max_3);
    }
  }
  return 0;
}
