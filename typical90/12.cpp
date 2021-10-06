#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0; i<n;++i)
int H, W, Q;
int dh[4] = {1,0,-1,0}, dw[4] = {0, 1, 0, -1};
bool G[4000002];

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

    // uniteされるとは、追加したマスの上下左右に赤いマスがある  
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

int trans(int h, int w) {
  return h*W+w;
}

int main() {
  cin >> H >> W;
  cin >> Q;
  UnionFind uf(H*W);
  vector<string> ans;
  int t;
  rep(i, Q) {
    cin >> t;
    if (t==1) {
      int r, c;
      cin >> r >> c;
      r--;c--;
      int idx = trans(r,c);
      G[idx] = true;
      rep(j, 4) {
        int nr = r+dh[j];
        int nc = c+dw[j];
        if ((nr<0) || (nr>=H) || (nc<0) || (nc>=W)) continue;
        if (G[trans(nr, nc)]) {
          uf.unite(idx, trans(nr, nc));
        }
      }
    } else {
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      ra--;ca--;rb--;cb--;
      if (uf.issame(trans(ra, ca), trans(rb, cb)) && G[trans(ra, ca)] && G[trans(rb, cb)]) {
        ans.push_back("Yes");
      } else {
        ans.push_back("No");
      }
    }
  }
  for (auto s: ans) cout << s << endl;
}
