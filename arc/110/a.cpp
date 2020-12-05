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
int n;

ll calc_gcd(ll a, ll b) {
    if (b == 0) return a;
    return calc_gcd(b, a % b);
}

int main() {
  INCANT;
  cin >> n;
  ll ans = 1ll;
  for (int i=2; i<=n; i++) {
    ans *=i/calc_gcd(ans, i);
  }
  cout << ans+1 << endl;
  return 0;
}