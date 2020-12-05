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
#include <stack>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll INF = 1e18;
int n;
string S;
ll C[3004], D[3004];
ll dp[3004][3002]; // i文字目,stackに含まれている'('の数,最小コスト

int main() {
  INCANT;
  cin >> n >> S;
  rep(i, n) cin >> C[i];
  rep(i, n) cin >> D[i];
  rep(i,n+1) {
    rep(j, n) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0ll;
  rep(i, n) {
    if (S[i]=='(') {
      rep(j, i+1) dp[i+1][j+1] = min(dp[i][j], dp[i+1][j+1]);
      for (int j=1; j<=i; j++) dp[i+1][j-1] = min(dp[i][j]+C[i], dp[i+1][j-1]); // '('を')'に変える
      rep(j, i+1) dp[i+1][j] = min(dp[i][j] + D[i], dp[i+1][j]);
    } else {
      rep(j, i+1) dp[i+1][j+1] = min(dp[i][j]+C[i], dp[i+1][j+1]); // ')'を'('に変える
      for (int j=1; j<=i; j++) dp[i+1][j-1] = min(dp[i][j], dp[i+1][j-1]);
      rep(j, i+1) dp[i+1][j] = min(dp[i][j] + D[i], dp[i+1][j]);
    }
  }
  cout << dp[n][0] << endl;
  return 0;
}