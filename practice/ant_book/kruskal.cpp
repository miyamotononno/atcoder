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
edge es[200005];
int V, E; //頂点数と変数

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

bool comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}

int kruskal() {
  sort(es, es+V, comp);
  UnionFind uf(V);
  int res = 0;
  rep(i, E){
    edge e = es[i];
    if (!uf.issame(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}