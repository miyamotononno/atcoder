#include <iostream>
#include <string>
#include <deque>
using namespace std;
int H,W;
const int INF = 2e9;
char S[1001][1001];
int dp[1001][1001][4]; // i, j の位置にある時の最小値
int dh[4] = {1,0,-1,0}, dw[4] = {0, 1, 0, -1};

struct node {
  int h;
  int w;
  int cnt;
  int dir;
};

int searchCalc(int& rs, int& cs, int& rt, int& ct) {
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      for (int k=0; k<4; k++) dp[i][j][k] = INF;
    }
  }
  // goalから逆算する
  deque<node> que;
  que.push_front(node{rs, cs, 0, -1});
  while(!que.empty()) {
    node cNode = que.front(); que.pop_front();
    int h = cNode.h;
    int w = cNode.w;
    int cnt = cNode.cnt;  
    int dir = cNode.dir;
    if (dir >= 0) {
      if (cnt >= dp[h][w][dir]) continue;
      dp[h][w][dir] = cnt;
    } else {
      for (int k=0; k<4; k++) dp[h][w][k] = 0; // 初回なので
    }
    if (h == rt && w == ct) continue;
    node nextNode;
    for (int ndir=0; ndir<4; ndir++) {
      if (dir == -1 || dir == ndir) { // そのまま進む
        int nh = h+dh[ndir];
        int nw = w+dw[ndir];
        if (nh<0 || nw<0 || nh>=H || nw>=W) continue;
        if (S[nh][nw]=='#') continue;
        nextNode = node{nh, nw, cnt, ndir};
        if (dp[nh][nw][ndir] <= cnt) continue;
        que.push_front(nextNode);
      } else { // 方向転換する
        if (dp[h][w][ndir] <= cnt+1) continue;
        nextNode = node{h, w, cnt+1, ndir};
        que.push_back(nextNode);
      }
    }
  }
  int ret = INF;
  for (int i=0; i<4; i++) {
    ret = min(ret, dp[rt][ct][i]);
  }
  return ret;
}

int main() {
  cin >> H >> W;
  int rs, cs, rt, ct;
  cin >> rs >> cs;
  cin >> rt >> ct;
  rs--;cs--;rt--;ct--;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> S[i][j];
    }
  }
  cout << searchCalc(rs, cs, rt, ct) << endl;
}