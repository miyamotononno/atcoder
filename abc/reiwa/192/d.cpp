#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
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
const int INF = 2e9;
string x;
ll m;

bool calc(ll d) {
  ll ret = 0ll;
  rep(i, x.size()) {
    ll digit = x[i]-'0';
    if (ret>(m-digit)/d) return false;
    ret*=d;
    ret+=digit;
  }
  return ret<=m;
}

// d^sz <= mとなる最大のdは?
int main() {
  INCANT;
  cin >> x;
  cin >> m;
  if (x.size()==1) {
    ll d =x[0]-'0';
    if (d<=m) cout << 1 << endl;
    else cout << 0  << endl;
    return 0;
  }
  int mind = 0;
  for (auto c: x) {
    mind = max(mind, c-'0');
  }

  int ans = 0;
  ll ok = mind;
  ll ng = 1e18;
  ng++;
  while(ng-ok>1) {
    ll mid = (ok+ng)/2;
    if (calc(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok-mind << endl;
  
  return 0;
}