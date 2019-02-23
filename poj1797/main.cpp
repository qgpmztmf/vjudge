#include <iostream>
#include <cmath>
using namespace std;
const int MAXV = 1005;
const int inf = 1000005;
int table[MAXV][MAXV];
int v[MAXV], d[MAXV];
int num, u, n, m, maxl, start, end;

int WinMain() {
  cin >> num;

  for(int iii = 1; iii <= num; iii++) {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
      table[i][i] = inf;
      d[i] = 0;
      v[i] = 0;
    }

    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        table[i][j] = 0;
      }
    }

    for(int i = 0; i < m; i++) {
      cin >> start >> end;
      cin >> table[start][end];
      table[end][start] = table[start][end];
    }

    d[1] = inf;
    for(int i = 0; i < n; i++) {
      u = -1;
      maxl = -1;
      for(int j = 1; j <= n; j++) {
        if(!v[j] && maxl < d[j]) {
          maxl = d[j];
          u = j;
        }
      }

      v[u] = 1;
      for(int j = 1; j <= n; j++) {
        //cout << "v["<<j<<"]: " << v[j] << " table["<<u<<"]["<<j<<"]: " << table[u][j] << " d["<<j<<"]: "<<d[j]<< endl;
        if(!v[j] && table[u][j] && d[j] < min(d[u], table[u][j])) {
          d[j] = min(d[u], table[u][j]);
        }
      }
    }

    cout << "Scenario #" << iii << ":" << endl;
    cout << d[n] << endl << endl;
  }
  return 0;
}
