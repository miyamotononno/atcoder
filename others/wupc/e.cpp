#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll INF = 1e18;
struct edge {int to; ll cost; };
typedef pair<ll, int> P;
int N, M;
vector<edge> G[1005]; //MAX_V
ll d[1005][28];

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  rep(i, N) rep(j,28) d[i][j] = INF;
  d[s][0] = 0ll;
  que.push(P(0ll, s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    int mod = p.first%28;
    if (d[v][mod] < p.first || v==N-1) continue;
    rep(i, G[v].size()) {
      edge e = G[v][i];
      ll n_cost = d[v][mod] + e.cost;
      if (d[e.to][n_cost%28] > n_cost) {
        d[e.to][n_cost%28] = n_cost;
        que.push(P(n_cost, e.to));
      }
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int f, t;
  ll c;
  rep(i, M) {
    cin >> f >> t >> c;
    G[f].push_back({t, c});
    G[t].push_back({f, c});
  }

  dijkstra(0);
  ll ans = INF;
  rep(i, 28) {
    if (i%4==0) ans = min(ans, d[N-1][i]);
    if (i%7==0) ans = min(ans, d[N-1][i]);
  }

  cout << ans << "\n";
  return 0;
}