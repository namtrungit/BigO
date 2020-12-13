#include<iostream>
using namespace std;
int inf = -1000000001;
void merge(int n1, int L[], int n2, int R[], int a[])
{
    L[n1] = inf;
    R[n2] = inf;

    int i, j, k;
    i = j = k = 0;
    while (i < n1 || j < n2) {
        if (L[i] > R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
}

void mergeSort(int a[], int n) {
	int L[50000], R[50000];
	if(n>1) {
		int left = n/2;
		int right = n-left;
		for(int i=0; i<left; i++)
			L[i] = a[i];
		for(int i=0; i<right; i++)
			R[i] = a[i+right];
		mergeSort(L, left);
		mergeSort(R, right);
		merge(left, L, right, R, a);
	}
	
}

int main() {
	int n, a[100000];
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
	mergeSort(a, n);
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
}
