#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
int n;
int A[200005];
int LastIdx[200005];
ll dp[200005];

int main() {
  INCANT;
  cin >> n;
  rep(i, n) {
    cin >> A[i];
    A[i]--;
  }
  vector<int> P(n, -1);
  fill(LastIdx, LastIdx+200005, -1);
  rep(i, n) {
    P[i] = LastIdx[A[i]];
    LastIdx[A[i]] = i;
  }

  fill(dp, dp+n, -1);
  dp[0] = 1ll;
  for (int i=1; i<n; i++) {
    dp[i] = dp[i-1];
    if (A[i]!=A[i-1] && P[i]>=0) {
      dp[i] += dp[P[i]];
      dp[i]%=MOD;
    } 
  }

  cout << dp[n-1] << endl;
  return 0;
}