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
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
ll A[81];

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> A[i];
  ll lower = A[0];
  ll higher = A[0];
  vector<P> V;
  rep(i, N) {
    if (i==0) continue;
    if (A[i]<higher) {
      V.push_back(P(lower, higher));
      lower = A[i];
      higher= A[i];
    } else {
      higher = A[i];
    }
  }
  V.push_back(P(lower, higher));
  ll ans = 1000ll;
  for (auto p: V) {
    ll lower = p.first; ll higher = p.second;
    ans = (ans / lower) * higher + ans%lower;
  }
  cout << ans << "\n";
  return 0;
}