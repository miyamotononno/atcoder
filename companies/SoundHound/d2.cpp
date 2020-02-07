#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
typedef pair<ll, int> P;
struct edge {int to; ll cost;};
const ll INF = 1e17;
int N, M, s,t;
vector<edge> Yen[100005], Snuuk[100005];
ll CostYen[100005], CostSnuuk[100005];

void dijkstra(int s_yen, int s_snuuk) {
  priority_queue<P, vector<P>, greater<P> >  que;
  fill(CostYen, CostYen +  N, INF);
  CostYen[s_yen] = 0ll;
  que.push(P(0ll, s_yen));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if (CostYen[v] < p.first) continue;
    for (int i = 0; i < Yen[v].size(); i++) {
      edge e = Yen[v][i];
      if (CostYen[e.to] > CostYen[v] + e.cost) {
        CostYen[e.to] = CostYen[v] + e.cost;
        que.push(P(CostYen[e.to], e.to));
      }
    }
  }

  fill(CostSnuuk, CostSnuuk +  N, INF);
  CostSnuuk[s_snuuk] = 0ll;
  que.push(P(0ll, s_snuuk));
  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if (CostSnuuk[v] < p.first) continue;
    for (int i = 0; i < Snuuk[v].size(); i++) {
      edge e = Snuuk[v][i];
      if (CostSnuuk[e.to] > CostSnuuk[v] + e.cost) {
        CostSnuuk[e.to] = CostSnuuk[v] + e.cost;
        que.push(P(CostSnuuk[e.to], e.to));
      }
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> s >> t;
  s--;t--;
  int u,v;
  ll a,b;
  rep(i, M) {
    cin >> u >> v >> a >> b;
    u--;v--;
    Yen[u].push_back({v,a});
    Yen[v].push_back({u,a});
    Snuuk[u].push_back({v,b});
    Snuuk[v].push_back({u,b});
  }

  dijkstra(s,t);
  vector<P> Cost;
  priority_queue<P, vector<P>, greater<P> >  que;
  rep(i, N) que.push(P(CostYen[i] + CostSnuuk[i], i));
  
  int year=0;
  while (year < N) {
    int ec = que.top().second;
    if (ec < year) {
      que.pop();
      continue;
    }
    ll cs = 1e15 - que.top().first;
    year++;
    cout << cs << "\n";
  }

  return 0;
}