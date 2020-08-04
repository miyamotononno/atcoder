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
int X, Y;
ll DP[1000001]; // n回動かした時に、たどり着くか

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

ll kaizyo(ll a, int c) {
  ll b = 1;
  rep(i, c) {
    b *= a;
    b%=MOD;
    a--;
  }
  return b;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> X >> Y;
  if ((X+Y)%3!=0) {
    cout << 0 << "\n";
    return 0;
  }
  int cnt = (X+Y)/3;
  int p1 = X-cnt;
  int p2 = Y-cnt;
  if (p1<0 || p2<0) {
    cout << 0 << "\n";
    return 0;
  }
  assert(p1==cnt-p2);
  ll bunshi = kaizyo(cnt, p1);
  ll bunbo = kaizyo(p1, p1);
  
  cout << bunshi%MOD*modinv(bunbo, MOD)%MOD << "\n";
  return 0;
}