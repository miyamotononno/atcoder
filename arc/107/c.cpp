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
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 998244353;
int n, k;
int A[52][52];
ll Fac[52];

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

void init() {
  Fac[0] = 1ll;
  for (int i=1; i<=n; i++) {
    Fac[i] = Fac[i-1]*i;
    Fac[i]%=MOD;
  }
}

ll solve() {
  UnionFind uf(n);
  rep(i, n) {
    for (int j=i+1;j<n; j++) {
      bool ok = true;
      rep(c, n) {
        if (A[i][c]+A[j][c]>k) {
          ok = false;
          break;
        }
      }
      if (ok) uf.unite(i, j);
    }
  }
  ll ret = 1ll;
  rep(i, n) {
    int p = uf.root(i);
    if (i==p) {
      ret*=Fac[uf.size(i)];
      ret%=MOD;
    }
  }
  return ret;
}


int main() {
  INCANT;
  cin >> n >> k;
  init();
  rep(i, n) rep(j, n) cin >> A[i][j];
  ll row = solve();
  rep(i, n) {
    for (int j=i+1;j<n; j++) {
      swap(A[i][j], A[j][i]);
    }
  }
  ll col = solve();
  cout << row*col%MOD << endl;

  return 0;
}