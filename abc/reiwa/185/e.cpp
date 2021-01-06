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
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const int INF = 2e9;
int n, m;
int A[1003],B[1003];
int dp[1003][1003];
void chmin(int &a, int b) { if (a > b) a = b; }
// LCS(最小共通部分文字列)に似てる

int main() {
  INCANT;
  cin >> n >> m;
  rep(i, n) cin >> A[i];
  rep(i, m) cin >> B[i];
  rep(i, n+1) rep(j, m+1) dp[i][j] = INF;
  dp[0][0]=0;
  rep(i, n+1) {
    rep(j, m+1) {
      if (i>0) chmin(dp[i][j], dp[i-1][j]+1); // Aの末尾を削除する
      if (j>0) chmin(dp[i][j], dp[i][j-1]+1); // Bの末尾を削除する
      if (i>0 && j>0) {
        if (A[i-1]==B[j-1]) chmin(dp[i][j], dp[i-1][j-1]);
        else chmin(dp[i][j], dp[i-1][j-1]+1);
      }
    }
  }

  cout << dp[n][m] << endl;
  return 0;
}