using namespace std;
#include <iostream>
#include <cstring>
#define rep(i, n) for (int i=0; i<n; i++)
const int MAX_N = 16;
constexpr int INF = 2e9;
int n, d[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N]; // メモ化テーブル

// 巡回セールスマン問題
// すでに訪れた頂点がS,現在の位置がv

// 1周して戻ってくるとした場合
int rec(int S, int v) {
  if (dp[S][v]>=0) return dp[S][v];
  if (S == (1<<n)-1 && v==0) {
    return dp[S][v] = 0; // 全ての頂点を訪れて戻ってきた 
  }
  int res = INF;
  rep(u,n) {
    if (!(S >> u & 1)) { // 次にuに移動する
      res = min(res, rec(S | 1 << u, u)+d[v][u]);
    }
  }
  return dp[S][v] = res;
}

void tsp() {
  rep(i, n) fill(d[i], d[i]+n, INF);
  d[0][3] = 4;
  d[0][1] = 3;
  d[1][2] = 5;
  d[2][0] = 4;
  d[2][3] = 5;
  d[3][4] = 3;
  d[4][1] = 6;
  d[4][0] = 7;
  memset(dp, -1, sizeof(dp));
  cout << rec(0,0) << '\n';
}


int main() {
  cin >> n;
  tsp();
  return 0;
}