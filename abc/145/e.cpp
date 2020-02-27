#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, T;
int A[3003], B[3003];
int DP[3003][3000];
int INVDP[3003][3000]; 
// T-1分後までにi以外の食事を食べ、最後にiを食べるのは、
// T分後までにi-1とi+1以降の食事をする

// DP[i][j]はj分までで料理0-(i-1)まで注文できる時にかかる最大値
// DP[i][j]はj分までで料理(N-1)-(i)まで注文できる時にかかる最大値
// iこ目の料理でT分は、

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N  >> T;
  int a, b;
  rep(i, N) {
    cin >> a >> b;
    A[i] = a;
    B[i] = b;
  }
  rep(i, T) {
    if (i>=A[0]) DP[0][i] = B[0];
    else DP[0][i] = 0;
    if (i>=A[N-1]) INVDP[N-1][i] = B[N-1];
    else INVDP[0][i] = 0;
  }

  rep(i, N) {
    if (i==0) continue;
    rep(j, T) {
      if (j-A[i]<0) DP[i][j] = DP[i-1][j];
      else DP[i][j] = max(DP[i-1][j], DP[i-1][j-A[i]]+B[i]);
    }
  }

  for(int i=N-2; i>=0; i--) {
    rep(j, T) {
      if (j-A[i]<0) INVDP[i][j] = INVDP[i+1][j];
      else INVDP[i][j] = max(INVDP[i+1][j], INVDP[i+1][j-A[i]]+B[i]); 
    }
  }

  int ans = 0;
  rep(i, N) {
    rep(j, T) {
      if (i==0) ans = INVDP[1][T-1] + B[0];
      else if (i==N-1) ans = max(ans, DP[N-2][T-1]+B[N-1]);
      else ans = max(ans, DP[i-1][j]+INVDP[i+1][T-j-1]+B[i]);
    }
  }

  cout << ans << "\n";
  return 0;
}