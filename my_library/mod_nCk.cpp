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
const int MAX = 1e6;
 
ll fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
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


ll Comb[200005]; // nCkにおいてnが固定されている場合
ll K=100001;
ll N=200001;

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

ll modinv(ll a) {
    return modpow(a, MOD - 2);
}

void init() {
  Comb[0] = 1ll;
  rep(i, K) {
    if (i==0) continue;
    Comb[i] = Comb[i-1]*(N-i+1)%MOD*modinv(i)%MOD;
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  COMinit();
  cout << COM(5,2) << "\n";
  return 0;
}