#include<string>
#include<iostream>
#include<map>
#include<iomanip>
using namespace std;

int main() {
  string name;
  int T;
  map<string, int> trees;
  map<string, int>::iterator it;
  cin >> T;
  getline(cin, name);
  getline(cin, name);
  while(T--) {
    int count = 0;
    while(getline(cin, name)) {
      if(name.size() < 1)
        break;
      count++;
      if(trees.find(name) == trees.end()) {
        trees[name] = 1;
      } else trees[name]++;
    }
    for(it=trees.begin(); it != trees.end(); it++) {
      cout << (it->first).c_str() << " ";
      cout << fixed << setprecision(4) << 100.0*(it->second)/count << endl;
    }
    if(T) cout << endl;
    trees.clear();
  }
  return 0;
}
