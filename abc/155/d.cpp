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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;

ll n, K;
auto nC2 = [](ll a) { return a*(a-1)/2; };
vector<ll> Po,Ne;
bool is_nega; //負or正(≠0)

ll calc_count(ll X, vector<ll> &V, vector<ll> &W) {
  ll ret = 0ll;
  // t以上のものはWに何個あるかを求める
  rep(i, V.size()) {
    ll t = (X+V[i]-1)/V[i];
    int idx = lower_bound(ALL(W), t)-W.begin();
    if (!is_nega && i>=idx) ret += W.size()-i-1;
    else ret+=W.size()-idx;
  }
  return ret;
} 


int main() {
  INCANT;
  cin >> n >> K;
  ll a;
  rep(i, n) {
    cin >> a;
    if (a<0) Ne.push_back(-a); // 便宜上正にする
    else if (a>0) Po.push_back(a);
  }

  sort(ALL(Ne)); sort(ALL(Po));

  if (Ne.size()*Po.size()<K && K < nC2(n)-nC2(Po.size())-nC2(Ne.size())) {
    cout << 0 << "\n";
    return 0;
  }
  is_nega = Ne.size()*Po.size()>=K;
  ll ok = 0ll, ng = 1e18;
  ll base = is_nega?K-1:nC2(n)-K;
  while(ng-ok>1ll) {
    ll mid = (ok+ng)/2;
    ll r;
    if (is_nega) r = calc_count(mid, Ne,Po);
    else r = calc_count(mid, Ne, Ne)+calc_count(mid,Po, Po);
    if (r<=base) ng = mid;
    else ok = mid;
  } 
  if (is_nega) ok *= -1;

  cout << ok << "\n";
  return 0;
}
