#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
  int N, Q, q;
  cin >> N;
  vector<int> list(N);
  vector<int>::iterator low_value, upper_value;
  for(int i=0; i<N; i++) {
    cin >> list[i];
  }
  cin >> Q;
  for(int i=0; i<Q; i++) {
    cin >> q;
    low_value = lower_bound(list.begin(), list.end(), q);
    upper_value = upper_bound(list.begin(), list.end(), q);
    int low_index = low_value - list.begin();
    int upper_index = upper_value - list.begin();
    if(low_index == 0) {
      cout << 'X';
    } else {
      cout << list[low_index-1];
    }
    cout << " ";
    if(upper_index == list.size()) {
      cout << 'X';
    } else {
      cout << list[upper_index];
    }
    cout << endl;
  }
  return 0;
}
