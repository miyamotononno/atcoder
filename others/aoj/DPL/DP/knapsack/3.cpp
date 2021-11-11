#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9; 
const int MAXVALUE=100;

int getMaximumValue(int v[], int w[], const int& n, const int& W) {
  vector<vector<int>> dp(n, vector<int>(MAXVALUE*n+1, INF)); // i個まで考慮した時に価値がjとなる時の最小の重さ
  dp[0][0]=0;
  dp[0][v[0]]=w[0];
  for (int i=1;i<n; i++) {
    for (int j=0; j<MAXVALUE*n+1; j++) {
      dp[i][j] = dp[i-1][j]; // 何もしない
      if (j-v[i]>=0 && dp[i][j-v[i]]+w[i]<=W) {
        dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]]+w[i]); // 今回で足す
      }
    }
  }
  for (int i=MAXVALUE*n; i>=0; i--) {
    if (dp[n-1][i]<=W) return i;
  }
  return 0; 
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