#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
typedef long long ll;
// sから各町行くまでの最小値
const ll INF = 2e18;
struct edge{int node; ll cost;};
vector<edge> G[100004];

vector<ll> dijkstra(int s) {
  vector<ll> ret(n, INF);
  queue<edge> que;
  edge se = edge{s, 0};
  que.push(se);
  while(!que.empty()) {
    edge e = que.front(); que.pop();
    if (ret[e.node]<=e.cost) continue;
    ret[e.node] = e.cost;
    for (edge nextEdge: G[e.node]) {
      int nextNode = nextEdge.node;
      ll cost = e.cost+nextEdge.cost;
      if (ret[nextNode]<= cost) continue;
      edge ne = edge{nextNode, cost};
      que.push(ne);
    }
  }
  return ret;
}

int main() {
  cin >> n >> m;
  int a, b;
  ll c;
  for (int i=0; i<m; i++) {
    cin >> a >> b >> c;
    a--;b--;
    edge e1 = edge{b, c};
    edge e2 = edge{a, c};
    G[a].push_back(e1);
    G[b].push_back(e2);
  }
  vector<ll> CostsFromStart = dijkstra(0);
  vector<ll> CostsFromGoal = dijkstra(n-1);
  for (int i=0; i<n; i++) {
    cout << CostsFromStart[i] + CostsFromGoal[i] << endl;
  }
}
