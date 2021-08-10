#include<iostream>
#include<map>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
  int n, people, s;
  double x, y;
  map<double, int> res;
  map<double, int>::iterator it;
  cin >> n >> s;
  for(int i=0; i<n; i++) {
    cin >> x >> y >> people;
    double r = x*x + y*y;
    if(res.find(r) != res.end())
      res[r] += people;
    else 
      res[r] = people;
  }
  for(it = res.begin(); it != res.end(); it++) {
    s += it->second;
    if(s >= 1000000) {
      cout << fixed << setprecision(6) << sqrt(it->first) << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
