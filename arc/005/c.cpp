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
#include <tuple>
#include <stack>
#include <set>
#include <map>
#include <limits>
using namespace std;
const int INF = 1000000000;
#define rep(i,n) for (int i=0; i<n;++i)
typedef pair<pair<int, int>, int> P; 
int H, W, sh, sw, gh, gw;
bool C[501][501];
bool used[501][501][3];
int dh[4] = {1, 0, -1, 0}, dw[4] = {0, 1, 0, -1};


void bfs(){
  queue<pair<pair<int, int>, int> > que; //座標と壁を壊した回数
  que.push(P(make_pair(sh, sw), 0));
  while(!que.empty()){
    P p = que.front(); que.pop();
    int ph = p.first.first, pw = p.first.second, pt = p.second;
    if ((ph == gh) && (pw == gw)) break;
    rep(i, 4){
      int nh = ph + dh[i], nw = pw + dw[i];
      if ((nh<0) || (nh>=H) || (nw<0) || (nw>=W)) continue;
      if (used[nh][nw][pt]) continue;
      if (!C[nh][nw]){
        if(pt == 2) continue;
        used[nh][nw][pt+1] = true;
        que.push(P(make_pair(nh, nw), pt+1));
      }else{
        used[nh][nw][pt] = true;
        que.push(P(make_pair(nh, nw), pt));
      }
    }
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> W;
  char c;
  rep(i, H){
    rep (j, W){
      cin >> c;
      if (c == '#'){
        C[i][j] = false;
        continue;
      }
      if (c == 's') sh = i, sw =j;
      if (c == 'g') gh = i, gw = j;
      C[i][j] = true;
    }
  }
  bfs();
  rep(i, 3){
    if (used[gh][gw][i]){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}