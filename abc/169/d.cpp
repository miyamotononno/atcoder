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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
ll N;

map<ll, int> prime_factor(ll n) {
  map<ll, int> ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int calc(int x) {
  if (x<=2) return 1;
  int a=0;
  while(a*(a+1)/2<=x) {
    a++;
  }
  return a-1;
}

int main() {
  INCANT;
  cin >> N;
  map<ll, int> ret = prime_factor(N);
  int ans = 0;
  for (auto p: ret) ans +=calc(p.second);
  cout << ans << endl;
  return 0;
}