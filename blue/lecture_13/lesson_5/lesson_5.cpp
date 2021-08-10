#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
  int N;
  string name;
  map<string, int> list;
  map<string, int>::iterator it;
  cin >> N;
  cin.ignore(); // Xoa bo nho dem
  for(int i=0; i<N; i++) {
    getline(cin , name);
    if(list.find(name) != list.end())
      list[name]++;
    else 
      list[name] = 1;
  }
  int max = -1;
  string maxName;
  for(it = list.begin(); it != list.end(); it++) {
    if(it->second > max) {
      max = it->second;
      maxName = it->first;
    }
  }
  cout << maxName;
  return 0;
}
