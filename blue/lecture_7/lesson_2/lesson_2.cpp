#include <iostream>
#include <queue>
using namespace std;
int main() {
  int N;
  cin >> N;
  priority_queue< int, vector<int>, greater<int> > q, dq;
  int u, v;
  for(int i=0; i<N; i++) {
    cin >> u;
    if(u == 1) {
      cin >> v;
      q.push(v);
    } else if(u == 2) {
      cin >> v;
      dq.push(v);
    } else {
      while(!dq.empty() && q.top() == dq.top()) {
        q.pop();
        dq.pop();
      }
      cout << q.top() << endl;
    }
  }
}
