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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, M, X, Y;
int x[102], y[102];

int main() {
  INCANT;
  cin >> N >> M >> X >> Y;
  rep(i, N) cin >> x[i];
  rep(i, M) cin >> y[i];

  bool flag = true;
  for (int z=X+1; z<=Y; z++) {
    bool ok = true;
    rep(i, N) {
      if (x[i]>=z) {
        ok=false;
        break;
      }
    }
    rep(i, M) {
      if (y[i]<z) {
        ok=false;
        break;
      }
    }
    if (ok) {
      flag=false;
      break;
    }
  }
  string ans = flag?"War":"No War";
  cout << ans << "\n";
  return 0;
}