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
typedef long long ll;
using namespace std;
const ll MOD = 1000000007;
int N;
ll K;
vector<int> T[100005];
bool Used[100005];

ll dfs(int n, int f){
  ll c;
  if (f == -1) c=K-1;
  else c = K-2;
  if (K < T[n].size()) return 0;
  ll cn = 1;
  for (auto e: T[n]){
    if (e == f) continue;
    cn *= c;
    c--;
    cn%=MOD;
  }
  for (auto e: T[n]){
    if (e == f) continue;
    cn *= dfs(e, n);
    cn %= MOD;
  }
  return cn;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  int a, b;
  rep(i, N-1){
    cin >> a >> b;
    a--, b--;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  ll ans = K*dfs(0, -1);
  ans %= MOD;
  cout << ans << endl;
  return 0;
}