#include <iostream>
using namespace std;

struct Edge {
	int u, v, w;
};

Edge initEdge(int u, int v, int w) {
	Edge e;
	e.u = u;
	e.v = v;
	e.w = w;
	return e;
}

void sort(Edge list[], int n) {
	for(int i=1; i<n; i++) {
		Edge cur = list[i];
		int j=i;
		while(j>0 && list[j-1].w > cur.w) {
			list[j] = list[j-1];
			j--;
		}
		list[j] = cur;
	}
}

int main() {
	int m, k, u, v, w;
	Edge a[1000];
	cin >> m >> k;
	for(int i=0; i<m; i++) {
		cin >> u >> v >> w;
		a[i] = initEdge(u, v, w);
	}
	sort(a, m);
	for(int i=k-1; i>=0; i--) {
		cout << a[i].u << " " << a[i].v << endl;
	}
	return 0;
}
