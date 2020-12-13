#include<iostream>
#include<string.h>
using namespace std;

int main() {
  char s[1001];
  cin.getline(s, 1001);
  char words[1000][1001];
  int cnt = 0;
  int j = 0;
  for(int i=0; i<strlen(s); i++) {
    if(s[i] != ' ') {
      words[cnt][j] = s[i];
      j++;
    } else {
      words[cnt][j] = '\0';
      cnt++;
      j=0;
    }
  }

  if(j != 0) {
    words[cnt][j] = '\0';
    cnt++;
  }

  for(int i=cnt-1; i>-1; i--) {
    cout << words[i] << ' ';
  }
}
