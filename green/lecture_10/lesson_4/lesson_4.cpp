#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Position {
	int x;
	int y;
};

struct Triangle {
	double area;
};

double calculate_distance(Position a, Position b) {
	double distance;
	distance = sqrt((b.x - a.x)*(b.x - a.x)+(b.y - a.y)*(b.y - a.y));
	return distance;
}

double calculate_area(double a, double b, double c) {
	double area, hp;
	hp = (a+b+c)/2;
	area = sqrt(hp*(hp-a)*(hp-b)*(hp-c));
	return area;
}

int main() {
	int n;
	cin >> n;
	Triangle array[n];
	for(int i=0; i<n; i++) {
		Triangle triangle;
		Position position_1, position_2, position_3;
		cin >> position_1.x >> position_1.y;
		cin >> position_2.x >> position_2.y;
		cin >> position_3.x >> position_3.y;
		double edges[3];
		edges[0] = calculate_distance(position_1, position_2);
		edges[1] = calculate_distance(position_1, position_3);
		edges[2] = calculate_distance(position_2, position_3);
		triangle.area = calculate_area(edges[0], edges[1], edges[2]);
		array[i] = triangle;
	}
	double sum = 0;
	for(int i=0; i<n; i++) {
		sum += array[i].area;
	}
	cout << fixed;
	cout << setprecision(2);
	cout << sum;
}
