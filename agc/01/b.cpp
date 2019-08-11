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
ll N, X;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> X;
  ll ans = N; // X + N - X
  bool flag = true;
  ll a = max(X, N-X);
  ll b = min(X, N-X);
  while(flag){
    ll sy = a/b;
    ll am = a%b;
    ans+=(2*sy)*b;
    if (am==0){
      ans -= b;
      flag = false;
    }
    a = b;
    b = am;
  }

  cout << ans << endl;
  return 0;
}