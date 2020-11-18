#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
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
const ll INF = 2e18;
int n,m;
ll W[10];
ll L[100005], V[100005];

// ある牛の集合が渡れない最長の距離の橋
vector<ll> preprocessing() {
  vector<ll> dist(1<<n, 0);
  rep(bit,1<<n) {
    ll weight = 0ll;
    rep(i, n) if (bit & (1<<i)) weight+=W[i];
    rep(i, m) {
      if (V[i]<weight) {
        dist[bit] = max(dist[bit], L[i]);
      }
    }
  }
  return dist;
}

ll calc(vector<int>& ids, vector<ll>& dist) {
  vector<ll> dp(n, 0); // 先頭からi頭までの距離の最小値
  for(int i=1;i<n; i++) {
    int bit = (1<<ids[i]);
    for (int j=i-1; j>=0; --j) {
      // 先頭からi頭までの距離の最小値は、0<=j<iにおいて
      // 先頭からj頭までの距離の最小値+j頭からi頭までの距離の最大値
      bit |= (1<<ids[j]);
      dp[i] = max(dp[i], dp[j]+dist[bit]);
    }
  }
  return dp[n-1];
}

int main() {
  INCANT;
  cin >> n >> m;
  ll maxCamel=0ll;
  rep(i, n) {
    cin >> W[i];
    maxCamel=max(W[i], maxCamel);
  }
  ll minBrigeWeight=INF;
  rep(i, m) {
    cin >> L[i] >> V[i];
    minBrigeWeight = min(V[i], minBrigeWeight);
  }
  if (maxCamel>minBrigeWeight) {
    cout << -1 << endl;
    return 0;
  }

  vector<ll> dist = preprocessing();
  vector<int> ids(n);
  iota(ALL(ids) ,0); // 0からn-1までの値を生成(incrementする)
  ll ret = INF;
  do {
    ret = min(ret, calc(ids, dist));
  } while(next_permutation(ALL(ids)));
  cout << ret << endl;
  return 0;
}