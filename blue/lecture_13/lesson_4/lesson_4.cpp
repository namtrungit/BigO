#include<iostream>
#include<set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T, N, M;
  long long candy;
  set<long long> candies;
  set<long long>::iterator it;
  cin >> T;
  while(T--) {
    cin >> N >> M;
    candies.clear();
    for(int i=0; i<N; i++) {
      cin >> candy;
      candies.insert(candy);
    }

    for(int i=0; i<M; i++) {
      cin >> candy;
      it = candies.find(candy);
      if(it != candies.end())
        cout << "YES";
      else cout << "NO";
      cout << endl;
      candies.insert(candy);
    }
  }
  return 0;
}
