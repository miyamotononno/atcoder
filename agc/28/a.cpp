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
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
ll N, M;
string S, T;

ll calc_gcd(ll a, ll b) {
    if (b == 0) return a;
    return calc_gcd(b, a % b);
}

ll calc_lcm(ll a, ll b) {
    ll g = calc_gcd(a, b);
    return a / g * b;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  cin >> S >> T; 

  ll lcm = calc_lcm(N, M);
  ll gcd = calc_gcd(N, M);
  ll s = N/gcd;
  ll t = M/gcd; 

  bool flag = false;
  rep(i, gcd){
    if (S[s*i] != T[t*i]){
      flag = true;
      break;
    }
  }

  ll ans = flag?-1:lcm;
  cout << ans << endl;
  return 0;
}