#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n, b;
  long t, d, finish = 0;
  queue<long long> q;
  cin >> n >> b;
  for(int i=0; i<n; i++) {
    cin >> t >> d;
    while(!q.empty() && q.front() <= t)
      q.pop();
    int size = q.size();
    if(size <= b) {
      finish = max(t, finish) + d;
      cout << finish << " ";
      q.push(finish);
    } else {
      cout << -1 << " ";
    }
  }
  return 0;
}
