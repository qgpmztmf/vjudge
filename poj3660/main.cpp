#include <iostream>
using namespace std;
const int MAXN = 105;
const int MAXT = 300000;
int table[MAXN][MAXN] = {0};
int main() {
  int n, m, a, b;
  cin >> n >> m;

  for(int i = 1; i <= n; i++) {
    table[i][i] = 1;
  }
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    table[a][b] = 1;
  }

  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        table[i][j] = table[i][j] || (table[i][k] && table[k][j]);
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int temp = 0;
    for(int j = 1; j <= n; j++) {
      temp += table[i][j];
      temp += table[j][i];
    }
    if(temp == n + 1) {
      ans++;
    }
  }
  cout << ans << endl;
}
