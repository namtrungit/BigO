#include<iostream>
#include<string.h>
using namespace std;

int pos(char ch) {
  if('A' <= ch && ch <= 'Z')
    return ch - 'A';
  return ch - 'a' + 26;
}

int main() {
  char s[1001];
  cin.getline(s, 1001);
  bool array[2*26];
  for(int i=0; i<strlen(s); i++) {
    array[pos(s[i])] = true;
  }
  int count = 0;
  for(int i=0; i<2*26; i++) {
    if(array[i] == 1) count++;
  }
  cout << count;
}
