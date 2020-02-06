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
int N, K;
ll A[103];
ll DP[103][100003]; //i人にあめがj個の分け方の場合の数
ll SUMDP[103][100003]; // DP[i][j]にはDP[i-1][j-a[i]]からDP[i-1][j]までの和が入る

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  rep(i, N) cin >> A[i];
  rep(i, A[0]+1) DP[0][i] = 1ll; // 一人だけだと1通りのみ(許容量を超えると0)

  rep(i, N) {
    if (i==0) continue;
    rep(j, K+1) {
      SUMDP[i][j] = j==0? DP[i-1][0]:SUMDP[i][j-1]+DP[i-1][j];
      if (j < A[i]+1) {
        DP[i][j] = SUMDP[i][j];
        DP[i][j] %= MOD;
      } else {
        DP[i][j] = SUMDP[i][j] - SUMDP[i][j-A[i]-1];
        DP[i][j] %= MOD;
      }
    }
  }

  cout << DP[N-1][K] << "\n";
  return 0;
}