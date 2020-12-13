#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long learning(vector<int>& subjects, int x) {
  sort(subjects.begin(), subjects.end());
  long long min_time = 0;
  for(int subject: subjects) {
    min_time += 1LL * subject * x;
    if(x>1)
      x--;
  }
  return min_time;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> subjects(n);
  for(int i=0; i<n; i++) {
    cin >> subjects[i];
  }
  long long result = learning(subjects, x);
  cout << result;
}
