#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  int count_1 = 0;
  int count_2 = 0;
  int i = 0;
  int j = n-1;
  bool turn = true;
  while(i<=j) {
    int max = 0;
    if (a[i] > a[j]) {
      max = a[i];
      i++;
    } else {
      max = a[j];
      j--;
    }
    if(turn)
      count_1 += max;
    else count_2 += max;
    turn = !turn;
  }
  cout << count_1 << " " << count_2;
  return 0;
}
