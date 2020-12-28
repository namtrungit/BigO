#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int bsearch(const vector<int> &a, int left, int right, int x) {
  if(left <= right) {
    int mid = left + (right - left) / 2;
    if((mid == left || x > a[mid-1]) && a[mid] == x) {
      return mid;
    }
    else if(x > a[mid]) 
      return bsearch(a, mid+1, right, x);
    else 
      return bsearch(a, left, mid-1, x);
  }
  return -1;
}

int main() {
  int N, Q, num, x;
  int index = 0;
  while(true) {
    cin >> N >> Q;
    if(N == 0 && Q == 0) break;
    vector<int> a;
    for(int i=0; i<N; i++) {
      cin >> num;
      a.push_back(num);
    }
    cout << "CASE# " << index+1 << ":" << endl;
    sort(a.begin(), a.end());
    for(int i=0; i<Q; i++) {
      cin >> x;
      int result = bsearch(a, 0, N-1, x);
      if(result == -1) {
        cout << x << " not found" << endl;
      } else {
        cout << x << " found at " << result + 1 << endl;
      }
    }
    index++;
  }
  return 0;
}
