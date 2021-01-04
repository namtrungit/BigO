#include<iostream>
#include<vector>

using namespace std;
int a[100005];
int main() {
  int T, N;
  cin >> T;
  for(int t=1; t<=T; t++) {
    cin >> N;
    for(int i=0; i<N; i++) {
      cin >> a[i];
    }
    int L = 1, R = a[N]+1;
    int res;
    while(L <= R) {
      int M = (L + R) >> 1;
      bool check = true;
      int k = M;
      for(int i=1; i<=N; i++) {
        if((a[i] - a[i-1]) > k) {
          check = false;
          break;
        } else if((a[i] - a[i-1]) == k) {
          k--;
        }
      }
      if(check) {
        res = M;
        R = M - 1;
      } else {
        L = M + 1;
      }
    }
    cout << "Case " << t << ": ";
    cout << res << endl;
  }
  return 0;
}
