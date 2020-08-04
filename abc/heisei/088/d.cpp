#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const int INF = 1000000007;
int H, W;
char S[52][52];
int MinCnt[52][52];
typedef pair<int, int> P; // 座標と最短到達マス
queue<P> que;
int dh[4] = {1,0,-1,0}, dw[4] = {0, 1, 0, -1};

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> W;
  int b_cnt = 0;
  rep(i, H){
    rep(j, W){
      cin >> S[i][j];
      MinCnt[i][j] = INF;
      if (S[i][j] == '#') b_cnt++;
    }
  }
  MinCnt[0][0] = 0;
  que.push(P(0, 0));
  while(!que.empty()){
    P p = que.front(); que.pop();
    int ph = p.first, pw = p.second;
    if (ph == H-1 && pw == W-1) continue;
    
    rep(i, 4){
      int nh = ph + dh[i], nw = pw + dw[i];
      if ((nh<0) || (nh>=H) || (nw<0) || (nw>=W)) continue;
      if (S[nh][nw]=='#') continue;
      if (MinCnt[nh][nw] <= MinCnt[ph][pw] + 1) continue;
      P nxt = make_pair(nh, nw);
      MinCnt[nh][nw] = MinCnt[ph][pw] + 1;
      que.push(nxt);
    }
  }

  int goalCnt = MinCnt[H-1][W-1];
  if (goalCnt == INF) {
    cout << -1 << "\n";
    return 0;
  }

  cout << H*W-goalCnt-b_cnt-1 << "\n";
  return 0;
}