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
const ll MOD = 1e9+7LL;
int h, w;
char S[2003][2003];
ll dp[2003][2003];
ll rig[2003][2003], down[2003][2003], rd[2003][2003];

int main() {
  INCANT;
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> S[i][j];
  dp[0][0]=1ll;
  rep(i, h) {
    rep(j, w) {
      if (S[i][j]=='#') continue;
      if (i>0 && j>0) {
        rd[i][j] = rd[i-1][j-1]+dp[i-1][j-1];
        rd[i][j]%=MOD;
        dp[i][j]+=rd[i][j];
      }
      if (i>0) {
        down[i][j] = down[i-1][j]+dp[i-1][j];
        down[i][j]%=MOD;
        dp[i][j]+=down[i][j];
      }
      
      if (j>0) {
        rig[i][j] = rig[i][j-1]+dp[i][j-1];
        rig[i][j]%=MOD;
        dp[i][j]+=rig[i][j];
      }      
      dp[i][j]%=MOD;
    }
  }
  cout << dp[h-1][w-1] << endl;
  return 0;
}