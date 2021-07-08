#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;

void init(int n) {
  for(int i=1; i<=n; i++) {
    mp[i] = i;
  }
}

int findSet(int x) {
  if(mp[x] == x) {
    return x;
  }
  return findSet(mp[x]);
}

void unionSet(int A, int B) {
  int x,y;
  x = findSet(A);
  y = findSet(B);
  mp[x] = y;
}

int main() { 
  int n, m, cnt=0, x, y, t=0;
  while(true) {
    cin >> m >> n;
    cnt = 0;
    t++;
    if(m == 0 && n == 0) break;
    init(m);
    for(int i=0; i<n; i++) {
      cin >> x >> y;
      unionSet(x, y);
    }
    for(int i=1; i<=m; i++) {
      if(mp[findSet(i)] == i)
        cnt++;
    }
    printf("Case %d: %d\n", t, cnt);
  }
  return 0;
}
