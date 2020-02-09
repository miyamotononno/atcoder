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
ll R, B, x, y;

// 二分探索

bool check(ll X) {
  ll r = R - X, b = B - X;
  if (r < 0 || b < 0) return false;
  ll num = r/(x-1)+(b/(y-1));
  return num >= X;
}

ll binary_search(ll ng) {
  ll ok = 0ll;
  while(ng-ok>1) {
    ll mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> R >> B;
  cin >> x >> y;
  ll ng=(R+B)/2+1ll;

  cout << binary_search(ng) << "\n";
  return 0;
}