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
int n, q;
typedef pair<int, int> P; // 頂点、つながってる辺
typedef pair<int, ll> P2;
vector<P> Tree[200005];
struct edge{int a,b; bool par;}; // par=trueでaが親側
edge E[200005];
vector<int> G[200005];
ll Memo[200005];
ll Ans[200005];

void init_tree() {
  bool seen[200005]={false};
  queue<int> que;
  que.push(0); // 親
  while(!que.empty()) {
    int a = que.front(); que.pop();
    seen[a] = true;
    for (auto nq: Tree[a]) {
      int b = nq.first;
      if (!seen[b]) {
        G[a].push_back(b);
        int e = nq.second;
        if (E[e].a == a) E[e].par = true; // aが親に近いということ
        que.push(b);
      }
    }
  }
}

int main() {
  INCANT;
  cin >> n;
  int a, b;
  rep(i, n-1) {
    cin >> a >> b;
    a--;b--;
    edge e = {a, b, false};
    E[i] = e;
    Tree[a].push_back(P(b, i));
    Tree[b].push_back(P(a, i));
  }
  init_tree();
  cin >> q;
  int t, e;
  ll x;
  rep(i, q) {
    cin >> t >> e >> x;
    e--;
    if (t==1) {
      if (E[e].par) {
        Memo[0]+=x;
        Memo[E[e].b] -= x;
      } else {
        Memo[E[e].a] += x;
      }
    } else {
      if (E[e].par) {
        Memo[E[e].b] += x;
      } else {
        Memo[0]+=x;
        Memo[E[e].a] -= x;
      }
    }
  }
  queue<P2> que2;
  que2.push(P2(0, 0ll)); // 頂点, 合計
  while(!que2.empty()) {
    P2 q = que2.front(); que2.pop();
    Ans[q.first]=Memo[q.first]+q.second;
    for (auto c: G[q.first]) {
      que2.push(P2(c, Ans[q.first]));
    }
  }
  rep(i, n) {
    cout << Ans[i] << endl;
  }

  return 0;
}