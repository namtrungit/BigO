#include <iostream>
using namespace std;

struct Edge {
	int u, v;
};

Edge initEdge(int u, int v) {
	Edge e;
	e.u = u;
	e.v = v;
	return e;
}

int main() {
	int a[1000][1000];
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			cin >> a[i][j];
	}

	Edge edgeList[1000];
	int edgeListLength = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			if(a[i][j] == 1)
				edgeList[edgeListLength++] = initEdge(i, j);
	}
	
	cout << edgeListLength << endl;
	for(int i=0; i<edgeListLength; i++) {
		cout << edgeList[i].u << " " << edgeList[i].v << endl;
	}
}
