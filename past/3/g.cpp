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
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const int INF = 2e9;
int N,X,Y;
int dx[6] = {1,0,-1,1,-1,0}, dy[6] = {1,1,1,0,0,-1};
int dp[410][410];
bool obj[410][410];
struct edge{ int x,y,cnt;};

void dfs() {
  queue<edge> que;
  que.push({201,201,0});
  rep(i, 410) rep(j, 410) dp[i][j] = INF;
  while(!que.empty()) {
    edge e = que.front(); que.pop();
    if (dp[e.x][e.y]<=e.cnt) continue;
    dp[e.x][e.y] = e.cnt;
    rep(i, 6) {
      int nx = e.x+dx[i];
      int ny = e.y+dy[i];
      if (nx<0 || nx>409 || ny<0 || ny>409) continue;
      if (obj[nx][ny]) continue;
      if (dp[nx][ny]<=e.cnt) continue;
      que.push({nx,ny, e.cnt+1});
    }
  }
}

int main() {
  INCANT;
  cin >> N >> X >> Y;
  X+=201;Y+=201;
  int x,y;
  rep(i, N) {
    cin >> x >> y;
    obj[x+201][y+201] = true;
  }
  dfs();
  if (dp[X][Y]==INF) {
    cout << -1 << "\n";
    return 0;
  }
  cout << dp[X][Y] << "\n";
  return 0;
}