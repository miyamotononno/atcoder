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
int t;
ll ans[101];

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
ll extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int main() {
  INCANT;
  cin >> t;
  ll n,s,k;
  rep(i, t) {
    cin >> n >> s >> k;
    ll x,y;
    ll d = extGCD(k, n, x,y);
    if (s%d>0) {
      ans[i]=-1;
    } else {
      if (x<0) {
        int e = (-x+n-1)/n;
        x+=e*n;
      }
      x*=(n-s)/d;
      ans[i]=x%(n/d);
    }
  }
  rep(i,t) {
    cout << ans[i] << endl;
  }
  return 0;
}