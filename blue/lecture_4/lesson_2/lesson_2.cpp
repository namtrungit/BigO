#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
  int n;
  while(true) {
    cin >> n;
    if(n == 0) {
      return 0;
    }
    vector<int> trucks(n);
    stack<int> truck_stacks;
    for(int i=0; i<n; i++) {
      cin >> trucks[i];
    }
    int number = 1;
    for(int i=0; i<n; i++) {
      if(trucks[i] != number) {
        truck_stacks.push(trucks[i]);
      } else {
        number++;
      }
      while(!truck_stacks.empty()) {
        if(truck_stacks.top() == number) {
          number++;
          truck_stacks.pop();
        } else {
          break;
        }
      }
    }

    while(!truck_stacks.empty()) {
      if(truck_stacks.top() == number) {
        number++;
        truck_stacks.pop();
      } else break;
    }
    if(number == n+1) 
      cout << "yes" << endl;
    else cout << "no" << endl;
  }

  return 0;
}
