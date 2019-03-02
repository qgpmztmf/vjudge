#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000010;

struct qnode{
  int v;
  int c;
  qnode(int _v = 0, int _c = 0):v(_v), c(_c){}
  bool operator <(const qnode &r)const{
    return c > r.c;
  }
};

struct Edge{
  int v, cost;
  Edge(int _v = 0, int _cost = 0):v(_v), cost(_cost){}
};

vector<Edge> E[MAXN];
vector<Edge> dE[MAXN];
bool v[MAXN];
int d[MAXN];

void Dijkstra(int n, vector<Edge> E[]) {
  memset(v, false, sizeof(v));
  for(int i = 1; i <= n; i++) {
    d[i] = INF;
  }
  priority_queue<qnode> pq;
  while(!pq.empty()) {
    pq.pop();
  }
  d[1] = 0;
  pq.push(qnode(1, 0));
  qnode tmp;

  while(!pq.empty()) {
    tmp = pq.top();
    pq.pop();
    int u = tmp.v;
    if(!v[u]) {
      v[u] = true;
      for(int i = 0; i < E[u].size(); i++) {
        int t = E[u][i].v;
        int cost = E[u][i].cost;
        if(!v[t] && d[t] > d[u] + cost) {
          d[t] = d[u] + cost;
          pq.push(qnode(t, d[t]));
        }
      }
    }
  }
}

void addedge(int u, int v, int w, vector<Edge> E[]) {
  E[u].push_back(Edge(v, w));
}

int main() {
  int N, P, Q, u, v, w, ans;
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
    Dijkstra(P, E);
    for(int i = 1; i <= P; i++) {
      ans += d[i];
    }
    Dijkstra(P, dE);
    for(int i = 1; i <= P; i++) {
      ans += d[i];
    }
    cout << ans << endl;

    for(int i = 0; i < MAXN; i++) {
        vector<Edge>().swap(E[i]);
        vector<Edge>().swap(dE[i]);
    }
  }
  return 0;
}
