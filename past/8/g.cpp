#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;
struct query {ll a,b,c;};

ll calc_cnt(const query& q, const ll& v) {
  ll a = q.a;
  ll b = q.b;
  ll c = q.c;
  if (v<b) return 0ll;
  // b, b+c, b+2*c, ... , b+(a-1)*c
  return min((v-b+c) / c, a);
}
 
ll solve(const vector<query>& Q, const ll& k, const ll& maxK, const ll& minK) {
  ll ok = maxK;
  ll ng = minK-1;
  while(ok-ng > 1) {
    ll mid = (ok+ng) / 2;
    ll ret = 0ll;
    for (query q: Q) {
      ret += calc_cnt(q, mid);
    }
    if (ret < k) ng = mid;
    else ok = mid;
  }
  return ok;
}

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<query> Q;
  ll minK = INF;
  ll maxK = 0ll;
  for (int i=0; i<n; i++) {
    ll a,b,c;
    cin >> a >> b >> c;
    query q = query{a,b,c};
    Q.push_back(q);
    maxK = max(b+(a-1)*c, maxK);
    minK = min(minK, a);
  }
  cout << solve(Q, k, maxK, minK) << endl;

  
}