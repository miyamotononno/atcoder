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
#include <deque>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const int INF = 2e9;
int H, W;
int ch, cw, gh, gw;
char S[1002][1002];
int seen[1002][1002];
typedef pair<int, int> P;
queue<P> que;
int dh[4] = {1,0,-1,0}, dw[4] = {0, 1, 0, -1};

int bfs() {
  rep(i, H) rep(j, W) seen[i][j] = INF;
  que.push(P(ch,cw));
  queue<P> cur_oper;
  int cnt=0;
  while(!que.empty()) {
    while(!que.empty()) {
      P p = que.front(); que.pop();
      cur_oper.push(p);
      int h = p.first;
      int w = p.second;
      if (seen[h][w]<=cnt) continue;
      if (h==gh && w==gw) return cnt;
      seen[h][w] = cnt;
      rep(i, 4) {
        int nh = h+dh[i];
        int nw = w+dw[i];
        if ((nh<0) || (nh>=H) || (nw<0) || (nw>=W)) continue;
        if (S[nh][nw]=='#') continue;
        if (seen[nh][nw]<=cnt) continue;
        que.push(P(nh,nw));
      }
    }
    cnt++;
    while(!cur_oper.empty()) {
      P p = cur_oper.front(); cur_oper.pop();
      int h = p.first;
      int w = p.second;
      for (int ih=-2; ih<=2; ih++) {
        for (int iw=-2; iw<=2; iw++) {
          int nh = h+ih;
          int nw = w+iw;
          if ((nh<0) || (nh>=H) || (nw<0) || (nw>=W)) continue;
          if (S[nh][nw]=='#') continue;
          if (seen[nh][nw]<=cnt) continue;
          que.push(P(nh,nw));
        }
      }
    }
  }
  return -1;
}

int main() {
  INCANT;
  cin >> H >> W;
  cin >> ch >> cw >> gh >> gw;
  ch--; cw--; gh--; gw--;
  rep(i, H) rep(j, W) cin >> S[i][j];
  cout << bfs() << endl;
  return 0;
}
