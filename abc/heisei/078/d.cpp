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
const int INF = 2147483647;
int n;
int Z,W, a[2002];
int dp[2002][2]; // i枚目をxがとった時の値,直前にxが撮った時のindex, 今x,yのターン

int getPoint(int cur) {
  if (cur==0) return abs(a[n-1]-W);
  return abs(a[n-1]-a[cur-1]);
}

int dfs(int cur, bool flag) { // 現在の自分の位置
  if (dp[cur][flag]>=0) return dp[cur][flag];
  if (cur==n-1) { // 最後の一枚、絶対にとるしかない
    dp[cur][flag] = getPoint(cur);
    return getPoint(cur);
  }
  int ret;
  if (flag) {
    ret = 0;
    for (int i=cur+1; i<n;i++) { // 次のターンの一番上がi
      ret = max(ret, dfs(i, !flag));
    }
    ret = max(ret, getPoint(cur)); // 全部取る
  } else {
    ret = INF;
    for (int i=cur+1; i<n;i++) {
      ret = min(ret, dfs(i, !flag));
    }
    ret = min(ret, getPoint(cur));
  }
  dp[cur][flag] = ret;
  return ret;
}

int main() {
  INCANT;
  cin >> n >> Z >> W;
  rep(i, n) cin >> a[i];
  memset(dp, -1, sizeof(dp));
  int d = dfs(0, 1);
  cout << d << endl;
  return 0;
}