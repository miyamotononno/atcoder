#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
int N;
ll DP[101][4][4][4];
ll modpow4[101];

const char S[4] = {'A', 'C', 'G', 'T'};
/* 
  ngな文字列
  agc, acg, gac
  agxc, axgc
*/

int henkan(char c) {
  rep(i, 4) {
    if (S[i]==c) return i;
  }
  return -1;
}

ll dfs(int idx, char preprepre, char prepre, char pre) {
  if (idx == N) return 0;
  if (DP[idx][henkan(preprepre)][henkan(prepre)][henkan(pre)] > 0) return DP[idx][henkan(preprepre)][henkan(prepre)][henkan(pre)];
  ll ret = 0ll;
  rep(i, 4) {
    char now = S[i];
    if (preprepre == 'A') {
      if ((pre == 'G' || prepre == 'G') && now == 'C') {
        ret += modpow4[N-idx-1];
        continue;
      }
    }
    if (prepre=='A') {
      if ((pre == 'G' && now == 'C') || (pre == 'C' && now == 'G')) {
        ret += modpow4[N-idx-1];
        continue;
      }
    }
    if (prepre == 'G' && pre == 'A' && now == 'C') {
      ret += modpow4[N-idx-1];
      continue;
    }
    ret += dfs(idx+1, prepre, pre, now);
  }
  ret %= MOD;
  DP[idx][henkan(preprepre)][henkan(prepre)][henkan(pre)] = ret;
  return ret;
}

// DP[idx][4] // idx文字目がa,g,c,tで大丈夫な場合の和
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  ll ans = 1ll;
  rep(i, N+1) {
    ans %= MOD;
    modpow4[i] = ans;
    ans*=4ll;
  }
  ll ret = dfs(0, 'T', 'T', 'T');
  cout << (modpow4[N] + MOD - ret) % MOD<< endl;
  return 0;
}