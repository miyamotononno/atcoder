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
ll n,a,b;
ll mod2[33]; // 2^1, 2^2, 2^4, 2^8...

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
ll modinv(ll a) {
    return modpow(a, MOD - 2, MOD);
}

ll nCk(ll k) {
  ll ret = 1ll;
  rep(i, k) {
    ret *= n-i;
    ret%=MOD;
    ret *= modinv(i+1);
    ret %=MOD;
  }
  return ret;
}

void init() {
  mod2[0] =2ll;
  rep(i, 32) {
    mod2[i+1] = mod2[i]*mod2[i]%MOD;
  }
}

int main() {
  INCANT;
  cin >> n >> a >> b;
  init();
  ll towPowN=1ll;
  int idx=0;
  ll _n = n;
  while(_n>0) {
    if (_n%2==1) {
      towPowN*=mod2[idx];
      towPowN%=MOD;
    }
    _n/=2;
    idx++;
  }
  ll ans = towPowN - 1 - nCk(a) - nCk(b);
  while(ans<0) ans+=MOD;
  cout << ans << "\n";
  return 0;
}