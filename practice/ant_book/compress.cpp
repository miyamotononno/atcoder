// 座標圧縮
using namespace std;
#include <vector>
#include <algorithm>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for (int i=0; i<n;++i)
/* compress
  X を座標圧縮して書き換える（副作用）
  返り値: ソート済みの値
  計算量: O(n log n)
*/
vector<int> compress(vector<int> &X) {
    vector<int> vals = X;
    sort(ALL(vals));
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(ALL(vals)), vals.end());
    rep(i, X.size()) {
      X[i] = lower_bound(ALL(vals), X[i]) - vals.begin();
    }
    return vals;
}

/* compress_2x
    (X1,Y1),(X2,Y2)という二点で表されるもの（長方形や直線など）について、行か列の片方（X1とX2 or Y1とY2）を座標圧縮する（副作用）
    返り値: ソートされ重複要素を除いた値
    計算量: O(n log n)
*/
vector<int> compress_2x(vector<int> &C1, vector<int> &C2) {
    vector<int> vals;
    int N = (int)C1.size();
    rep (i, N) {
      rep (d, 2) {  // その位置と、一つ隣を確保(隣を確保しないと空白が埋まってしまうことがある)
        int tc1 = C1[i] + d;
        int tc2 = C2[i] + d;
        vals.push_back(tc1);
        vals.push_back(tc2);
      }
    }
    sort(ALL(vals));
    vals.erase(unique(ALL(vals)), vals.end());
    rep (i, N) {
      C1[i] = lower_bound(ALL(vals), C1[i]) - vals.begin();
      C2[i] = lower_bound(ALL(vals), C2[i]) - vals.begin();
    }
    return vals;
}