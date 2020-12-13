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

Fraction sumFraction(Fraction p1, Fraction p2) {
	Fraction p3;
	p3.num = p1.num * p2.denom + p1.denom * p2.num;
	p3.denom = p1.denom * p2.denom;
	reduceFraction(p3);
	return p3;
}

int main() {
	Fraction p1;
	Fraction p2;
	Fraction p3;
	cin >> p1.num >> p1.denom;
	cin >> p2.num >> p2.denom;
	p3 = sumFraction(p1, p2);
	cout << p3.num << " " << p3.denom;
	return 0;
}

