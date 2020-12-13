#include <iostream>
using namespace std;

struct Fraction {
	int num;
	int denom;
};

int gcd(int a, int b) {
	int r = 0;
	while (b != 0) {
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

void reduceFraction(Fraction &p) {
	if(p.num == 0) {
		p.denom = 1;
		return;
	}
	int x  = gcd(abs(p.num), abs(p.denom));
	p.num = p.num/x;
	p.denom = p.denom/x;
}

int main() {
	int n;
  cin >> n;
  Fraction array[n];
  int maxPosition = 0;
  int max = 0;
  for(int i=0; i<n; i++) {
    Fraction p;
    cin >> p.num >> p.denom;
    reduceFraction(p);
    array[i] = p;
  }

  for(int i=0; i<n; i++) {
    Fraction p = array[i];
    int result = p.num/p.denom;
    if(result > max) {
      max = result;
      maxPosition = i;
    }
  }

  cout << array[maxPosition].num <<  " " << array[maxPosition].denom;
	return 0;
}

