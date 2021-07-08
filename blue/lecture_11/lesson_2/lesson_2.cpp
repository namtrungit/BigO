#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int MAX = 28;
const int INF = 1e9;
struct Place {
  int cost, id;
  bool operator<(const Place &other) const {
    return cost < other.cost || (cost == other.cost && id < other.id);
  }
};
vector<Place> res;
int distS[MAX][MAX];
int distD[MAX][MAX];

void FloydWarshall(int dist[MAX][MAX]) {
  for(int k=0; k<MAX; k++) {
    for(int i=0; i<MAX; i++) {
      for(int j=0; j<MAX; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

int main() {
  int N, c;
  char age, dir, x, y;
  while(cin >> N, N != 0) {
    for(int i=0; i<MAX; i++) {
      for(int j=0; j<MAX; j++) {
        distS[i][j] = ( i == j ? 0 : INF );
        distD[i][j] = ( i == j ? 0 : INF );
      }
    }

    for(int i=0; i<N; i++) {
      cin >> age >> dir >> x >> y >> c;
      int u = x - 'A';
      int v = y - 'A';
      if(age == 'Y') {
        distS[u][v] = min(distS[u][v], c);
        if(dir == 'B')
          distS[v][u] = min(distS[v][u], c);
      } else {
        distD[u][v] = min(distD[u][v], c);
        if(dir == 'B')
          distD[v][u] = min(distD[v][u], c);
      }
    }

    FloydWarshall(distS);
    FloydWarshall(distD);
    res.clear();
    cin >> x >> y;
    int s = x - 'A';
    int d = y - 'A';
    int min = INF;
    for(int i=0; i<MAX; i++) {
      int dist1 = distS[s][i];
      int dist2 = distD[d][i];
      if(dist1 != INF && dist2 != INF && dist1+dist2 <= min) {
        res.push_back({ dist1 + dist2, i });
        min = dist1 + dist2;
      }
    }
    sort(res.begin(), res.end());
    if(res.empty()) {
      cout << "You will never meet.";
    } else {
      cout << min;
      for(Place &place : res) {
        if(place.cost != min) break;
        cout <<  " " << char(place.id + 'A');
      }
    }
    cout << endl;
  }
  return 0;
}
