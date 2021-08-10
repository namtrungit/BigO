#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
  string letter, paper;
  map<int, int> a, b;
  cin >> letter >> paper;

  for(int i=0; i<letter.size(); i++) {
    int temp = letter[i] - 'A';
    if(letter[i] > 'Z')
      temp = letter[i] - 'a' + 26;
    a[temp]++;
  }

  for(int i=0; i<paper.size(); i++) {
    int temp = paper[i] - 'A';
    if(paper[i] > 'Z')
      temp = paper[i] - 'a' + 26;
    b[temp]++;
  }

  int yap=0, whops=0;
  for(int i=0; i<52; i++) {
    int cnt = min(a[i], b[i]);
    yap += cnt;
    a[i] -= cnt;
    b[i] -= cnt;
  }

  for(int i=0; i<26; i++) {
    int cnt = min(a[i], b[i+26]) + min(a[i+26], b[i]);
    whops += cnt;
  }

  cout << yap << " " << whops << endl;
  return 0;
}
