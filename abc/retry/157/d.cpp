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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n, m, k;
int F[100005];
vector<int> B[100005];

// friend suggestions = FofF - friends - block in FofF - the oneself


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

int main() {
  INCANT;
  cin >> n >> m >> k;
  UnionFind uf(n);
  int a,b;
  rep(i, m) {
    cin >> a >> b;
    uf.unite(a-1,b-1);
    F[a-1]++;
    F[b-1]++;
  }
  rep(i, k) {
    cin >> a >> b;
    a--;b--;
    B[a].push_back(b);
    B[b].push_back(a);
  }

  rep(i, n) {
    int ans = uf.size(i)-F[i]-1;
    for (auto f: B[i]) {
      if (uf.issame(i, f)) ans--;
    }
    cout << ans << ' ';
  }
  cout << endl;

  return 0;
}