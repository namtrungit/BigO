#include <iostream>
using namespace std;

int main() {
	int a[1000][1000];
	int n;
	bool check = true;
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> a[i][j];

	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++) {
			if(a[i][j] != a[j][i]) 
				check = false;
		}
	}

	check ? cout << "YES" : cout << "NO";
}
