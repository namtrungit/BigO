#include <iostream>
using namespace std;

struct Edge {
	int u;
	int v;
};

Edge initEdge(int x, int y) {
	Edge e;
	e.u = x;
	e.v = y;
	return e;
}

int adj_matrix[1000][1000];
Edge edge_list[500000];

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> adj_matrix[i][j];
	
	int	edge_length = 0;
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if(adj_matrix[i][j] == 1)
				edge_list[edge_length++] = initEdge(i, j);
		}
	}

	cout << edge_length << endl;
	for(int i=0; i<edge_length; i++)
		cout << edge_list[i].u << " " << edge_list[i].v << endl;
}
