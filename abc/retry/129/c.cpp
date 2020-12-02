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
int n, m;
ll ans[100003];
unordered_map<int, bool> a;

int main() {
  INCANT;
  cin >> n >> m;
  int b;
  rep(i, m) {
    cin >> b;
    a[b] = true;
  }
  ans[0] = 1ll;
  rep(i, n+1) {
    if (a[i]) continue;
    ans[i]%=MOD;
    if (!a[i+1]) ans[i+1]+=ans[i];
    if (!a[i+2]) ans[i+2]+=ans[i];
  }

  cout << ans[n] << endl;
  
  return 0;
}