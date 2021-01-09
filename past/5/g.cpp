#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#include <stack>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int H,W;
char S[5][5];
bool dp[5][5];
int dh[4] = {1,0,-1,0}, dw[4] = {0,1,0,-1};
int k;
struct node{int h, w;};
int sh,sw;

bool dfs(stack<node> st, int dir, bool init) {
  int ch, cw;
  if (init) {
    ch = sh;
    cw = sw;
  } else {
    node pre = st.top();
    ch = pre.h+dh[dir];
    cw = pre.w+dw[dir];
  }
  dp[ch][cw] = true;
  node c = {ch, cw};
  st.push(c);
  if (st.size()==k) {
    while (!st.empty()) {
      cout << st.top().h+1 << ' ' << st.top().w+1 << endl;
      st.pop();
    }
    return true;
  }
  bool flag = false;
  int nh,nw;
  rep(i, 4) {
    if (!init && (dir+2)%4==i) continue;
    nh = ch+dh[i];
    nw = cw+dw[i];
    if ((nh<0) || (nh>=H) || (nw<0) || (nw>=W)) continue;
    if (S[nh][nw]=='.') continue;
    if (dp[nh][nw]) continue;
    if (dfs(st, i, false)) return true;
  }
  dp[ch][cw] = false;
  return false;
}

int main() {
  INCANT;
  cin >> H >> W;
  k = 0;
  rep(i, H) rep(j, W) {
    cin >> S[i][j];
    if (S[i][j]=='#') k++;
  }
  cout << k << endl;
  bool ok = false;
  rep(i, H) {
    rep(j, W) {
      if (S[i][j]=='#') {
        memset(dp, false, sizeof(dp));
        stack<node> st;
        sh =i; sw = j; 
        if (dfs(st, 0, true)) {
          ok = true;
          break;
        }
      }
    }
    if (ok) break;
  }

  
  return 0;
}