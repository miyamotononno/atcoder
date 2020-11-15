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
#include <deque>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
int n, m;
typedef pair<int, int> P;
char S[12][12];
bool seen[12][12];
int dx[4] = {1,0,-1,0}, dy[4] = {0, 1, 0, -1};

int bfs(int sy, int sx) {
  memset(seen, false, sizeof(seen));
  queue<P> que;
  que.push(P(sx,sy));
  while(!que.empty()) {
    P p = que.front(); que.pop();
    int x = p.first;
    int y = p.second;
    rep(i, 4) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
      if (S[ny][nx]=='#') continue; 
      if (seen[ny][nx]) continue;
      que.push(P(nx,ny));
      seen[ny][nx] = true;
    }
  }
  rep(i, n) {
    rep(j, m) {
      if (S[i][j]=='.' && !seen[i][j]) return 0;
    }
  }
  return 1;
}

int main() {
  INCANT;
  cin >> n >> m;
  rep(i, n) rep(j, m) cin >> S[i][j];
  
  int ret = 0;
  rep(i, n) {
    rep(j, m) {
      if (S[i][j]=='#') {
        ret += bfs(i, j);
      }
    }
  }
  cout << ret << endl;
  
  return 0;
}