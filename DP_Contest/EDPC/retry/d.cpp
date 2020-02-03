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
int N, W;
ll v[103], w[103];
ll Values[103][100003]; // nこ目が重さiの時の最大価値

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> W;
  rep(i, N) {
    cin >> w[i] >> v[i];
  }

  rep(i, N+1) {
    if (i==0) continue;
    rep(j, W+1) { // 0からWまでの重さ
      Values[i][j] = max(Values[i][j], Values[i-1][j]); // Nコめは使わない。その前のものを引き継ぐ。
      if (j + w[i-1] <= W) Values[i][j+w[i-1]] = max(Values[i][j+w[i-1]], Values[i-1][j] + v[i-1]); // Nコめを使う。
    }
  }

  ll ans = 0ll;
  rep(i, W+1) {
    ans = max(ans, Values[N][i]);
  }
  cout << ans << "\n";
  return 0;
}