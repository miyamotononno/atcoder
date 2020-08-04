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
const int INF = 2e9;
int A, B;
ll X;

bool ok(ll N) {
  ll digit = 1;
  ll X2 = N;
  while(X2/10>0) {
    digit++;
    X2/=10;
  }
  return A*N+B*digit <=X;
}

ll binary_search(ll l, ll r) {
  while(r-l>1) {
    ll mid = (r+l)/2;
    if (ok(mid)) l = mid;
    else r = mid;
  }
  return l;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B;
  cin >> X;
  
  cout << binary_search(0, 1000000001) << "\n";
  return 0;
}