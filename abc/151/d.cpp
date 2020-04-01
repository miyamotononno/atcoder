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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int H, W;
char s[21][21];
int dp[21][21]; 
typedef pair<pair<int, int>, int> P; 
int dh[4] = {1, 0, -1, 0}, dw[4] = {0, 1, 0, -1};


// 計算量はO(HW)
int bfs(int sh, int sw) {
  rep(i, H) rep(j, W) dp[i][j]=-1;
  dp[sh][sw] = 0; 
  queue<P> que;
  que.push(P(make_pair(sh, sw), 0));
  int max_cnt = 0;
  while(!que.empty()) {
    P p = que.front(); que.pop();
    int h = p.first.first, w = p.first.second, cnt = p.second;
    rep(i, 4) {
      int nh = h +dh[i], nw = w+dw[i];
      if ((nh<0) || (nh>=H) || (nw<0) || (nw>=W)) continue;
      if (s[nh][nw] == '#') continue;
      if (dp[nh][nw] != -1) continue;
      int next_cnt = cnt+1; 
      que.push(P(make_pair(nh, nw), next_cnt));
      dp[nh][nw] = next_cnt;
      max_cnt = next_cnt;
    }
  }
  
  return max_cnt;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> W;
  int sh,sw;
  rep(i, H) {
    rep(j, W) {
      cin >> s[i][j];
      if (s[i][j]=='.') {
        sh = i;
        sw = j;
      } 
    }
  }
  int ans = -1;
  rep(i, H){
    rep(j, W) {
      if  (s[i][j]=='#') continue;
      int cnt = bfs(i, j);
      if (ans < cnt) ans = cnt;
    }
  }

  cout << ans << endl;
  return 0;
}