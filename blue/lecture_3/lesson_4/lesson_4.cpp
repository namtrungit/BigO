#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool option(int a, int b) {
  return a>b;
}

int main() {
  int n;
  // int cnt[2000] = {0};
  int rank[2001] = {0};
  cin >> n;
  vector<int> marks(n);
  vector<int> sort_marks(n);
  for(int i=0; i<n; i++) {
    cin >> marks[i];
    sort_marks[i] = marks[i];
  }
  sort(sort_marks.begin(), sort_marks.end(), option);
  int rating = 0;
  // 3 3 1
  // 5 5 4 3 3
  for(int i=0; i<n; i++) {
    rating = sort_marks[i];
    if(!rank[rating]) {
      rank[rating] = i+1;
    }
  }

  for(int i=0; i<n; i++) {
    cout << rank[marks[i]] << " ";
  }
  return 0;
}
