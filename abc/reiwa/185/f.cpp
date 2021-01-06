using namespace std;
#include <iostream>
#include <vector>
#define rep(i, n) for(int i=0;i<n;i++)

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
      p += sz;
      d[p] = x;
      for (int i=1; i<=lg; i++) update(p>>i);
    }

    S get (int p) {
      return d[p+sz];
    }

    S prod(int l, int r) {
      S sml = e(), smr = e();
      l+=sz;r+=sz;

      while(l<r) {
        if (l & 1) sml = op(sml, d[l++]);
        if (r & 1) smr = op(d[--r], smr);
        l >>= 1;
        r >>= 1;
      }

      return op(sml, smr);
    }


    S all_prod() {return d[1];}
};

int op(int a, int b) {
  return a^b;
}

int e() {
  return 0;
}



int main() {
  int N,Q;
  cin >> N >> Q;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  segTree<int, op, e> seg(a);

  vector<int> ans;
  int t,x,y; 
  rep(i,Q) {
    cin >> t >> x >> y;
    x--;
    if (t==1) {
      int v = seg.get(x);
      v^=y;
      seg.set(x,v);
    } else {
      int d = seg.prod(x,y);
      ans.push_back(d);
    }
  }
  for (auto c: ans) {
    cout << c << endl;
  }
}
