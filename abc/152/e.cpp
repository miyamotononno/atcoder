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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
int N;
ll A[10005];
map<ll, ll> M[10005], lcp;

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
ll modinv(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}

map<ll, ll> prime_factor(ll n) {
  map<ll, ll> ret;
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> A[i];
  rep(i, N) {
    map<ll, ll> ret = prime_factor(A[i]);
    M[i] = ret;
    for(auto p : ret) {
      lcp[p.first] = max(p.second, lcp[p.first]);
    }
  }

  ll mod_lcp =  1ll;
  for(auto p : lcp) {
    mod_lcp *= pow(p.first, p.second);
    mod_lcp%=MOD;
  }
  
  ll ans = 0ll;
  rep(i, N) {
    ans+=mod_lcp*modinv(A[i], MOD)%MOD;
    ans%=MOD;
  }
  while(ans<0) ans+=MOD;
  cout << ans << "\n";
  return 0;
}