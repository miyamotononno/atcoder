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
const int INF = 2e9;
ll n, k;

ll calc(ll x) {
  return x - 1 - max(x-n-1, 0ll)*2;
}

int main() {
  INCANT;
  cin >> n >> k;
  ll ret = 0ll;
  for (ll a_b=2; a_b<=2*n; a_b++) {
    ll c_d = a_b - k;
    if (c_d < 2 || c_d > 2*n) continue;
    ret+=calc(a_b)*calc(c_d);
  }
  cout << ret << endl;
  return 0;
}