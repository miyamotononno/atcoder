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
int H, W;
typedef pair<int, int> P;
struct edge {int h,w,cnt;};
char A[2002][2002];
vector<P> Teleport[26];
int TelSeen[26];
int seen[2002][2002];
int sh, sw, gh, gw;
int dh[4] = {1,0,-1,0}, dw[4] = {0, 1, 0, -1};

void bfs() {
  rep(i, 26) TelSeen[i] = -1;
  queue<edge> que;
  edge s = {sh,sw, 0};
  que.push(s);
  while(!que.empty()) {
    edge cur = que.front(); que.pop();
    if (seen[cur.h][cur.w]!=-1 && seen[cur.h][cur.w] <= cur.cnt) {
      continue;
    }
    seen[cur.h][cur.w] = cur.cnt;
    rep(i, 4) {
      int nh = cur.h+dh[i];
      int nw = cur.w+dw[i];
      if ((nh<0) || (nh>=H) || (nw<0) || (nw>=W)) continue;
      if (A[nh][nw]=='#') continue;
      if (seen[nh][nw]!=-1 && seen[nh][nw] <= cur.cnt+1) continue;
      edge n = {nh,nw, cur.cnt+1};
      que.push(n);
    }
    int a = A[cur.h][cur.w]-'a';
    if (a>=0 && a<26) {
      if (TelSeen[a]>=cur.cnt && TelSeen[a]!=-1) continue;
      for (auto p: Teleport[a]) {
        if (p.first == cur.h && p.second == cur.w) continue;
        if (seen[p.first][p.second]!=-1 && seen[p.first][p.second] <= cur.cnt+1) continue;
        edge n = {p.first,p.second, cur.cnt+1};
        que.push(n);
      }
      TelSeen[a] = cur.cnt+1; 
    }
  }
}

int main() {
  INCANT;
  cin >> H >> W;
  
  rep(i,H) {
    rep(j, W) {
      cin >> A[i][j]; 
      if (A[i][j]=='S') {
        sh = i;sw = j;
        continue;
      }
      if (A[i][j]=='G') {
        gh = i;gw = j;
        continue;
      }
      int a = A[i][j]-'a';
      if (a>=0 && a<26) {
        Teleport[a].push_back(P(i, j));
      }
    }
  }
  memset(seen, -1, sizeof(seen));
  bfs();

  cout << seen[gh][gw] << "\n";
  return 0;
}