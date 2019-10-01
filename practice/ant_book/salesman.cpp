#include <algorithm>
#include <iostream>
#include <cstring>
#include <iomanip>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
const int INF = 1000000007;
const int MAX_N = 15;

int n;
int d[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N]; // 現在vにいる状態から残りの頂点をめぐって頂点0に変えるようなパスの重みの総和の最小値をdp[S][v]と表す
// dp[V][0]

// P173
// bitDPを用いる。計算時間はO(2^n, n^2)

// すでに訪れた頂点が集合S(スタート地点0はまだ訪れていないものとする), 現在地がv
int rec(int S, int v){
  if (dp[S][v] >= 0) return dp[S][v];

  if (S == (1 << n) - 1 && v ==  0){
    // 全ての頂点を訪れて戻ってきた
    return dp[S][v] = 0;
  }

  int res = INF;
  rep(u, n){
    if (!(S >> u & 1)){
      // 次にuに移動する
      res = min(res, rec(S | 1 << u, u) + d[v][u]);
    }
  }
  return dp[S][v] = res;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0) << endl;
}