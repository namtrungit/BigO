#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int p, c, cnt = 1;
  queue<int> q1;
  while(true) {
    cin >> p >> c;
    if(p == 0 && c == 0) break;
    vector<int> list;
    for(int i=1; i<=min(p, c); i++)
      q1.push(i);
    cout << "Case " << cnt++ << ":" << endl;
    char cmd;
    int x;
    for(int i=0; i<c; i++) {
      cin >> cmd;
      if(cmd == 'N') {
        int pick = q1.front();
        cout << q1.front() << endl;
        q1.pop();
        q1.push(pick);
      } else if(cmd == 'E') {
        cin >> x;
        int n = q1.size();
        q1.push(x);
        for(int j=0; j<n; j++) {
          int temp = q1.front();
          q1.pop();
          if(temp != x) {
            q1.push(temp);
          }
        }
      }
    }
    while(!q1.empty()) {
      q1.pop();
    }
  }
}
