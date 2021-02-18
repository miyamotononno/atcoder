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
int N;
string S[62];

ll dfs(int idx) {
  if (idx==-1) {
    return 1ll;
  }
  ll ans = 0ll;
  if (S[idx]=="OR") {
    ll d = 1ll<<(idx+1ll);
    ans+=d;
  }
  ans+=dfs(idx-1);
  return ans;
}

int main() {
  INCANT;
  cin >> N;
  int cnt = 1;
  rep(i, N) {
    cin >> S[i];
  }
  ll ans = dfs(N-1);

  cout << ans << endl;

  return 0;
}