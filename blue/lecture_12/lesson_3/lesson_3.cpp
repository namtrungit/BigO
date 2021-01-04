#include<iostream>
#include<vector>

using namespace std;

int main() {
  int N, M, res = 0;
  cin >> N >> M;
  vector<int> trees(N);
  for(int i=0; i<N; i++) {
    cin >> trees[i];
  }
  int hleft = 0;
  int hright = 1e9-7;
  long long h;
  while(hleft <= hright) {
    h = 0;
    int hmid = hleft + (hright - hleft) / 2;
    for(int &x : trees) {
      h += max(0, (x - hmid));
    }
    if(h >= M) {
      res = hmid;
      hleft = hmid + 1;
    } else {
      hright = hmid - 1;
    }
  }
  cout << res;
  return 0;
}
