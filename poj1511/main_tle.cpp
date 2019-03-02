#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 1000010;
const int MAXP = 0x3f3f3f3f;
int N, P, Q, start, end, table[MAXN][MAXN], btable[MAXN][MAXN], d[MAXN], bd[MAXN], v[MAXN], bv[MAXN];
priority_queue<int, vector<int>, greater<int> > q,bq;

int main() {
  cin >> N;
  for(int k = 0; k < N; k++) {

    cin >> P >> Q;

    for(int i = 1; i <= P; i++) {
      for(int j = 1; j <= P; j++) {
        table[i][j] = MAXP;
        btable[i][j] = MAXP;
      }
      table[i][i] = 0;
      btable[i][i] = 0;
      d[i] = MAXP;
      bd[i] = MAXP;
      v[i] = 0;
      bv[i] = 0;
    }

    for(int i = 0; i < Q; i++) {
      cin >> start >> end;
      cin >> table[start][end];
      btable[end][start] = table[start][end];
    }

    //for(int i = 1; i <= P; i++) {
    //  for(int j = 1; j <= P; j++) {
    //    cout << table[i][j] << " ";
    //  }
    //  cout << endl;
    //}

    d[1] = 0;
    for(int ii = 0; ii < P; ii++) {
      int minl = MAXP;
      int u = -1;
      for(int i = 1; i <= P; i++) {
        if(!v[i] && d[i] < minl) {
          minl = d[i];
          u = i;
        }
      }
      v[u] = 1;
      for(int i = 1; i <= P; i++) {
        if(!v[i] && table[u][i] != MAXP && d[i] > d[u] + table[u][i]) {
          d[i] = d[u] + table[u][i];
        }
      }
    }

    bd[1] = 0;
    for(int ii = 0; ii < P; ii++) {
      int minl = MAXP;
      int u = -1;
      for(int i = 1; i <= P; i++) {
        if(!bv[i] && bd[i] < minl) {
          minl = bd[i];
          u = i;
        }
      }
      bv[u] = 1;
      for(int i = 1; i <= P; i++) {
        if(!bv[i] && btable[u][i] != MAXP && bd[i] > bd[u] + btable[u][i]) {
          bd[i] = bd[u] + btable[u][i];
        }
      }
    }

    int ans = 0;
    for(int i = 1; i <= P; i++) {
      ans += d[i];
      ans += bd[i];
    }
    cout << ans << endl;
  }
  return 0;
}
