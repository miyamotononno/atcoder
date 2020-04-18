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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int x,y;
string W;
char c[15][15];
// 9*9の他に上下左右ともに3行ずつ足す
// (0,0)は(3,3)になる。

// (0,1,2)←(6,5,4), (12,13,14)←(8,9,10)
void init() {
  rep(i, 3) rep(j, 15) c[i][j] = c[6-i][j];
  rep(i, 3) rep(j, 15) c[i+12][j] = c[10-i][j];
  rep(j, 3) rep(i, 15) c[i][j] = c[i][6-j];
  rep(j, 3) rep(i, 15) c[i][j+12] = c[i][10-j];  
}
int main() {
  INCANT;
  cin >> x >> y >> W;
  x--;y--;
  rep(i, 9) rep(j, 9) cin >> c[i+3][j+3];
  init();
  if (W[0]=='R') {
    if (W.size()==1) {
      rep(i,4) cout << c[y+3][x+3+i];
    } else {
      if (W[1]=='U') {
        rep(i,4) cout << c[y+3-i][x+3+i];
      } else {
        rep(i,4) cout << c[y+3+i][x+3+i];
      }
    }
  } else if (W[0]=='L'){
    if (W.size()==1) {
      rep(i,4) cout << c[y+3][x+3-i];
    } else {
      if (W[1]=='U') {
        rep(i,4) cout << c[y+3-i][x+3-i];
      } else {
        rep(i,4) cout << c[y+3+i][x+3-i];
      }
    }
  } else if (W[0]=='U') rep(i,4) cout << c[y+3-i][x+3];
  else rep(i,4) cout << c[y+3+i][x+3];
  cout << endl;
  return 0;
}