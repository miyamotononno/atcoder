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
int N;
ll W;
ll v[103], w[103];
ll Weight[103][100003]; // nこ目まで考慮して、価値がiの時の重さの最低値
ll INF = 1e18;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> W;
  rep(i, N) {
    cin >> w[i] >> v[i];
    rep(j, 100002) {
      Weight[i+1][j] = INF;
    }
  }

  rep(i, N) {
    rep(j, i*1000+1) { // 0からWまでの価値のrange
      Weight[i+1][j] = min(Weight[i+1][j], Weight[i][j]);
      if (Weight[i][j] + w[i] <= W) Weight[i+1][j+v[i]] = min(Weight[i+1][j+v[i]], Weight[i][j]+w[i]);
    }
  }

  int ans = 0;
  rep(i, N*1000+1) {
    if (Weight[N][i] > 0 && Weight[N][i] <= W) ans = i;
  }
  cout << ans << "\n";
  return 0;
}