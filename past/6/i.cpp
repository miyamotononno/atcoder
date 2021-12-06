#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[101][101][201];

void solve(const vector<vector<ll>>& A) {
  int h = A.size();
  int w = A[0].size();
  dp[0][0][1] = A[0][0];
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      for (int k=1; k<=h+w-1; k++) {
        if (j>0) {
          dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
          dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]+A[i][j]);
        }
        if (i>0) {
          dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
          dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]+A[i][j]);
        }
      }
    }
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<ll>> A(h, vector<ll>(w));
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      cin >> A[i][j];
    }
  }
  solve(A);
  for (int i=1; i<h+w; i++) {
    cout << dp[h-1][w-1][i] << endl; 
  }
}