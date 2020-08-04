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
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
ll N, C;
ll x[100003], v[100003], r[100003], l[100003];

int main () {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> C;
  rep(i,N) cin >> x[i] >> v[i];

  ll ans = 0;

  // r[i]はOから反時計回りのvalueの総和
  // l[i]はOから時計回りのvalueの総和

  // 一回も折り返さなかった時の場合
  ll y = 0, z = 0;
  rep(i,N) {
    y += v[i];
    z += v[N-1-i];
    r[i+1] = max(r[i], y - x[i]);
    l[i+1] = max(l[i], z - (C - x[N-i-1]));
    ans = max(ans, max(r[i+1], l[i+1]));
  }

  // 一回折り返した時の場合
  y = 0, z = 0;
  rep(i,N) {
    y += v[i];
    z += v[N-1-i];
    ans = max(ans, y - 2*x[i] + l[N-i-1]);
    ans = max(ans, z - 2*(C - x[N-1-i]) + r[N-i-1]);
  }

  cout << ans << endl;
  return 0;
}
