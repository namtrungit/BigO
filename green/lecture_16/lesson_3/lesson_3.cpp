#include<iostream>
using namespace std;

void findMax(int a, int b, int c, int &max) {
	int array[6];
	array[0] = a+b+c;
	array[1] = a*b+c;
	array[2] = a+b*c;
	array[3] = (a+b)*c;
	array[4] = a*(b+c);
	array[5] = a*b*c;
	for(int i=0; i<6; i++) {
		if(array[i] > max)
			max = array[i];
	}
}

int main() {
	int a, b, c, max=0;
	cin >> a;
	cin >> b;
	cin >> c;
	findMax(a, b, c, max);
	cout << max;
	return 0;
}
