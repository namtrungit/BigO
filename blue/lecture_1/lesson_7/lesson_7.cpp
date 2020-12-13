#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> list(n);
  int count[101] = {0};
  string chars, password;
  for(int i=0; i<n; i++) {
    cin >> chars;
    count[chars.size()]++;
  }
  cin >>  password;

  int best_time = 0, worst_time = 0;
  for(int i=0; i<password.size(); i++) {
    best_time += count[i];
  }
  // Tru di Th mat khau dung
  worst_time = best_time + count[password.size()] - 1;

  best_time += (best_time / k) * 5;
  worst_time += (worst_time / k) * 5;

  cout << best_time+1 << " " << worst_time+1;
  return 0;
}
