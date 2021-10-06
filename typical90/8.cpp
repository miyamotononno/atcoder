#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0; i<n;++i)
int N;
string S;
typedef long long ll;
const ll MOD = 1e9+7;
ll dp[100004][8]; // 何も終わっていない - rまで終わった 

int main() {
  cin >> N;
  cin >> S;
  dp[0][0] = 1ll;
  for (int i=1; i<=N; i++) {
    rep(j, 8) {
      dp[i][j] = dp[i-1][j];
    }
    switch(S[i-1]) {
      case 'a':
        dp[i][1] += dp[i-1][0];
        dp[i][1] %= MOD;
        break;
      case 't':
        dp[i][2] += dp[i-1][1];
        dp[i][2] %= MOD;
        break;
      case 'c':
        dp[i][3] += dp[i-1][2];
        dp[i][3] %= MOD;
        break;
      case 'o':
        dp[i][4] += dp[i-1][3];
        dp[i][4] %= MOD;
        break;
      case 'd':
        dp[i][5] += dp[i-1][4];
        dp[i][5] %= MOD;
        break;
      case 'e':
        dp[i][6] += dp[i-1][5];
        dp[i][6] %= MOD;
        break;
      case 'r':
        dp[i][7] += dp[i-1][6];
        dp[i][7] %= MOD;
        break;
      default:
        break;
    }
  }
  cout << dp[N][7] << endl;
  return 0;
}