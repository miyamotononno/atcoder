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
int n, m;
int a,b;
vector<int> G[101];
int d[101];
ll cnt[101];
typedef pair<int, int> P; //firstは最短距離、secondは頂点の番号

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + n, INF);
  d[s] = 0;
  cnt[s] = 1ll;
  que.push(P(0, s));
  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    rep(i, G[v].size()) {
      int e = G[v][i];
      if (d[e]<d[v]+1) continue;
      if (d[e] > d[v] + 1) {
        cnt[e]=cnt[v];
        d[e] = d[v]+1;
        que.push(P(d[e], e));
      } else if (d[e]==d[v]+1) {
        cnt[e]+=cnt[v];
        cnt[e]%=MOD;
      }
    }
  }
}

int main() {
  INCANT;
  cin >> n;
  cin >> a >> b;
  a--;b--;
  cin >> m;
  rep(i, m) {
    int x,y;
    cin >> x >> y;
    x--;y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dijkstra(a);
  cout << cnt[b] << "\n";
  return 0;
}