#include <iostream>
#include <sstream>
using namespace std;
const int MAXN = 105;
const int MAXT = 1 << 30;
stringstream ss;
string s;
int table[MAXN][MAXN] = {MAXT};
int N, d[MAXN], v[MAXN];
int main() {

  cin >> N;
  for(int i = 0; i < N; i++) {
    d[i] = MAXT;
    v[i] = 0;
  }
  for(int i = 0; i < N; i++) {
    table[i][i] = 0;
  }
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < i; j++) {
        cin >> s;
        if(s == "x") {
          table[i][j] = MAXT;
        }
        else {
          ss << s;
          ss >> table[i][j];
          ss.clear();
        }
        table[j][i] = table[i][j];
    }
  }

  d[0] = 0;
  for(int k = 0; k < N; k++) {
     int minl = MAXT;
     int u = -1;
     for(int i = 0; i < N; i++) {
       if(!v[i] && d[i] < minl) {
         minl = d[i];
         u = i;
       }
     }
     v[u] = 1;
     for(int i = 0; i < N; i++) {
       if(!v[i] && table[u][i] != MAXT && d[i] > d[u] + table[u][i]) {
         d[i] = d[u] + table[u][i];
       }
     }
  }

  //for(int i = 0; i < N; i++) {
  //  for(int j = 0; j < N; j++) {
  //    cout << table[i][j] << " ";
  //  }
  //  cout << endl;
  //}

  int ans = 0;
  for(int i = 0; i < N; i++) {
    ans = max(ans, d[i]);
  }
  cout << ans << endl;
  return 0;
}
