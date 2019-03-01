#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAXN = 35;
string A, B;
double w, n, m, num, table[MAXN][MAXN] = {0};
int main() {
  num = 0;
  while(cin >> n && n) {
    map<string, int> c;
    for(int i = 0; i < n; i++) {
      string temp;
      cin >> temp;
      c[temp] = i;
    }
    cin >> m;
    for(int i = 0; i < n; i++) {
      table[i][i] = 1;
    }
    for(int i = 0; i < m; i++) {
      cin >> A >> w >> B;
      table[c[A]][c[B]] = w;
    }

    //for(int i = 0; i < n; i++) {
    //  for(int j = 0; j < n; j++) {
    //    cout << table[i][j] << " ";
    //  }
    //  cout << endl;
    //}
    double d[MAXN] = {0};
    double od[MAXN] = {0};
    d[0] = 1;
    od[0] = 1;
    for(int k = 0; k < 2 * n; k++) {
      if(k == n) {
        for(int l = 0; l < n; l++) {
          od[l] = d[l];
        }
      }
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          d[j] = max(d[j], d[i] * table[i][j]);
        }
      }
    }

    int judge = 0;
    for(int i = 0; i < n; i++) {
      if(od[i] < d[i]) {
        judge = 1;
        break;
      }
    }

    num++;
    if(judge){
      cout << "Case " << num << ": " << "Yes" << endl;
    }
    else {
      cout << "Case " << num << ": " << "No" << endl;
    }
  }
  return 0;
}
