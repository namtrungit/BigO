#include <iostream>
#include <string>
using namespace std;

int countStep(int x, int y) {
  int a, b;
  if(x > y) {
    a = x-y;
    b = 26+y-x;
  } else {
    a = y-x;
    b = 26+x-y;
  }
  if(a > b)
    return b;
  return a;
}

int main() {
  string s;
  getline(cin, s);
  int result = countStep(int('a'), int(s[0]));
  for(int i=1; i<s.size(); i++) {
    result += countStep(int(s[i-1]), int(s[i]));
  }
  cout << result;
}
