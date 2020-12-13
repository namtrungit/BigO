#include<iostream>
using namespace std;

void sort(int a[], int n) {
  for(int i=1; i<n; i++) {
    int cur = a[i];
    int j = i;
    while( j > 0 && a[j-1] > cur ) {
      a[j] = a[j-1];
      j--;
    }
    a[j] = cur;
  }
}

int main() {
	int n;
	int a[1000];
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, n);
	for(int i=0; i<n; i++) {
		cout << a[i] << " ";
	}
}
