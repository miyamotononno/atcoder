#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>
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
const ll MOD = 1000000007LL;
int N, W;
double P[3000];
double DP[3000][1500];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N){
    cin >> P[i];
  }

  W = (N-1)/2; //負ける数の上限
  DP[0][0] = 1;

  rep(i, N){
    rep(j, W+1){
      if (j<W) DP[i+1][j+1] += DP[i][j]*(1-P[i]);
      DP[i+1][j] += DP[i][j]*P[i];
    }
  }

  double ans = 0.0;
  rep(i, W+1) ans += DP[N][i];

  cout << setprecision(10) << ans << endl;
  return 0;
}
