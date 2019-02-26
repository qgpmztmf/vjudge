#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 105;
int N, M, S, A, B;
double V, R[MAXN][MAXN], C[MAXN][MAXN], d[MAXN], newd[MAXN];

int main() {
  cin >> N >> M >> S >> V;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      R[i][j] = 0;
      C[i][j] = 0;
    }
  }

  for(int i = 0; i < M; i++) {
    cin >> A >> B;
    cin >> R[A][B] >> C[A][B];
    cin >> R[B][A] >> C[B][A];
  }

  for(int i = 1; i <= N; i++) {
    d[i] = 0;
    newd[i] = 0;
  }
  d[S] = V;
  newd[S] = V;

  for(int k = 1; k <= 2 * N; k++) {
    if(k == N) {
      for(int l = 1; l <= N; l++) {
        d[l] = newd[l];
      }
    }
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        newd[j] = max(newd[j], (newd[i] - C[i][j]) * R[i][j]);
        //cout << "k: " << k << " i: " << i << " j: " << j << " ";
        //for(int ii = 1; ii <= N; ii++) {
        //  cout << newd[ii] << " ";
        //}
        //cout << endl;
      }
    }
  }

  int more = 0;
  for(int i = 1; i <= N; i++) {
    if(newd[i] > d[i]) {
      more = 1;
      break;
    }
  }

  if(more) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return 0;
}
