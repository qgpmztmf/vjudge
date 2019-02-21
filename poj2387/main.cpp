#include <iostream>
using namespace std;
const int MAX = 1002;
const int Unreachable = 101;
int table[MAX][MAX];
int d[MAX], v[MAX];
int T, N, start, end, uid, minl;
int WinMain() {
  cin >> T >> N;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      table[i][j] = Unreachable;
    }
  }

  for(int j = 1; j <= N; j++) {
    d[j] = Unreachable;
    v[j] = 0;
    table[j][j] = 0;
  }

  for(int i = 0; i < T; i++) {
    cin >> start >> end;
    cin >> table[start][end];
  }

  d[1] = 0;
  for(int i = 1; i <= N; i++) {
    uid = -1;
    minl = Unreachable;
    for(int j = 1; j <= N; j++) {
      if(!v[j] && d[j] < minl) {
        minl = d[j];
        uid = j;
      }
    }

    //if(uid == N) {
    //  cout << d[N] << endl;
    //  break;
    //}

    v[uid] = 1;
    for(int j = 1; j <= N; j++) {
      if(!v[j] && table[uid][j] != Unreachable && d[j] >= d[uid] + table[uid][j]) {
        d[j] = d[uid] + table[uid][j];
      }
    }
  }
  cout << d[N] << endl;
  return 0;
}
