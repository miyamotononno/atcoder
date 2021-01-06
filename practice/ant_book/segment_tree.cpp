using namespace std;
#include <iostream>
#include <algorithm>
// #include <cassert>
#include <vector>

// 実装では1-indexedの配列で実現されている。
template<class S, S (*op)(S, S), S (*e)()> struct segTree {
  private:
    int _n, sz, lg;
    vector<S> d;
    void update(int k) { d[k] = op(d[2*k], d[2*k+1]); }
    // @param n `0 <= n`
    // @return minimum non-negative `x` s.t. `n <= 2**x`
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
  
  public:
    segTree(): segTree(0) {}
    segTree(int n): segTree(vector<S>(n, e())) {}
    segTree(const vector<S>& v): _n(int(v.size())) {
      lg = ceil_pow2(_n);
      sz = 1 << lg;
      d = vector<S>(2 * sz, e());
      for (int i=0; i<_n; i++) d[sz+i]=v[i];
      for (int i=sz-1; i>=1; i--) update(i);
    }

    void set(int p, S x) {
      // assert(0<=p && p < _n);
      p += sz;
      d[p] = x;
      for (int i=1; i<=lg; i++) update(p>>i);
    }

    S get (int p) {
      // assert(0<=p && p < _n);
      return d[p+sz];
    }

    S prod(int l, int r) {
      // assert(0 <= l && l <= r && r <= _n);
      S sml = e(), smr = e();
      l+=sz;r+=sz;

      while(l<r) {
        if (l & 1) sml = op(sml, d[l++]); // 
        if (r & 1) smr = op(d[--r], smr);
        l >>= 1;
        r >>= 1;
      }

      return op(sml, smr);
    }

    S all_prod() {return d[1];}
};

int main() {
  int l = 100;
  while(l>0) {
    cout << l << ' ' << (l&1) << "\n";
    l>>=1; 
  }
}
