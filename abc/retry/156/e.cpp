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
ll n, k;
const int MAX = 1e6;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

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

// 2*n-1Cn

int main() {
  INCANT;
  cin >> n >> k;
  if (n<=k) {
    ll ret = 1ll;
    rep(i, n) {
      ret*=2*n-1-i;
      ret%=MOD;
      ret*=modinv(i+1);
      ret%=MOD;
    }
    cout << ret << endl;
    return 0;
  }
  COMinit();
  // 何部屋0人部屋になるか
  // どの部屋が0人部屋か=>k部屋でnCk
  // 各部屋一人以上になるようにn人をn-kに分ける
  //=>n人の間のn-1この隙間にn-k-1この仕切りを入れる=>n-1Cn-k-1
  ll ret =0ll;
  rep(i, k+1) {
    ret+=COM(n,i)*COM(n-1, n-i-1)%MOD;
    ret%=MOD;
  }
  
  cout << ret << "\n";
  return 0;
}