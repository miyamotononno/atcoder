#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9; 

int getMaximumValue(int v[], int w[], const int& n, const int& W) {
  vector<vector<int>> dp(n, vector<int>(W+1, -INF));
  for (int i=0; i*w[0]<W+1; i++) dp[0][w[0]*i] = v[0]*i;

  for (int i=1; i<n; i++) {
    for (int j=0; j<W+1; j++) {
      dp[i][j] = dp[i-1][j];
      if (j>=w[i]) {
        dp[i][j] = max({dp[i][j], dp[i][j-w[i]]+v[i], dp[i-1][j-w[i]]+v[i]});
      }
    }
  }
  int ans = 0;
  for (int i=0; i<W+1; i++) {
    ans = max(ans, dp[n-1][i]);
  }
  return ans;
}

int main() {
  int n,W;
  cin >> n >> W;
  int v[n],w[n];
  for (int i=0; i<n; i++) {
    cin >> v[i] >> w[i];
  }
  cout << getMaximumValue(v,w,n,W) << endl;
}