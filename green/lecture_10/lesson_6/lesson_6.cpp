#include<iostream>
using namespace std;

struct Roll {
  int color;
  int length;
};

int main() {
  int n;
  cin >> n;
  Roll array[n];
  for(int i=0; i<n; i++) {
    Roll roll;
    cin >> roll.color >> roll.length;
    array[i] = roll;
  }

  int color[1001] = {0};
  int count[1001] = {0};
  for(int i=0; i<n; i++) {
    color[array[i].color]+=array[i].length;
    count[array[i].color]++;
  }
  
  int countList = 0;
  for(int i; i<1001; i++) {
    if(color[i] != 0 && count[i] !=0) countList++;
  }
  cout << countList << endl;
  for(int i=0; i<1001; i++) {
    if(color[i] != 0 && count[i] !=0) {
      cout << i << " " << color[i] << " " << count[i] << endl;
    }
  }
  return 0;
}
