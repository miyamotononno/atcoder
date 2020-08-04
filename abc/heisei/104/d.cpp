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
string S;
int N;
ll dp[100005][4]; // idx番目でA,AB,ABCの数
ll H[100005];

ll dfs(int idx, int status) {
  if (idx==-1) return status?0ll:1ll;
  if (status==0) return H[idx];
  if (dp[idx][status]>=0) return dp[idx][status];
  char c = S[idx];
  ll res = 0ll;
  if (c=='C' || c=='?') {
    res += dfs(idx-1, status); // このCは選ばない
    if (status==3) res += dfs(idx-1, 2);
  }
  if (c=='B' || c=='?') {
    res += dfs(idx-1, status);
    if (status==2) res += dfs(idx-1, 1);
  }
  if (c=='A' || c=='?') {
    res += dfs(idx-1, status);
    if (status==1) res += dfs(idx-1, 0);
  }
  res%=MOD;
  dp[idx][status] = res;
  return res;
}

int main() {
  INCANT;
  cin >> S;
  N = S.size();
  ll tmp = 1ll;
  rep(i, N) {
    if (S[i]=='?') {
      tmp*=3ll;
      tmp%=MOD;
      H[i] = tmp;
    } else H[i] = tmp;
  }
  rep(i, N) rep(j, 4) dp[i][j] = -1;
  ll res = dfs(N-1, 3);
  cout << res << "\n";
  return 0;
}
