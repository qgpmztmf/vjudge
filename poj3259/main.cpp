#include <iostream>
#include <cmath>
#include<cstring>
using namespace std;
const int MAXN = 505;
const int MAXT = 0x3f3f3f3f;
int F, N, M, W, S, E, C;
int table[MAXN][MAXN];

int floyd() {
  for(int k = 1; k <= N; k++) {
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        if(table[i][k] != MAXT && table[k][j] != MAXT) {
          int t = table[i][k] + table[k][j];
          if(t < table[i][j]) {
            table[i][j] = t;
          }
        }
      }
      if(table[i][i] < 0) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  cin >> F;
  for(int ii = 0; ii < F; ii++) {
    cin >> N >> M >> W;

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        table[i][j] = MAXT;
      }
    }

    memset(table,0x3f3f3f3f,sizeof(table));
    for(int i = 0; i < M; i++) {
      cin >> S >> E >> C;
      if(C < table[S][E]) {
        table[E][S] = table[S][E] = C;
      }
    }

    for(int i = 0; i < W; i++) {
      cin >> S >> E;
      cin >> table[S][E];
      table[S][E] *= -1;
    }
    for(int i = 1; i <= N; i++) {
      table[i][i] = 0;
    }


    if(floyd()) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
