#include <bits/stdc++.h>
using namespace std;
int H, W;
typedef pair<int, int> P;
int dh[4] = {1,0,-1,0}, dw[4] = {0, 1, 0, -1};

int convertInt(const int& h, const int& w) {
  return h*W + w; 
}

int dfs(bool& canGo, int h, int w, int bits, const char c[], const int& sh, const int& sw) { //現在idxにいて、回った状況としてはbits
  if (h==sh && w == sw && bits>0) return 0;
  if (h!=sh || w != sw) bits += (1<<convertInt(h, w));
  int ret = -1;
  canGo = false;
  for (int i=0; i<4; i++) {
    int nh = h + dh[i];
    int nw = w + dw[i];
    if (nh < 0 || nh>=H || nw < 0 || nw >= W) continue;
    int d = convertInt(nh, nw);
    if (c[d]=='#') continue;
    if ((1<<d) & bits) continue;
    bool canNextGo = true;
    int r = dfs(canNextGo, nh, nw, bits, c, sh, sw);
    if (canNextGo) {
      canGo = true;
      ret = max(ret, r+1);
    }
  } 
  return ret;
}

int main() {
  cin >> H >> W;
  char c[H*W];
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> c[convertInt(i,j)];
    }
  }
  int ret = 0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      bool canGo = true;
      int r = dfs(canGo, i, j, 0, c, i, j);
      if (canGo) ret = max(ret, r);
    }
  }
  cout << (ret>2?ret:-1) << endl;
  
}

