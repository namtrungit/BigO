#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Task {
  int a, b, d;
  bool operator < (const Task& B) const {
    return a < B.a;
  }
};

bool option(const Task& A,const Task& B) {
  return A.d < B.d;
}

int main() {
  int t, n, a, b, d;
  cin >> t;
  while(t--) {
    vector<Task> taskList;
    cin >> n;
    for(int i=0; i<n; i++) {
      cin >> a >> b >> d;
      taskList.push_back({a, b, d});
    }
    sort(taskList.begin(), taskList.end(), option);
    int time = 0;
    double cost = 0;
    priority_queue<Task> pq;
    for(int i=0; i<taskList.size(); i++) {
      Task task = taskList[i];
      time+=task.b;
      pq.push(task);
      // cout << cost << " " << time << " " << i << endl;
      while(time > task.d) {
        Task t = pq.top();
        pq.pop();
        if(t.b > time - task.d) {
          t.b -= (time - task.d);
          cost += 1.0*(time - task.d)/t.a;
          time = task.d;
          pq.push(t);
        } else {
          cost += 1.0*t.b / t.a;
          time -= t.b;
        }
      }
      // cout << cost << " " << time << " " << i << endl;
    }
    cout << setprecision(2) << fixed << cost << endl;
  }
  return 0;
}
