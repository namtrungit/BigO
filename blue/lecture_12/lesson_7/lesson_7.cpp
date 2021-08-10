#include<iostream>
#include<iomanip>
using namespace std;
const int MAX = 10000;
const int MAX_A = 1000;
double sumEnergy, sumTransfer, mid;
int n, k, A[MAX];

int main() {
  double left, right;
  cin >> n >> k;
  sumEnergy = 0;
  for(int i=0; i<n; i++) {
    cin >> A[i];
    sumEnergy += A[i];
  }

  left = 0;
  right = MAX_A;
  while(right - left > 1e-7) {
    mid = (left + right)/2;
    sumTransfer = 0;
    for(int i=0; i<n; i++) {
      if(A[i] > mid) {
        sumTransfer += A[i] - mid;
      }
    }
    if(mid * n < sumEnergy - sumTransfer*k/100)
      left = mid;
    else right = mid;
  }

  cout << fixed << setprecision(9) <<  left << endl;
  return 0;
}
