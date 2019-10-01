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
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int K;
double DP[1<<10][11]; // iがj連勝するときの確率

double probability(double Rp, double Rq){
  return 1.0/(1.0+pow(10.0, (Rq - Rp)/400.0));
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> K;
  double R[1 << K];
  rep(i, 1 << K){
    cin >> R[i];
    DP[i][0] = 1.0;
  }
  // j連勝後に戦う候補となる相手の候補は,
  // (0-indexedで考えた時に)jbitが異なり、jbit目以降は同じ相手である
  rep(j, K){
    rep(bit, 1 << K){
      int mask = 0;
      for (int l = K-1; l > j; l--){ 
        if (bit & 1 << l) mask += 1 << l; //bitのl文字目が立っていたらmaskのl文字目も立たせる。
      }
      if (!(bit & 1 << j )) mask += 1 << j; //j-1のフラグが立っていなければ、maskのフラグをたたせる。

      double sm = 0.0;
      rep(l, 1 << j){
        // l+maskのbitが最終的な対戦相手
        sm += DP[l + mask][j] * probability(R[bit], R[l + mask]);
      }
      DP[bit][j+1] = DP[bit][j] * sm;
    }
  }

  rep (i, 1 << K){
    cout << fixed << setprecision(9) << DP[i][K] << "\n";
  }
  return 0;
}