#include <iostream>
using namespace std;

struct Edge {
	int u,v,w;
};

Edge initEdge(int u, int v, int w) {
	Edge e;
	e.u = u;
	e.v = v;
	e.w = w;
	return e;
}

int main() {
	int n, u, v, w;
	cin >> n;
	Edge a[1000006];
	for(int i=0; i<n; i++) {
		cin >> u >> v >> w;
		a[i] = initEdge(u, v, w);
	}
	int count = 0;
	int res = 1;
	for(int i=0; i<n; i++) {
		if(a[i].u == a[i].v) {
			count++;
			res = (res * a[i].w)%1000007;
		}
	}
	if(count > 0) {
		cout << count << " " << res;
	} else {
		cout << -1;
	}

	return 0;
}
