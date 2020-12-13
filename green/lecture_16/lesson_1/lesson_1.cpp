#include<iostream>
using namespace std;

void merge(int m, int a[],int n, int b[], int c[]) {
	for(int i=0; i<m; i++)
		c[i] = a[i];
	for(int i=0; i<n; i++)
		c[i+m] = b[i];
}

void sort(int z, int c[]) {
	for(int i=1; i<z; i++) {
		int cur = c[i];
		int j = i;
		while(j>0 && c[j-1] > cur){
			c[j] = c[j-1];
			j--;
		}
		c[j] = cur;
	}
}

int main() {
	int m,n,k;
	cin >> m >> n >> k;
	int a[10000], b[10000], c[20000];
	for(int i=0; i<m; i++)
		cin >> a[i];
	for(int i=0; i<n; i++)
		cin >> b[i];
	int z = m+n;
	merge(m, a, n, b, c);
	sort(z, c);
	cout << c[k];
	
	return 0;
}
