#include <iostream>
#include<queue>
using namespace std;

struct Student {
  int id, increment, score;
  bool operator < (const Student& B) const {
    return (increment < B.increment || (increment == B.increment && id < B.id));
  }
};

int main() {
  int N, ID, Z, P, L, C, S;
  cin >> N;
  priority_queue<Student> q;
  for(int i=0; i<N; i++) {
    cin >> ID >> Z >> P >> L >> C >> S;
    int score = (P*50)+(L*5)+(C*10)+(S*20);
    int increment =  score - Z;
    Student stu = { ID, increment, score };
    q.push(stu);
  }
  int i = 0;
  while(!q.empty() && i<5) {
    cout << q.top().id << " " << q.top().score << endl;
    q.pop();
    i++;
  }
  return 0;
}
