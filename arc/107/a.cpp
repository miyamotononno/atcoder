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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 998244353;
ll a, b, c;

int main() {
  INCANT;
  cin >> a >> b >> c;
  ll d = a*(a+1)/2%MOD;
  ll e = b*(b+1)/2%MOD;
  ll f = c*(c+1)/2%MOD;
  cout << d*e%MOD*f%MOD << "\n";
  return 0;
}