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
const ll INF = 1e18;
int N, M;
vector<int> D[11];
string S[1001];
ll C[1001];
ll dp[11][10240];

ll dfs(int b, int idx) {
  if (idx==N) return 0ll;
  if (dp[idx][b]>0) return dp[idx][b];
  ll ret=INF;
  if (b&(1 << idx)) ret = dfs(b, idx+1);
  else {
    if (D[idx].size()==0) return -INF;
    int _b = b;
    for (auto p: D[idx]) {
      for(int i=idx; i<N; i++) {
        int n_mask = 1<<i;
        if (S[p][i]=='Y' && !(b & n_mask)) _b += n_mask;
      }
      ll tmp = dfs(_b, idx+1)+C[p];
      ret= min(ret, tmp);
      _b = b;
    }
  }
  dp[idx][b]=ret;
  return ret;
}

int main() {
  INCANT;
  cin >> N >> M;
  string s;
  rep(i, M) { 
    cin >> s >> C[i];
    rep(j, N) {
      if (s[j]=='Y') D[j].push_back(i);
      S[i] = s;
    }
  }
  ll ret = dfs(0,0);
  if (ret<0) {
    cout << -1 << endl;
    return 0;
  }
  cout << dp[0][0] << endl;
  return 0;
}