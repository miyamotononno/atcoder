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

vector<ll> prime_factor(ll X) {
  vector<ll> primes;
  for (ll i=1ll; i*i<=X; i++) {
    if (X%i==0) {
      if (i*i==X) {
        primes.push_back(i);
      } else {
        primes.push_back(i);
        primes.push_back(X/i);
      }
    }
  }
  return primes;
}

int main() {
  INCANT;
  ll X;
  cin >> X;
  if (X==1) {
    cout << 2 << endl;
    return 0;
  }
  // 項数n, 初項d
  // 2X = (2d+n-1)*n
  vector<ll> primes = prime_factor(2*X);
  int cnt=0;
  for (auto p: primes) {
    // 2d = 2x/p - p + 1
    ll d2 = (2*X)/p - p + 1;
    cnt += (d2%2==0);
  }

  cout << cnt << endl;
  return 0;
}