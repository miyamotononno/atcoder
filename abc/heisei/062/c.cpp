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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll INF = 1000000007LL;
ll H, W;

ll calc(ll len1, ll len2){
  ll res = INF;
  ll a = len1/2;
  ll b = len1 - a;
  if (b>a){
    rep(i,len2){
      ll c1 = len1*i;
      ll c2 = (len2-i)*b;
      ll c3 = (len2-i)*a;
      // c2 > c3ではある
      ll d = c1>c2?c1-c3:max(c2-c3, c2-c1);
      res = min(res, d);
    }
  } else {
    rep (i, len2){
      res = min(abs(i*len1 - a*(len2-i)), res);
    }
  }
  return res;
}

ll calc2(ll len1, ll len2){
  ll res = INF;
  for (ll i=1; i*2<len1; i++){
    res = min(res, abs(i-(len1-2*i))*len2);
  }
  return res;
}


int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> W;
  if (H%3==0 || W%3==0){
    cout << 0 << "\n";
    return 0;
  }

  ll ans = INF;
  
  ans = min(ans, calc(H, W));
  ans = min(ans, calc(W, H));
  ans = min(ans, calc2(H, W));
  ans = min(ans, calc2(W, H));
  cout << ans << "\n";
  return 0;
}