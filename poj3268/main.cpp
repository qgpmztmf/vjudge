#include<iostream>
using namespace std;

const int MAXN = 1005;
const int MAXT = 1 << 30;
int btable[MAXN][MAXN], table[MAXN][MAXN];
int v[MAXN], d[MAXN], bd[MAXN];
int start, end, n, m, x, t, minl, u, ans;

int main() {
  cin >> n >> m >> x;

  for(int i = 1; i <= n; i++) {
    v[i] = 0;
    bd[i] = MAXT;
    for(int j = 1; j <= n; j++) {
      table[i][j] = MAXT;
      btable[i][j] = MAXT;
    }
  }

  for(int i = 0; i < m; i++) {
    cin >> start >> end;
    cin >> table[start][end];
    btable[end][start] = table[start][end];
  }

  bd[x] = 0;
  for(int ii = 0; ii < n; ii++) {
    u = -1;
    minl = MAXT;
    for(int i = 1; i <= n; i++) {
      if(!v[i] && minl > bd[i]) {
        minl = bd[i];
        u = i;
      }
    }

    v[u] = 1;
    for(int i = 1; i <= n; i++) {
      if(!v[i] && btable[u][i] != MAXT && bd[i] > bd[u] + btable[u][i]) {
        bd[i] = bd[u] + btable[u][i];
      }
    }
  }


  for(int i = 1; i <= n; i++) {
      v[i] = 0;
      d[i] = MAXT;
  }

  d[x] = 0;
  for(int ii = 0; ii < n; ii++) {
    u = -1;
    minl = MAXT;
    for(int i = 1; i <= n; i++) {
      if(!v[i] && minl > d[i]) {
        minl = d[i];
        u = i;
      }
    }

    v[u] = 1;
    for(int i = 1; i <= n; i++) {
      if(!v[i] && table[u][i] != MAXT && d[i] > d[u] + table[u][i]) {
        d[i] = d[u] + table[u][i];
      }
    }
  }

  ans = -1;
  for(int i = 1; i <= n; i++) {
    if(ans < d[i] + bd[i]) {
      ans = d[i] + bd[i];
    }
  }

  cout << ans << endl;
  return 0;
}
