#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000010;
const long long INF = 1000000009;
struct Edge{
  int v;
  long long cost;
  Edge(int _v, int _cost): v(_v), cost(_cost){}
};
vector<Edge> E[MAXN];
vector<Edge> dE[MAXN];

void addedge(int u, int v, int w, vector<Edge> E[]) {
  E[u].push_back(Edge(v, w));
}


bool v[MAXN];
int cnt[MAXN];
long long d[MAXN];
bool spfa(int n, vector<Edge> E[]) {
  memset(v, false, sizeof(v));
  for(int i = 1; i <= n; i++) {
    d[i] = INF;
  }

  queue<int> q;
  d[1] = 0;
  v[1] = true;
  q.push(1);
  memset(cnt, 0, sizeof(cnt));
  cnt[1] = 1;

  while(!q.empty()) {
    int u = q.front();
    q.pop();
    v[u] = false;
    for(int i = 0; i < E[u].size(); i++) {
      int t = E[u][i].v;
      int cost = E[u][i].cost;
      if(d[t] > d[u] + cost) {
        d[t] = d[u] + cost;
        if(!v[t]) {
          v[t] = true;
          q.push(t);
          if(++cnt[t] > n) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

int main() {
  int N, P, Q, u, v, w;
  long long ans;
  scanf("%d", &N);
  //cin >> N;
  while(N--) {
    ans = 0;
    scanf("%d%d", &P, &Q);
    //cin >> P >> Q;
    for(int i = 0; i < Q; i++) {
      scanf("%d%d%d", &u, &v, &w);
      //cin >> u >> v >> w;
      addedge(u, v, w, E);
      addedge(v, u, w, dE);
    }
    spfa(P, E);
    for(int i = 1; i <= P; i++) {
      ans += d[i];
    }
    spfa(P, dE);
    for(int i = 1; i <= P; i++) {
      ans += d[i];
    }
    cout << ans << endl;

    for(int i = 0; i <= P; i++) {
        vector<Edge>().swap(E[i]);
        vector<Edge>().swap(dE[i]);
    }
  }
  return 0;
}
