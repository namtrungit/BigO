#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void transform(string expression) {
  stack<char> s;
  for(char sympol : expression) {
    if(isalpha(sympol)) {
      cout << sympol;
    } else if(sympol == ')') {
      cout << s.top();
      s.pop();
    } else if (sympol != '(') {
      s.push(sympol);
    }
  }
  cout << endl;
} 

int main() {
  int n;
  cin >> n;
  vector<string> strings(n);
  for(int i=0; i<n; i++) {
    cin >> strings[i];
  }

  for(int i=0; i<n; i++) {
    transform(strings[i]);
  }
  return 0;
}
