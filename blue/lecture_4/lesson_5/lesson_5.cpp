#include <iostream>
#include <string>
#include <stack>
using namespace std;

char isMass(char s) {
  return s == 'H' ? 1 : ( s == 'C' ? 12 : 16);
}

int main() {
  string s;
  cin >> s;
  stack<int> atom;
  for(char c : s) {
    if(isalpha(c)) {
      atom.push(isMass(c));
    } else if(isdigit(c)) {
      int top = atom.top() * (c - '0');
      atom.pop();
      atom.push(top);
    } else if(c == '(') {
      atom.push(-1);
    } else if( c == ')') {
      int sum = 0;
      while(atom.top() != -1) {
        sum += atom.top();
        atom.pop();
      }
      atom.pop();
      atom.push(sum);
    }
  }
  int res = 0;
  while(!atom.empty()) {
    res+=atom.top();
    atom.pop();
  }

  cout << res;
  return 0;
}
