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
int N, K;
ll A[100003];
ll fac[100003], finv[100003], inv[100003];
 
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i <= N; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算
ll COM(int n){
    if (n < K-1) return 0;
    if (n < 0) return 0;
    return fac[n] * (finv[K-1] * finv[n - K + 1] % MOD) % MOD;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  rep(i, N) cin >> A[i];
  sort(A, A+N);
  COMinit();
  ll ans = 0ll;
  // MAXの方
  for (ll i=K-1; i<=N-1; i++) {
    ans += A[i]*COM(i);
    ans %= MOD;
  }
  // MINの方
  for (ll i=N-K; i>=0; i--) {
    ans -= A[i]*COM(N-i-1);
    ans%=MOD;
  }
  while(ans<0) ans+=MOD;
  cout << ans << "\n";
  return 0;
}