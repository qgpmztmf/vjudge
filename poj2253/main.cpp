#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const int maxn = 205;
const double inf = 1 << 21;
double table[maxn][maxn];
double d[maxn];
int v[maxn], r[2 * maxn];
int n, u, k, minl;

int WinMain() {
  k = 0;
  while(cin >> n && n) {
    for(int i = 0; i < n; i++) {
        cin >> r[2 * i] >> r[2 * i + 1];
    }

    for(int i = 0; i < n; i++) {
      d[i] = inf;
      v[i] = 0;
      for(int j = i; j < n; j++) {
        table[i][j] = sqrt(pow(float(r[2 * i] - r[2 * j]), 2) + pow(float(r[2 * i + 1] - r[2 * j + 1]), 2));
        table[j][i] = table[i][j];
      }
    }

    d[0] = 0;
    for(int ii = 0; ii < n; ii++) {
      u = -1;
      minl = inf;
      for(int i = 0; i < n; i++) {
        if(!v[i] && d[i] <= minl) {
          minl = d[i];
          u = i;
        }
      }
      v[u] = 1;
      for(int i = 0; i < n; i++) {
        if(!v[i] && d[i] > max(table[u][i], d[u])) {
          d[i] = max(table[u][i], d[u]);
        }
      }
    }
    //for(int i = 0; i < n; i++) {
    //  for(int j = 0; j < n; j++) {
    //    cout << table[j][i] << " ";
    //  }
    //  cout << endl;
    //}
    k++;
    cout << "Scenario #" << k << endl;
    cout << "Frog Distance = " << fixed << setprecision(3) << d[1] << endl;
    cout << endl;
  }
  return 0;
}
