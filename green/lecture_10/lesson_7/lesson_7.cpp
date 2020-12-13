#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

struct Employee {
	char id[7];
	char name[10];
	int birth;
};

int find_min_year(int n, Employee employee_list[]){
	int min_year = employee_list[0].birth;
	for(int i=0; i<n; i++) {
		if(employee_list[i].birth < min_year) {
			min_year = employee_list[i].birth;
		}
	}
	return min_year;
}

Employee find_ans(Employee array[], int n) {
	if(n == 1) {
		return array[0];
	}
	char min_id[7];
	strcpy(min_id, array[0].id);
	for(int i=0; i<n; i++){
		if(atoi(array[i].id) < atoi(min_id)){
			return array[i];
		}
	}
	return array[0];
}

int main() {
	int n;
	cin >> n;
	Employee employee_list[n];
	for(int i=0; i<n; i++) {
		Employee emp;
		cin >> emp.id >> emp.name >> emp.birth;
		employee_list[i] = emp;
	}
	int min_year = find_min_year(n, employee_list);
	Employee ans[n];
	int ans_length = 0;
	for(int i=0; i<n; i++){
		if(employee_list[i].birth == min_year) {
			ans[ans_length] = employee_list[i];
			ans_length++;
		}
	}
	Employee result = find_ans(ans, ans_length);
	cout << result.id << " " << result.name << " " << result.birth;
}
