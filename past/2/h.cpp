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
const int INF = 2e9;
int H,W;
char C[52][52];
typedef pair<int, int> P;
vector<P> d[11]; // S, 1...9, G, h,w
int dp[52][52];

int dfs(int idx, P now) {
  if (idx==10) return 0;
  if  (dp[now.first][now.second]>0) return dp[now.first][now.second];
  int MIN = INF;
  for (auto p: d[idx+1]) {
    int h = p.first;
    int w = p.second;
    MIN = min(MIN, dfs(idx+1, P(h,w))+abs(h-now.first)+abs(w-now.second));
  }
  dp[now.first][now.second] = MIN;
  return MIN;
}

int main() {
  INCANT;
  cin >> H >> W;
  rep(i, H) rep(j, W) cin >> C[i][j];
  vector<int> vec;
  rep(i, H) {
    rep(j, W) {
      if (C[i][j]=='S') d[0].push_back(P(i,j));
      else if (C[i][j]=='G') d[10].push_back(P(i,j));
      else d[C[i][j] - '0'].push_back(P(i,j));
    }
  }
  for (auto p: d) {
    if (p.size()==0) {
      cout << -1 << endl;
      return 0;
    }
  }
  int ret = dfs(0, d[0][0]);
  cout << ret << "\n";
  return 0;
}