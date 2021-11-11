#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int MAX_ITEM_COUNT = 10000;

int getMaximumValue(int v[], int w[], int m[], const int& n, const int& W) {
  vector<vector<int>> dp(n, vector<int>(W+1, -INF));
  dp[0][0]=0;
  for (int i=0; i<n; i++) {
    if (i>0) for (int j=W; j>=0; j--) dp[i][j] = dp[i-1][j];
    for (int bit=0; bit<=14; bit++) {
      int num = 1 << bit;
      num = min(num, m[i]);
      if (num==0) break;
      for (int j=W; j>=0; j--) {
        if (j-num*w[i]>=0) dp[i][j] = max(dp[i][j], dp[i][j-num*w[i]]+v[i]*num);
      }
      m[i]-=num;
    }
  }
  int ans = 0;
  for (int i=0; i<=W; i++) ans = max(ans, dp[n-1][i]);
  return ans;
}

int main() {
  int n,W;
  cin >> n >> W;
  int v[n],w[n], m[n];
  for (int i=0; i<n; i++) {
    cin >> v[i] >> w[i] >> m[i];
  }
  cout << getMaximumValue(v,w,m, n,W) << endl;
}