#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

struct Student {
	char name[101];
	float math;
	float literature;
	float average;
};

float calculate_avarage(Student stu) {
	float average;
	average = (stu.math + stu.literature)/2;
	return average;
}

int main() {
	int n;
	cin >> n;
	Student a[n];
	for(int i=0; i<n; i++) {
		cin.clear();
		cin.ignore(101,'\n');
		Student stu;
		cin.getline(stu.name, 101);
		cin >> stu.math >> stu.literature;
		stu.average = calculate_avarage(stu);
		a[i] = stu;
	}

	int count = 0;
	for(int i=0; i<n; i++) {
		if(a[i].average >= 9) count++;
	}
	cout << count;
	return 0;
}
