using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
int H, W;
char S[401][401];
struct node {int h,w;};
int dh[4] = {1,0,-1,0}, dw[4]={0,1,0,-1};
bool serched[401][401];

ll bfs(int h, int w) {
  queue<node> que;
  ll black=0;
  ll white=0; 
  que.push(node{h,w});
  while(!que.empty()) {
    node no = que.front(); que.pop();
    if (serched[no.h][no.w]) continue;
    if (S[no.h][no.w]=='#') black++;
    if (S[no.h][no.w]=='.') white++;
    serched[no.h][no.w] =true;
    rep(i, 4) {
      int nh = no.h+dh[i];
      int nw = no.w+dw[i];
      if (nh < 0 || nh > H || nw<0 || nw>W) continue;
      if (S[nh][nw]==S[no.h][no.w] || serched[nh][nw]) continue;
      que.push(node{nh,nw});
    }
  }
  return black * white;
}

int main() {
  cin >> H >> W;
  rep(i, H) rep(j, W) cin >> S[i][j];

  ll sm=0ll;
  rep(i, H) {
    rep(j, W) {
      if (!serched[i][j]) {
        sm+=bfs(i,j);
      }
    }
  }
  cout << sm << endl;
}
