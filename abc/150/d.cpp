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
typedef long long ll;
using namespace std;
int N;
ll M, a[100005];

// gcd lcm
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
  rep(i, N) cin >> a[i];
  ll lcm = a[0]/2;
  ll gcd = a[0]/2;

  rep(i, N) {
    gcd = calc_gcd(gcd, a[i]/2);
    lcm = calc_lcm(lcm, a[i]/2);
  }

  rep(i, N) {
    if ((a[i]/2/gcd)%2==0) {
      cout << 0 << "\n";
      return 0;
    }
  }

  ll cnt=M/lcm; //1-M間で初項がlcm,等差が2*lcmの等差数列の個数
  cout << (cnt+1)/2 << "\n";
  return 0;
}
