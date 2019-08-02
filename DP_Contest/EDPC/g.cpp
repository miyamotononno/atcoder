#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
int N, M;
vector<int> G[100005];
int DP[100005];

int dfs(int idx){
  if (DP[idx] > 0) return DP[idx];
  int ans = 0;
  rep(i, G[idx].size()){
    int n = G[idx][i];
    int nxt_dp = dfs(n) + 1;
    ans = max(ans, nxt_dp);
  }
  DP[idx] = ans;
  return ans;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int a, b;
  rep(i, M) {
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
  }

  int ans = 0;
  rep(i, N) {
    ans = max(ans, dfs(i));
  }

  cout << ans << endl;
  return 0;
}
