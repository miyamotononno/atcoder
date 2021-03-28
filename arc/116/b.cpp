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
const ll MOD = 998244353;
const int INF = 2e9;
int n;
ll A[200005], minCount[200005], maxCount[200005];
ll CulSum[200005];

void func() {
  CulSum[0] = A[0];
  for (int i=1; i<n; i++) {
    CulSum[i] = 2*CulSum[i-1]-A[i-1]+A[i];
    CulSum[i]%=MOD;
  }
}

int main() {
  INCANT;
  cin >> n;
  rep(i, n) cin >> A[i];
  sort(A, A+n);
  func();
  ll ans = 1ll;
  rep(i, n) {
    ll d = A[i]*CulSum[i];
    d%=MOD;
    ans+=d;
    ans%=MOD;
  }
  cout << (ans+MOD-1)%MOD << "\n";
  return 0;
}