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
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int h, w, n, m;
char Gh[1502][1502], Gw[1502][1502];
int D[500003][2]; // 電球の置かれている場所を行、列で記録
int dh[4] = {1,-1,0,0}, dw[4] = {0,0,1,-1};

void dfsh(int y, int x, int dir) {
  if (Gh[y][x]!='-') return;
  Gh[y][x] = 's';
  if (y+dh[dir]<0 || y+dh[dir]>=h) return;
  dfsh(y+dh[dir], x+dw[dir], dir);
}

void dfsw(int y, int x, int dir) {
  if (Gw[y][x]!='-') return;
  Gw[y][x] = 's';
  if (x+dw[dir]<0 || x+dw[dir]>=w) return;
  dfsw(y+dh[dir], x+dw[dir], dir);
}

int main() {
  INCANT;
  cin >> h >> w >> n >> m;
  int a,b;
  memset(Gh, '-', sizeof(Gh));
  memset(Gw, '-', sizeof(Gw));
  rep(i, n) {
    cin >> a >> b;
    a--;b--;
    D[i][0] = a;
    D[i][1] = b;
    Gh[a][b]='d';
    Gw[a][b]='d';
  }
  rep(i, m) {
    cin >> a >> b;
    a--;b--;
    Gh[a][b]='b';
    Gw[a][b]='b';
  }
  rep(i, n) {
    rep(j, 2) dfsh(D[i][0]+dh[j], D[i][1]+dw[j], j);
  }
  rep(i, n) {
    rep(j, 2) dfsw(D[i][0]+dh[j+2], D[i][1]+dw[j+2], j+2);
  }
  int cnt=0;
  rep(i, h) {
    rep(j, w) {
      cnt += (Gh[i][j]=='s' || Gh[i][j]=='d' || Gw[i][j]=='s' || Gw[i][j]=='d');
    }
  } 

  cout << cnt << endl;

  return 0;
}