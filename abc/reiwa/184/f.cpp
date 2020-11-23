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
ll t;
ll A[42];

vector<ll> get_all_permutation(vector<ll>& vec) {
  vector<ll> ret;
  rep(i, 1ll<<vec.size()) {
    ll tmp = 0ll;
    rep(bit, vec.size()) {
      if ((1ll<<bit) & i) tmp+=vec[bit];
    }
    ret.push_back(tmp);
  }
  sort(ALL(ret));
  return ret;
}

int main() {
  INCANT;
  cin >> n >> t;
  rep(i, n) cin >> A[i];
  vector<ll> C,D;
  rep(i, n/2) C.push_back(A[i]);
  for (int i=n/2; i<n; i++) D.push_back(A[i]);
  C = get_all_permutation(C);
  D = get_all_permutation(D);
  ll ans = 0;
  for (auto c: C) {
    int idx = upper_bound(ALL(D), t-c) -D.begin() -1;
    if (c+D[idx]>t) continue; 
    ans = max(ans, c+D[idx]);
  }
  
  cout << ans << "\n";
  return 0;
}