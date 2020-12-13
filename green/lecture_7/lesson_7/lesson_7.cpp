#include<iostream>
#include<string.h>
using namespace std;

int main() {
  char s[1001];
  cin.getline(s, 1001);
  for(int i=0; i<strlen(s); i++) {
    if(s[i-1] == ' ' && s[i-2] == '.') {
      int asciiCode = int(s[i]);
      if(asciiCode >= 97 && asciiCode <= 122) {
        int newChar = int(s[i])-32;
        s[i] = char(newChar);
      }
    }
  }
  cout << s << endl;
}
