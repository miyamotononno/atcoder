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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
typedef pair<ll,int> P;
P x[100005], y[100005];
struct edge {ll cost; int from,to;};
vector<edge> E;
int par[100005]; //親
int tree_rank[100005]; //木の深さ

bool comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}

void init_union_find(int n){
  rep(i, n){
    par[i] = i;
    tree_rank[i] = 0;
  }
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
  sort(ALL(E), comp);
  init_union_find(N);
  ll res = 0ll;
  for (auto e: E) {
    if (!same(e.from, e.to)) {
      unite(e.from, e.to);
      res += e.cost;
    }
  }
  return res;
}

int main() {
  INCANT;
  cin >> N;
  int a,b;
  rep(i, N) {
    cin >> a >> b;
    x[i] = P(a, i);
    y[i] = P(b, i);
  }
  sort(x, x+N);
  sort(y, y+N);
  rep(i, N-1) {
    edge e1 = {x[i+1].first-x[i].first, x[i].second, x[i+1].second}; 
    E.push_back(e1);
    edge e2 = {y[i+1].first-y[i].first, y[i].second, y[i+1].second}; 
    E.push_back(e2);
  }
  ll ret = kruskal();
  cout << ret << endl;
  return 0;
}