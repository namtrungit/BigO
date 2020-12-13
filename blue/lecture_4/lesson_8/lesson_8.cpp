#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  int n, cnt;
  string s;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> s;
    cnt = 0;
    stack<char> list;
    int length = s.length();
    for(int j=0; j<length; j++) {
      if(s[j] == '<') {
        list.push(s[j]);
      } 
      else if (list.empty()) {
        break;
      }
      else {
        list.pop();
        cnt = (list.empty() ? j+1 : cnt);
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
