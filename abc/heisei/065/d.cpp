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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
typedef pair<ll, int> P;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
struct edge {int u, v; ll cost;};
int par[100005]; //親
int tree_rank[100005]; //木の深さ
int N, M;
ll T, A[100005];
edge es[200005];

void init_union_find(int n){
  rep(i, n){
    par[i] = i;
    tree_rank[i] = 0;
  }
}

bool comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}

// 木の根を求める
int find(int x){
  if (par[x] == x) return x;
  else return par[x] = find(par[x]);
}

// xとyの属する集合を併合
void unite(int x, int y){
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (tree_rank[x] < tree_rank[y]) par[x] = y;
  else{
    par[y] = x;
    if (tree_rank[x] == tree_rank[y]) tree_rank[x]++;
  }
}

// xとyが同じ要素に属するかどうか
bool same(int x, int y){
  return find(x) == find(y);
}

ll kruskal() {
  sort(es, es+2*N-2, comp);
  init_union_find(N);
  ll res = 0ll;
  rep(i, 2*N-2){
    edge e = es[i];
    if (!same(e.u, e.v)) {
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  ll x, y;
  vector<P> X, Y;
  rep(i, N) {
    cin >> x >> y;
    P px = make_pair(x, i);
    P py = make_pair(y, i);
    X.push_back(px);
    Y.push_back(py);
  }
  sort(ALL(X));
  sort(ALL(Y));
  rep(i, N-1) {
    edge e = { X[i].second, X[i+1].second, X[i+1].first - X[i].first };
    es[i] = e;
  }
  rep(i, N-1) {
    edge e = { Y[i].second, Y[i+1].second, Y[i+1].first - Y[i].first };
    es[i+N-1] = e;
  }

  ll ans = kruskal();
  cout << ans << "\n";
  return 0;
}