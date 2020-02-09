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
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
string S;
int K;
ll DP[105][4]; // 右からn桁目までで０でないものを使った数字の個数。
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  cin >> K;
  
  for (int i=S.size()-1; i>=0; i--) {
    int n =S[i]-'0';
    if (i==S.size()-1) {
      DP[i][0] = 1;
      DP[i][1] = n;
      continue;
    }

    rep(j, n+1) {
      if (j==0) {
        rep(k, K) DP[i][k] += DP[i+1][k];
      } else {
        rep(k, K) DP[i][k+1] += DP[i+1][k]*9+DP[i+1][k+1]*10;
      }
    }
  }

  rep(i, K+1) {
    cout << DP[0][i] << "\n";
  }
  // cout << DP[0][K] << "\n";
  return 0;
}