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
int N;

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

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll a = MOD+1;
  ll b = 9ll;
  // a/bのあまりを求めたいときは逆元を使う。
  // 以下正しく111111112になる
  cout << a%MOD*modinv(b, MOD)%MOD << "\n";
  return 0;
}