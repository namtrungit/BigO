#include <iostream>
using namespace std;

int main() {
	int a[1000][1000];
	int n, x;
	int count = 0;
	cin >> n >> x;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> a[i][j];

	for(int i=0; i<n; i++){
		if(a[x][i] == 1)
			count++;
	}
	cout << count;
}
