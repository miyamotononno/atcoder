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
ll h[100005], A, B;

bool check(ll cnt) {
  vector<ll> w(n);
  ll now = 0ll;
  rep(i, n) {
    w[i] = max(0ll, h[i]-cnt*B);
    now+=(w[i]-B+A-1)/(A-B);
  }
  return cnt>=now;
}

int main() {
  INCANT;
  cin >> n >> A >> B;
  ll ok = 0ll;
  rep(i, n) {
    cin >> h[i];
    ok = max(ok, h[i]);
  }
  ll ng = 0ll;
  while(ok-ng>1) {
    ll mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}