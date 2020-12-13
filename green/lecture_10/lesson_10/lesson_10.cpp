#include <iostream>
using namespace std;

struct Apple {
  int kilo = 0;
  int price = 0;
};

int main() {
  int n;
  cin >> n;
  Apple array[n];
  for(int i=0; i<n; i++) {
    Apple a;
    cin >> a.kilo >> a.price;
    array[i] = a;
  }

  Apple bestApple;
  int position = 0;
  for(int i=0; i<n; i++) {
    Apple currentApple = array[i];
    if(currentApple.kilo > bestApple.kilo) {
      bestApple = currentApple;
      position = i;
    } else if(currentApple.kilo == bestApple.kilo) {
      if(currentApple.price > bestApple.price) {
        bestApple = currentApple;
        position = i;
      }
    }
  }

  cout << position;
}
