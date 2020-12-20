#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#define MAX 205
using namespace std;
vector<string> strList;
bool visisted[MAX];
vector<int> dist(MAX, 0);
vector<int> graph[MAX];

void BFS(int s) {
  for(int i=0; i<MAX; i++) {
    visisted[i] = false;
    dist[i] = 0;
  }
  queue<int> q;
  visisted[s] = true;
  q.push(s);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int i=0; i<graph[u].size(); i++) {
      int v = graph[u][i];
      if(!visisted[v]) {
        visisted[v] = true;
        q.push(v);
        dist[v] = dist[u]+1;
      }
    }
  }
}

int findIndex(string s) {
  for(int i=0; i<strList.size(); i++) {
    if(strList[i] == s) 
      return i;
  }
  return -1;
}

bool compareString(string s, string t) {
  int sL = s.length();
  int tL = t.length();
  if(sL != tL)
    return false;
  int cnt = 0;
  for(int i=0; i<sL; i++) {
    if(s[i] != t[i])
      cnt++;
  }
  return cnt == 1;
}

int main () {
  int Q;
  string word, s, t, line;
  cin >> Q;
  while(Q--) {
    fill(strList.begin(), strList.end(), "");
    while(cin >> word, word != "*")
      strList.push_back(word);
    cin.ignore();
    int size = strList.size();
    // Build Graph
    for(int i=0; i<size-1; i++) {
      for(int j=1; j<size; j++) {
        if(compareString(strList[i], strList[j])) {
          graph[i].push_back(j);
          graph[j].push_back(i);
        }
      }
    }
    while(getline(cin, line) && line != "") {
      stringstream ss(line);
      ss >> s >> t;
      int sindex = findIndex(s);
      int tindex = findIndex(t);
      // cout << s << " " << sindex << endl;
      // cout << t << " " << tindex << endl;
      // cout << strList.size() << endl;
      // for(int i=0; i<strList.size(); i++) {
        // cout << strList[i] << endl;
      // }
      BFS(sindex);
      // cout << dist[sindex] << " " << dist[tindex] << endl;
      cout << s << " " << t << " " << dist[tindex] << endl;
    }
  }
}
