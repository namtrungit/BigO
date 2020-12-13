#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

struct Position {
	int x;
	int y;
	float distance;
};

float calculateDistance(Position a, Position b) {
	float distance;
	distance = abs((a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y));
	return distance;
}

int main() {
	Position a;
	int n;
	Position array[n];
	cin >> a.x >> a.y;
	cin >> n;
	for(int i=0; i<n; i++) {
		Position p;
		cin >> p.x >> p.y;
		p.distance = calculateDistance(a, p);
		array[i] = p;
	}
	int max = 0;
	for(int i=0; i<n; i++) {
		if(array[i].distance > array[max].distance) {
			max = i;
		}
	}
	cout << array[max].x << " " << array[max].y;
	return 0;
}
