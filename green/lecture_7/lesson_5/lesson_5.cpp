#include<iostream>
#include<string.h>
using namespace std;

int pos(char ch) {
  if('A' <= ch && ch <= 'Z')
    return ch - 'A';
  return ch - 'a';
}

void printChar(char s[]) {
  int array[26] = {0};
  for(int i=0; i<strlen(s); i++) {
    array[pos(s[i])]++;
  }
  int minPos = -1;
  for(int i=26; i>-1; i--) {
    if(array[i] == 1) 
      minPos = i;
  }
  cout << char(65+minPos) << endl;
}

int main() {
  int n;
  cin >> n;
  char wordList[1000][1001];
  int cnt=0;
  for(int i=0; i<n; i++) {
    cin >> wordList[i];
    cnt++;
  }
  for(int i=0; i<cnt; i++) {
    printChar(wordList[i]);
  }
}
