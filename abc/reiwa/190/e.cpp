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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const int INF = 2e9;
int n, m, k;
int C[18];
vector<int> G[100005];
int G2[18][18];
typedef pair<int, int> P; //firstは最短距離、secondは頂点の番号
int dp[1 << 18][18]; // メモ化テーブル

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

vector<int> dijkstra(int s) {
  int d[100005];
  fill(d, d + n, INF);
  queue<P> que;
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()) {
    P p = que.front(); que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (auto ne: G[v]) {
      if (d[ne] > d[v]+1) {
        d[ne] = d[v]+1;
        que.push(P(d[ne], ne));
      }
    }
  }

  vector<int> costs;
  rep(i, k) costs.push_back(d[C[i]]);
  return costs;
}

int rec(int S, int v) {
  if (dp[S][v]>=0) return dp[S][v];
  if (S == (1<<k)-1) return dp[S][v] = 0; // 全ての頂点を訪れた
  int res = INF;
  rep(u,k) {
    if (!(S >> u & 1)) { // 次にuに移動する
      res = min(res, rec(S | 1 << u, u)+G2[v][u]);
    }
  }
  return dp[S][v] = res;
}

int main() {
  INCANT;
  cin >> n >> m;
  UnionFind uf(n);
  rep(i, m) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    uf.unite(a,b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cin >> k;
  rep(i, k) {
    cin >> C[i];
    C[i]--;
  }
  if (k==1) {
    cout << 1 << endl;
    return 0;
  }
  if (m==0) {
    cout << -1 << endl;
    return 0;
  }
  int root = uf.root(C[0]);
  rep(i, k) {
    if (root != uf.root(C[i])) {
      cout << -1 << endl;
      return 0;
    } 
  }
  rep(i, k) {
    vector<int> costs = dijkstra(C[i]);
    rep(j, k) {
      G2[i][j] = costs[j]; // j番目にC[j]のcost
      if (i==j) continue;
    }
  }
  // 始点をiとしたときの一周周るコスト
  int ans = INF;
  rep(i, k) {
    memset(dp, -1, sizeof(dp));
    ans = min(ans, rec(1<<i, i)+1);
  }

  cout << ans << endl;
  return 0;
}