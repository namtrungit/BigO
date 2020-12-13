#include <iostream>
#include <queue>
using namespace std;

int main() {
  while(true) {
    int n, next;
    cin >> n;
    queue<int> numbers;
    if(n == 0) break;
    for(int i=1; i<n+1; i++) 
      numbers.push(i);
    
    cout << "Discarded cards:";
    while(numbers.size() > 1) {
      if(numbers.size() == 2) 
       cout << " " << numbers.front(); 
      else
       cout << " " << numbers.front() << ",";
      numbers.pop();
      next = numbers.front();
      numbers.pop();
      numbers.push(next);
    }
    cout << endl;
    cout << "Remaining card: " << numbers.front() << endl;
  }
}
