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
typedef pair<int, ll> P;
P A[200002];
vector<ll> D[200002];
ll dp[200002][2]; // i番目に->　or <-の方向で動いた時の最小
vector<P> E;

ll dfs(int idx, bool prePos) { // 0ならfirst, 1でsecond
  if (dp[idx][prePos]>0) return dp[idx][prePos];
  if (idx==0) return 0; // 原点
  ll curPos = prePos?E[idx].second:E[idx].first;
  ll dist = E[idx].second-E[idx].first;
  ll ret = dfs(idx-1, false) + dist+ abs(E[idx-1].second-curPos);
  ret = min(ret, dfs(idx-1, true) + dist + abs(E[idx-1].first-curPos));
  dp[idx][prePos] = ret;
  return ret;
}

int main() {
  INCANT;
  cin >> n;
  ll x;
  int c;
  rep(i, n) {
    cin >> x >> c;
    A[i] = P(c, x);
  }
  sort(A, A+n);
  rep(i, n) {
    int color = A[i].first;
    ll d = A[i].second;
    D[color].push_back(d);
  }
  D[0].push_back(0);
  D[n+1].push_back(0);
  
  rep(i, n+2) {
    if (D[i].size()==0) continue;
    if (D[i].size()==1) E.push_back(P(D[i][0], D[i][0]));
    else E.push_back(P(D[i][0], D[i][D[i].size()-1]));
  }


  cout << dfs(E.size()-1, 0) << "\n";
  return 0;
}