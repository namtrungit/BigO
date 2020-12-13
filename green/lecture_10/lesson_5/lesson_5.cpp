#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

struct Student {
	int id;
	float math;
	float literature;
};

int main() {
	int n, m;
	cin >> n >> m;
	Student student_list[n];
	for(int i=0; i<n; i++) {
		Student stu;
		cin >> stu.id >> stu.math >> stu.literature;
		student_list[i] = stu;
	}
	for(int i=0; i<m; i++) {
		int search;
		cin >> search;
		for(int j=0; j<n; j++) {
			Student stu = student_list[j];
			if(stu.id == search) {
				cout << stu.math << " " << stu.literature << endl;
			}
		}
	}
}
