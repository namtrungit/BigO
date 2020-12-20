#include<iostream>
#include<queue>
using namespace std;

int main() {
  int Q, n, m, x;
  cin >> Q;
  while(Q--) {
    cin >> n >> m;
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++) {
      cin >> x;
      pq.push(x);
      q.push(pair<int, int> (i, x));
    }
    int cnt = 0;
    while(!q.empty()) {
      if(q.front().second != pq.top()) {
        pair<int, int> temp = q.front();
        q.pop();
        q.push(temp);
      } else {
        pq.pop();
        cnt++;
        if(q.front().first == m) break;
        q.pop();
      } 
    }

    cout << cnt << endl;
  }
  return 0;
}
