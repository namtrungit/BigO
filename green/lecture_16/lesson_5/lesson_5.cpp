#include<iostream>
#include<string>
using namespace std;

int main() {
	string name;
	string first;
	string second;
	string third;
	cin >> name;
	for(int i=0; i<name.length(); i++) {
		if(i%2 == 0) {
			first+=name[i];
		}
		if(i%2 != 0) {
			second+=name[i];
		}
	}
	for(int i=second.length(); i>=0; i--) {
		third+=second[i];
	}
	for(int i=0; i<first.length(); i++) {
		cout << first[i];
		cout << third[i+1];
	}
	return 0;
}
