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
const int INF = 1e9+7;
int N, K, A[103];
bool DP[100003]; // 0:先手負け, 1:先手勝ち

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  rep(i, N) cin >> A[i];
  rep(i, K+1) {
    rep(j, N) {
      int next = i-A[j];
      if (next >= 0) DP[i] |= !DP[next];
    }
  }
  string ans = DP[K]? "First": "Second";
  cout << ans << "\n";
  return 0;
}