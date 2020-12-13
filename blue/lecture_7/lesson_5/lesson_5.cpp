#include <iostream>
#include <queue>

using namespace std;

int main() {
  priority_queue<int> max, dmax;
  priority_queue<int, vector<int>, greater<int>> min, dmin;
  int n, k, x;
  long long cnt=0;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> k;
    while(!dmin.empty() && dmin.top() == max.top()) {
        dmin.pop();
        max.pop();
      }
    while(!dmax.empty() && dmax.top() == min.top()) {
        dmax.pop();
        min.pop();
      }
    if(k > 0) {
      for(int j=0; j<k; j++) {
        cin >> x;
        min.push(x);
        max.push(x);
      }
    } 
    // cout << max.top() << endl;
    // cout << min.top() << endl;
    // cout << max.top() - min.top() << endl;
    cnt += max.top() - min.top();
    dmax.push(max.top());
    dmin.push(min.top());
    max.pop();
    min.pop();
  }
  cout << cnt;
  return 0;
}
