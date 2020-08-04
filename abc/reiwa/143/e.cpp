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
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const ll INF = 1e18;
ll cost[2005][2005]; //d[u][v]は辺e = (u, v)のコスト。存在しない場合はINF,ただしd[i][j]=0とする。
int counts[2005][2005];
int N, M, Q;
ll L;

void warshall_floyd_cost() {
  rep(k, N){
    rep(i, N){
      rep(j, N) cost[i][j] =min(cost[i][j], cost[i][k]+cost[k][j]);
    }
  }
}

void warshall_floyd_counts() {
  rep(k, N){
    rep(i, N){
      rep(j, N) counts[i][j] =min(counts[i][j], counts[i][k]+counts[k][j]);
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> L;
  int a,b;
  ll c;
  rep(i, N) rep(j, N) cost[i][j] = INF;
  rep(i, M) {
    cin >> a >> b >> c;
    a--;b--;
    cost[a][b] = c;
    cost[b][a] = c;
  }
  warshall_floyd_cost();
  rep(i, N) {
    rep(j, N) {
      if (cost[i][j] <= L) counts[i][j] = 1;
      else counts[i][j] = 1e9;
    }
  }
  cin >> Q;
  warshall_floyd_counts();
  int s, t;
  rep(i, Q) {
    cin >> s >> t;
    s--;t--;
    int ans=counts[s][t]=counts[s][t]==1e9?-1:counts[s][t]-1;
    cout << ans << "\n";
  }

  return 0;
}