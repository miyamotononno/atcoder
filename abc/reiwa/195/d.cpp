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
int n, m, q;
int W[51], V[51], X[51];
int Q[51][2];
typedef pair<int, int> P;

// 価値が最大のものから、その重さ以上の最小の箱に詰めてく
// PQ & にぶたん

int findMaximuim(int lft, int rgt, priority_queue<P> pque) {
  multiset<int> weights;
  rep(i, lft) weights.insert(X[i]);
  for (int i=rgt+1; i<m; i++) weights.insert(X[i]);
  int ret = 0;
  while(!pque.empty()) {
    P p = pque.top(); pque.pop();
    auto itr = weights.lower_bound(p.second);
    if (itr != weights.end()) {
      ret += p.first;
      weights.erase(itr);
    }
  }
  return ret;
}


int main() {
  INCANT;
  cin >> n >> m >> q;
  rep(i, n) cin >> W[i] >> V[i];
  rep(i, m) cin >> X[i];
  rep(i, q) rep(j, 2) cin >> Q[i][j];

  rep(i, q) {
    priority_queue<P> pque;
    rep(j, n) pque.push(P(V[j], W[j]));
    int r = findMaximuim(Q[i][0]-1, Q[i][1]-1, pque);
    cout << r << endl;
  }

  return 0;
}