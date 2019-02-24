#include<iostream>
#include<cmath>
using namespace std;
const int MAXS = 105;
const int MAXT = 0x3f3f3f;
int table[MAXS][MAXS];
int temp[MAXS];
int n, m, index, end;
int ur = 0;

int main() {
  while(cin >> n && n) {

    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(i == j) {
          table[i][i] = 0;
        }
        else {
          table[i][j] = MAXT;
        }
      }
    }

    for(int i = 0; i < n; i++) {
      cin >> m;
      for(int j = 0; j < m; j++) {
        cin >> end;
        cin >> table[i + 1][end];
      }
    }

    for(int k = 1; k <= n; k++) {
      for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
          table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
        }
      }
    }

      for(int i = 1; i <= n; i++) {
        temp[i] = -1;
      }
      int ans = MAXT;
      int p;
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
          temp[i] = max(temp[i], table[i][j]);
        }
      }
      for(int i = 1; i <= n; i++) {
          if(ans > temp[i]) {
            p = i;
            ans = temp[i];
          }
      }
      if(ans == MAXT){
        cout << "disjoint" << endl;
      }
      else {
        cout << p << " " << ans << endl;
      }
  }
}
