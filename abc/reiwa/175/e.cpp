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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int R, C, K;
ll DP[3004][3004][4];
ll items[3004][3004];

int main() {
  INCANT;
  cin >> R >> C >> K;
  int r,c;
  ll v;
  rep(i, K) {
    cin >> r >> c >> v;
    r--;c--;
    items[r][c] = v;
  }
  rep(i, R) {
    rep(j, C) {
      for (int k=2; k>=0; k--) {
        DP[i][j][k+1] = max(DP[i][j][k]+items[i][j], DP[i][j][k+1]);
      }
      rep(k,4) {
        DP[i][j+1][k] = max(DP[i][j+1][k], DP[i][j][k]);
        DP[i+1][j][0] = max(DP[i+1][j][0], DP[i][j][k]);
      }
    }
  }
  ll MAX=0ll;
  rep(i, 4) MAX=max(MAX, DP[R-1][C-1][i]);
  cout << MAX << endl;
  return 0;
}