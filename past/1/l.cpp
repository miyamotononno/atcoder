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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(10);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
int n, m;
const double INF = 1.7e+20;
struct Tower{double x,y; int c;};
struct edge{int i,j; double c;};
Tower B[40];
double S[5][31];
vector<edge> G;

bool comp(const edge& e1, const edge& e2){
  return e1.c < e2.c;
}

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

edge get_edge(int t1, int t2) {
  double weight, _x, _y;
  weight = B[t1].c == B[t2].c?1.0:10.0;
  _x = pow(B[t1].x - B[t2].x, 2);
  _y = pow(B[t1].y - B[t2].y, 2);
  edge e = {t1, t2, sqrt(_x+_y)*weight};
  return e;
}

void input() {
  cin >> n >> m;
  double x,y; int c;
  rep(i, n) {
    cin >> x >> y >> c;
    Tower t = {x,y,c};
    B[i] = t;
  }
  rep(i, m) {
    cin >> x >> y >> c;
    Tower t = {x,y,c};
    B[n+i] = t;
  } 
}

int main() {
  INCANT;
  input();
  rep(i, n-1) {
    for (int j=i+1; j<n; j++) {
      G.push_back(get_edge(i, j));
    }
  }
  double ans = INF;
  rep(i, 1<<m) {
    vector<edge> V;
    for (auto g: G) V.push_back(g);
    vector<int> curSmall;
    rep(bit, m) {
      if (1<<bit & i) {
        rep(j, n) V.push_back(get_edge(j, n+bit));
        curSmall.push_back(n+bit);
      }
    }
    if (curSmall.size()>=2) {
      rep(j, curSmall.size()-1) {
        for (int k=j+1; k<curSmall.size(); k++) {
          V.push_back(get_edge(curSmall[j], curSmall[k]));
        }
      }
    }
    sort(ALL(V), comp);
    UnionFind uf(n+m);
    double curCost = 0.0;
    for (auto e: V) {
      if (!uf.issame(e.i, e.j)) {
        uf.unite(e.i, e.j);
        curCost+=e.c;
      }
    }
    ans = min(ans, curCost);
  }

  cout << ans << "\n";
  return 0;
}