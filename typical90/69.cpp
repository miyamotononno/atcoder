#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

// 繰返し二乗法
void init(const ll& n, const ll& k, vector<ll>& powK) {
  ll exp = 1ll;
  powK.push_back(k); // k^1 % MOD = K
  while(exp<=n) {
    ll tail = powK.back();
    ll newVal = tail*tail%MOD;
    powK.push_back(newVal);
    exp*=2ll;
  }
}

ll calc(vector<ll>& powK, const ll& a) {
  int sz = powK.size();
  ll ret = 1ll;
  for (int bit=0; bit<sz; bit++) {
    if ((1ll<<bit)&a) { // long longなので1<<bitにしないこと!
      ret*=powK[bit];
      ret%=MOD;
    }
  }
  return ret;
}

int main() {
  ll N, K;
  cin >> N >> K;
  if (N==1ll) {
    cout << K << endl;
    return 0;
  }
  if (N==2ll) {
    ll ans =  K*(K-1) % MOD;
    cout << ans << endl;
    return 0;
  }
  if (K==2ll) {
    cout << 0 << endl;
    return 0;
  }
  ll ret=K*(K-1)%MOD;
  K-=2ll;
  vector<ll> powK;
  init(N, K, powK);
  N-=2ll;
  ll rest = calc(powK, N);
  ret*=rest;
  ret%=MOD;
  cout << ret << endl;
  return 0;
}