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
const int INF = 1000000007;
int N, M;
int A[1005], B[1005], C[1005];
int DP[1005][1 << 12];
//dp[ i ][ S ] := 最初の i 個の鍵からいくつか選んで、
//開いた宝箱の集合が S で表されるような場合についての、最小コスト

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  rep(i, M){
    cin >> A[i] >> B[i];
    rep(j, B[i]) {
      int c;
      cin >> c; c--;
      C[i] += (1 << c); //　開けれる箱たちをbitで表現している
    }
  }

  rep(i, M+1){
    rep(j, 1 << N) {
      DP[i][j] = INF;
    }
  }
  DP[0][0] = 0; // 箱をあけないときは0コストでできる
  rep(i, M){
    rep(j, 1 << N) {
      DP[i+1][j] = min(DP[i][j], DP[i+1][j]);
      DP[i+1][j | C[i]] = min(DP[i+1][j | C[i]], DP[i][j] + A[i]);
    }
  }
  int ans = DP[M][(1<<N)-1] != INF ? DP[M][(1<<N)-1] : -1;
  cout << ans << "\n";
  return 0;
}