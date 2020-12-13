#include<iostream>
#include<stack>
#include<queue>
using namespace std;
stack<int> s;
queue<int> q;
priority_queue<int> pq;
int N, type, x;
bool is_s = true, is_q = true, is_pq = true;
int main() {
  while(cin >> N) {
    while(!s.empty()) s.pop();
    while(!q.empty()) q.pop();
    while(!pq.empty()) pq.pop();
    is_s = true; is_q = true; is_pq = true;
    for(int i=0; i<N; i++) {
      cin >> type >> x;
      if(type == 1) {
        s.push(x);
        q.push(x);
        pq.push(x);
      } else {
        if(s.empty()) {
          is_s = is_q = is_pq = false;
          continue;
        }
        if(s.top() != x)
          is_s = false;
        if(q.front() != x)
          is_q = false;
        if(pq.top() != x)
          is_pq = false;
        s.pop(); q.pop(); pq.pop();
      }
    }
    if(is_s + is_pq + is_q == 0) {
      cout << "impossible" << endl;
    } 
    else if(is_pq + is_q + is_s > 1) {
      cout << "not sure" << endl;
    }
    else if(is_s)
      cout << "stack" << endl;
    else if(is_q)
      cout << "queue" << endl;
    else
      cout << "priority queue" << endl;

  }
  return 0;
}
