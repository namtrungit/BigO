#include <iostream>
using namespace std;

struct Edge {
	int u,v,m;
};

Edge initEdge(int u, int v, int m) {
	Edge e;
	e.u = u;
	e.v = v;
	e.m = m;
	return e;
}

int main() {
	Edge a[1000000];
	int n,u,v,m,min;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> u >> v >> m;
		a[i] = initEdge(u,v,m);
	}
	min = a[0].m;
	for(int i=0; i<n; i++) {
		if(a[i].m < min)
			min = a[i].m;
	}
	int sum = 0;
	for(int i=0; i<n; i++) {
		if(a[i].m == min)
			sum += a[i].m;
	}
	cout << sum;
	return 0;
}
