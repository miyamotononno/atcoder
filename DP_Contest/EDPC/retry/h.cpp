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
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
int H, W;
ll MOD = 1e9+7;
char a[1003][1003];
ll DP[1003][1003];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> W;
  rep(i, H) {
    rep(j, W) {
      cin >> a[i][j];
    }
  }
  
  DP[0][0] = 1;
  rep(i, H) {
    rep(j, W) {
      if (i+1 < H && a[i+1][j]=='.') {
        DP[i+1][j]+=DP[i][j];
        DP[i+1][j]%=MOD;
      }
      if (j+1 < W && a[i][j+1]=='.') {
        DP[i][j+1]+=DP[i][j];
        DP[i][j+1]%=MOD;
      }
    }
  }
  
  cout << DP[H-1][W-1] << "\n";
  return 0;
}