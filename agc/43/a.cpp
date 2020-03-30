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
int H, W;
char s[101][101];
int DP[101][101];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> W;
  rep(i, H) rep(j, W) {
    cin >> s[i][j];
    DP[i][j] = INF;
  }
  DP[0][0] = s[0][0] == '#'?1:0;
  rep(i, H) {
    rep(j, W) {
      char c = s[i][j];
      if (i<H-1) {
        char yoko = s[i+1][j];
        if (c=='.'&& yoko=='#') DP[i+1][j] = min(DP[i][j] + 1, DP[i+1][j]);
        else DP[i+1][j] =  min(DP[i][j], DP[i+1][j]);
      }
      if (j<W-1) {
        char tate = s[i][j+1];
        if (c=='.'&& tate=='#') DP[i][j+1] = min(DP[i][j] + 1, DP[i][j+1]);
        else DP[i][j+1] = min(DP[i][j], DP[i][j+1]);
      }
    }
  }

  cout << DP[H-1][W-1] << endl;
  return 0;
}