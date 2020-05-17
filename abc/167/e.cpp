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
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 998244353;
int N, M, K;
ll Comb[200005], Zyo[200005]; // n-1Ck.

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

void init(){
  Comb[0] = 1ll;
  rep(i, N) {
    Comb[i+1]=Comb[i]*(N-1-i)%MOD*modinv(i+1);
    Comb[i+1]%=MOD;
  }
  Zyo[0] = 1ll;
  rep(i, N) {
    if (i==0) continue;
    Zyo[i] = Zyo[i-1]*(M-1);
    Zyo[i]%=MOD;
  }
}

// 隣り合う組で同じ色で塗られているのをK色と固定
// 左端の色はM通り、それ以外は左と違う色がN-1-K, 同じがK個。それの並べ替え
// M*n-1Ck*(M-1)^(N-1-K)*1^K

int main() {
  INCANT;
  cin >> N >> M >> K;
  init();
  ll SUM=0;
  rep(i, K+1) {
    SUM += M*Comb[i]%MOD*Zyo[N-1-i];
    SUM%=MOD;
  }
  if (SUM<0) SUM+=MOD;

  cout << SUM << "\n";
  return 0;
}