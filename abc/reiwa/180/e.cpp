using namespace std;
#include <iostream>
#include <cstring>
#define rep(i, n) for (int i=0; i<n; i++)
int n;
const int INF=2e9;
struct city{int x,y,z;};
city C[20];
int dp[1<<17][17]; // すでに訪れた、現在

int rec(int S, int v) {
  if (dp[S][v]>=0) return dp[S][v];
  if (S == (1<<n)-1 && v==0) {
    return dp[S][v] = 0; // 全ての頂点を訪れて戻ってきた 
  }
  int res = INF;
  rep(u,n) {
    if (!(S >> u & 1)) { // 次にuに移動する
      res = min(res, rec(S | 1 << u, u)+abs(C[u].x-C[v].x)+abs(C[u].y-C[v].y)+max(0, C[u].z-C[v].z));
    }
  }
  return dp[S][v] = res;
}

int main() {
  cin >> n;
  int x,y,z;
  rep(i, n) {
    cin >> x >> y >> z;
    city c ={x,y,z};
    C[i] = c;
  }
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0) << endl;
  return 0;
}