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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n;
ll A[100005], B[100005];
typedef pair<ll, ll> P;

int main() {
  INCANT;
  cin >> n;
  rep(i, n) cin >> A[i] >> B[i];
  vector<P> C(n);
  rep(i, n) {
    C[i] = P(B[i] + A[i], i);
  }
  sort(ALL(C), greater<P>());
  ll ret=0ll;
  rep(i, n) {
    if (i%2==0) ret+=A[C[i].second];
    else ret-=B[C[i].second];
  }
  cout << ret << "\n";
  return 0;
}