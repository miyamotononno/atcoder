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
const int INF = 2e9;
int H, W;
int A[51][51];
struct edge{int h,w,cost;};
int dh[4] = {1,0,-1,0}, dw[4] = {0,1,0,-1};
int dp1[51][51],dp2[51][51],dp3[51][51];

void bfs(int sh, int sw, int dp[51][51]) {
  rep(i, H) rep(j, W) dp[i][j]=INF;
  queue<edge> que;
  edge e = {sh,sw,0};
  que.push(e);
  while(!que.empty()) {
    edge e = que.front(); que.pop();
    int newCost = e.cost+A[e.h][e.w];
    if (dp[e.h][e.w]>newCost) {
      dp[e.h][e.w] = newCost;
      rep(i, 4) {
        int nh = e.h+dh[i];
        int nw = e.w+dw[i];
        if (nh<0 || nh>=H || nw<0 || nw >= W) continue;
        if (newCost+A[nh][nw]<dp[nh][nw]) {
          edge ne = {nh,nw,newCost};
          que.push(ne);
        } 
      }
    }
  }
}

int main() {
  INCANT;
  cin >> H >> W;
  rep(i, H) rep(j, W) cin >> A[i][j];
  bfs(H-1,0,dp1);
  bfs(H-1,W-1,dp2);
  bfs(0,W-1,dp3);
  int MIN=INF;
  rep(i, H) rep(j, W) MIN = min(MIN, dp1[i][j]+dp2[i][j]+dp3[i][j]-2*A[i][j]);
  cout << MIN << endl;
  return 0;
}