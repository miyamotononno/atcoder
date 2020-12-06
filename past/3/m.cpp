#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n, m, s, k;
int T[17];
int TfromS[17];
struct edge {int to, cost; };
vector<int> GraphT[17];
vector<int> G[100005];
typedef pair<int, int> P; //firstは最短距離、secondは頂点の番号

void input() {
  cin >> n >> m;
  int u,v;
  rep(i, m) {
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  cin >> s >> k;
  s--;
  rep(i, k) {
    cin >>T[i];
    T[i]--;
  }
}

void dijkstra(int start, int d[]) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + n, INF);
  d[start] = 0;
  que.push(P(0, start));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    rep(i, G[v].size()) {
      int e = G[v][i];
      if (d[e] > d[v] + 1) {
        d[e] = d[v] + 1;
        que.push(P(d[e], e));
      }
    }
  }
}

void preprocessing() {
  int d[n+3];
  dijkstra(s, d);
  rep(i, k) TfromS[i]=d[T[i]];
  rep(i, k) {
    dijkstra(T[i], d);
    rep(j, k) {
      GraphT[i].push_back(d[T[j]]);
    }
  }
}

int rec(int S, int v, int dp[65537][17]){
  if (dp[S][v] >= 0) return dp[S][v];
  
  if (S == (1 << k) - 1) {
    return dp[S][v] = 0;
  }
  int res = INF;
  rep(u, k){
    if (!(S >> u & 1)){ // 次にuに移動する
      int tmp = rec(S | 1 << u, u, dp);
      tmp+=GraphT[v][u];
      res = min(res, tmp);
    }
  }
  return dp[S][v] = res;
}

int main() {
  INCANT;
  input();
  preprocessing();
  int dp[65537][17];
  int ans = INF;
  rep(i, k) {
    memset(dp, -1, sizeof(dp));
    int tmp = TfromS[i]+rec(1<<i, i, dp);
    ans  = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}