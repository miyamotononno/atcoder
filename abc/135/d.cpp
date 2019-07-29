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
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
ll dp[100005][13]; // 1 - 桁数、2 - あまり。i桁目までで余りがjの個数
string S;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;

  dp[0][0] = 1; // 初期値

  rep (i, S.size()){ //　i桁目。昇順で考えていることに注意
    int trgt = -1;  
    if (S[i] != '?') trgt = S[i] - '0'; // i+1桁目の数
    if (trgt != -1) {
      // i桁目の余りは、i-1桁目までの余りkを10倍したものにi桁目の数jを加えて13で割った余りに等しい
      // kが0-12について考える
      rep(k, 13) dp[i+1][(k*10+trgt)%13] += dp[i][k];
    } else {
      //　i桁目が?のときはなんでも可能なのでi桁目を0-9で回して足し合わせることができる。
      rep(j, 10) {
        rep(k, 13) dp[i+1][(k*10+j)%13] += dp[i][k];
      }
    }
    rep(j, 13) dp[i+1][j] %= MOD;
  }

  cout << dp[S.size()][5] << endl;
  return 0;
}