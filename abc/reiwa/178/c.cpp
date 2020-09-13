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
int N;

ll calc(ll d) {
  ll ret=1ll;
  rep(i, N) {
    ret*=d;
    ret%=MOD;
  }
  return ret;
}

int main() {
  INCANT;
  cin >> N;
  // 全事象-(0が全く存在しない)-(9が全く存在しない)+(0と9が存在しない)
  ll ans = calc(10)-2*calc(9)+calc(8);
  while(ans<0) ans+=MOD;
  cout << ans << endl;
  return 0;
}