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
#include <stack>
#include <set>
#include <map>
#include <limits>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<n;++i)
struct edge {int u, v, cost;};

bool comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}

int N, E; //頂点数と変数
edge es[MAX_E];
int par[100005]; //親
int tree_rank[100005]; //木の深さ

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


int kruskal() {
  sort(es, es+N, comp);
  init_union_find(N);
  int res = 0;
  rep(i, E){
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
  vector<P> C(N);
  rep(i,N) cin >> C[i].first >> C[i].second;
  sort(C.begin(), C.end());
  

  return 0;
}