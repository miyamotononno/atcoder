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
#include <map>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
ll A, B;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

map< ll, ll > prime_factor(ll n) {
  map< ll, ll > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1ll) ret[n] = 1ll;
  return ret;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B;
  ll g = gcd(A, B);
  map<ll, ll> M = prime_factor(g);
  cout << M.size()+1 << "\n";
  return 0;
}