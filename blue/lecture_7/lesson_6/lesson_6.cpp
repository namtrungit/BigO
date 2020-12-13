#include <iostream>
#include <queue>
using namespace std;

int main() {
  int N, a, x;
  cin >> N;
  priority_queue<int> pq_max;
  priority_queue<int, vector<int>, greater<int>> pq_min;
  while(N--) {
    cin >> a;
    if(a == 1) {
      cin >> x;
      int size = pq_max.size() + pq_min.size() + 1;
      int reqs = size/3;
      if(!pq_min.empty() && x > pq_min.top()) { // O(logN)
        int temp = pq_min.top();
        pq_min.pop();
        pq_max.push(temp);
        pq_min.push(x);
      } else {
        pq_max.push(x);
      }
      while(!pq_max.empty() && reqs > pq_min.size()) { // O(logN);
        pq_min.push(pq_max.top());
        pq_max.pop();
      }
    } else {
      if(pq_min.size() == 0) {
        cout << "No reviews yet" << endl;
      } else {
        cout << pq_min.top() << endl;
      }
    }
  }
  return 0;
}
