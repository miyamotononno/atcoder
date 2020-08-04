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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL; 
int N;
bitset<60> A[300005];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  ll a;
  rep(i, N) {
    cin >> a;
    bitset<60> bs(a);
    A[i] = a;
  }
  ll ans = 0ll;
  rep(d, 60) { // 桁数
    ll m = 1ll<<d;
    m%=MOD;
    ll cnt1=0ll;
    ll cnt2=0ll;
    rep(i, N) {
      bitset<60> bs = A[i];
      if (bs[d]) cnt1++;
      else cnt2++; 
    }
    ll sm = cnt1*cnt2%MOD;
    ans+=(sm*m)%MOD;
  }
  ans%=MOD;
  cout << ans << "\n";
  return 0;
}