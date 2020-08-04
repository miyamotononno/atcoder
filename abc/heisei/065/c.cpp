#include <algorithm>
#include <iostream>
#include <iomanip>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
ll N, M, kaizyo[100005]; 

void init() {
  kaizyo[0] = 1ll;
  rep(i, 100005) {
    if (i==0) continue;
    kaizyo[i] = kaizyo[i-1]*i % MOD;
  }
}

int main() {
  INCANT;
  cin >> N >> M;
  init();
  if (abs(N-M)>=2) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = kaizyo[N]*kaizyo[M]%MOD;
  if (N!=M) {
    cout << ans << endl;
    return 0;
  }

  ans *=2ll;
  ans %= MOD;
  cout << ans << endl;
  
  return 0;
}