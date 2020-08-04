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
#define rep_itr(it, M) for (auto it = M.begin(); it != M.end(); ++it)
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
int N,A,B;

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
ll modinv(ll a) {
    return modpow(a, MOD - 2);
}

ll kaizyo(ll a, int cnt) {
  ll b = 1;
  rep(i, cnt) {
    b *= a;
    b%=MOD;
    a--;
  }
  return b;
}

// numのpow乗をmodで計算する
ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1;
    num %= mod;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % mod;
        num = num * num % mod;
        pow >>= 1;
    }
    return prod;
}


int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> A >> B;
  ll ans = 1ll;
  ll abc = pow_mod(2, N, MOD);
  ll inv_a = kaizyo(N, A)*modinv(kaizyo(A, A))% MOD;
  ll inv_b = kaizyo(N, B)*modinv(kaizyo(B, B))% MOD;
  cout << ((abc-inv_a-inv_b-1)%MOD+MOD)%MOD << "\n";
  return 0;
}