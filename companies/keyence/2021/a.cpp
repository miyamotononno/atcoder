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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n;
ll a[200005], b[200005], c[200005];

int main() {
  INCANT;
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll ma = a[0];
  c[0] = a[0]*b[0];
  for (int i=1; i<n; i++) {
    ma = max(ma, a[i]);
    c[i]= max(c[i-1], ma*b[i]);
  }
  rep(i, n) cout << c[i] << endl;
  return 0;
}