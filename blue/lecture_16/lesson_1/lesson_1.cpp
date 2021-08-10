#include<iostream>
using namespace std;
const int MAX = 30005;
int parent[MAX];
int ranks[MAX];
int cnt[MAX];

int findSet(int u) {
  while(parent[u] != u) {
    u = parent[u];
  }
  return u;
}

void unionSet(int u, int v) {
  int up = findSet(u);
  int vp = findSet(v);
  if(up != vp) {
    if(ranks[up] < ranks[vp]) {
      parent[up] = vp;
      cnt[vp] += cnt[up];
    } else {
      parent[vp] = up;
      cnt[up] += cnt[vp];
      if(ranks[up] == ranks[vp]) {
        ranks[up]++;
      }
    }
  }
}

int main() {
  int u, v, t, n, m;
  cin >> t;
  while(t--) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
      ranks[i] = 0;
      cnt[i] = 1;
      parent[i] = i;
    }

    for(int i=0; i<m; i++) {
      cin >> u >> v;
      unionSet(u, v);
    }
    int res = -1;
    for(int i=1; i<=n; i++) {
      res = max(res, cnt[i]);
    }
    cout << res << endl;
  }
  return 0;
}
