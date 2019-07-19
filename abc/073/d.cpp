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
#include <stack>
#include <set>
#include <map>
#include <limits>
#define rep(i,n) for (int i=0; i<n;++i)
using namespace std;
typedef long long ll;
const ll INF = 1e10;
int N, M, R;
ll d[203][203];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> R;
  vector<int> r(R);
  int u;
  rep(i, R){
    cin >> u;
    u--;
    r[i] = u;
  }

  rep(i, N){
    rep(j, N){
      if (i == j) d[i][j] = 0ll;
      else d[i][j] = INF;
    }
  }

  int a, b;
  ll t;
  rep(i, M){
    cin >> a >> b >> t;
    a--, b--;
    d[a][b] = t, d[b][a] = t;
  }
  rep(k, N){
    rep(i, N){
      rep(j, N) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
  }
  sort(r.begin(), r.end());
  ll min_d = INF;
  do {
    ll distance = 0;
    rep(i, R-1) distance+=d[r[i]][r[i+1]];
    min_d = min(min_d, distance);
  } while ( next_permutation(r.begin(), r.end()));

  cout << min_d << endl;  
  
  return 0;
}