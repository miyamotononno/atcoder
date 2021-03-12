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
int n,m,x,y;
struct edge{int to; ll cost, begin;};
vector<edge> G[100005];
ll costs[100005];
typedef pair<int, ll> P; // 都市, その時点でのコスト

void bfs() {
  queue<P> que;
  que.push(P(x, 0));
  while(!que.empty()) {
    P p = que.front(); que.pop();
    int c = p.first;
    ll cost = p.second;
    if (costs[c]>=0 && costs[c]<cost) continue;
    costs[c] = cost;
    for (auto e: G[c]) {
      int ne = e.to;
      ll wait_time = (e.begin-cost%e.begin)%e.begin;
      ll next_cost = cost+wait_time+e.cost;
      if (costs[ne]<0 || costs[ne]>next_cost) {
        que.push(P(ne, next_cost));
        costs[ne] = next_cost;
      }
    }
  }
}

int main() {
  INCANT;
  cin >> n >> m >> x >> y;
  x--;y--;
  int a,b;
  ll t,k;
  rep(i, m) {
    cin >> a >> b >> t >> k;
    a--;b--;
    edge e1 = {b,t,k};
    edge e2 = {a,t,k};
    G[a].push_back(e1);
    G[b].push_back(e2);
  }
  rep(i, n) costs[i]=-1;
  bfs();
  cout << costs[y] << "\n";
  return 0;
}