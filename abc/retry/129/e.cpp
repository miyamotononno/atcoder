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
int n;
string L;
// a,bは各桁で(0,0), (0,1), (1,0)
ll DP[100002][2]; // 左から走査して、i桁目で無条件になんでもOKもしくは制限付き
ll E3[100002];

void init() {
  E3[0] = 1ll;
  rep(i, n+1) {
    E3[i+1] = E3[i]*3ll%MOD;
  }
}

ll dfs(int idx, bool ok) {
  if (idx==n) return 1ll;
  if (ok) return E3[n-idx];

  ll ret;
  if (L[idx]=='0') ret=dfs(idx+1, false);
  else ret=dfs(idx+1, true) + 2*dfs(idx+1, false);
  ret%=MOD;
  return ret;
}


int main() {
  INCANT;
  cin >> L;
  n = L.size();
  init();
  cout << dfs(0, false) << endl;
  return 0;
}