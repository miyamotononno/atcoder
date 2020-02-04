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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 1e9+7;
int N;
double p[3004];
double DP[3004][3004]; // iまで考慮してj回勝利した時の確率

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> p[i];
  DP[0][0] = 1.0;
  rep(i, N+1) {
    if (i==0) continue;
    rep(j, i+1) { // i回目の時は0回からi+1回までのi+2通りある。
      if (j==0) {
        DP[i][j] = (1.0-p[i-1])*DP[i-1][j];
        continue;
      }
      DP[i][j] = (1.0-p[i-1])*DP[i-1][j] + p[i-1]*DP[i-1][j-1];
    }
  }

  double ans = 0.0;
  for (int i=N/2+1; i<N+1; i++) {
    ans += DP[N][i];
  }
  cout << setprecision(10) << ans << "\n";
  return 0;
}