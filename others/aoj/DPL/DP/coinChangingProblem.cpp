#include <bits/stdc++.h>
using namespace std;

int calc(const int& n, const int& m, int d[]) {
  int dp[m][n+1]; // i枚を使った時の最小のコイン使用数
  for (int i=0; i<n+1; i++) dp[0][i] = i;
  for (int i=1; i<m; i++) {
    for (int j=0; j<n+1; j++) {
      dp[i][j] = dp[i-1][j];
      if (j>=d[i]) {
        dp[i][j] = min(dp[i][j-d[i]]+1, dp[i][j]);
      }
    }
  }
  return dp[m-1][n];
}

int main() {
  int n, m;
  cin >> n >> m;
  int d[m];
  for (int i=0; i<m; i++) cin >> d[i];
  sort(d, d+m);
  cout << calc(n,m,d) << endl;
}