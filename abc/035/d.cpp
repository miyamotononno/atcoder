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
#include <stack>
#include <set>
#include <map>
#include <limits>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<n;++i)
struct edge {int to; ll cost; };
const ll INF = numeric_limits<ll>::max();
typedef pair<ll, int> P; //firstは最短距離、secondは頂点の番号
 
int N, M;
vector<edge> G[100005], G2[100005];
ll d[100005], d2[100005], A[100005];

void dijkstra(int s) {
  // greater<P>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P> >  que;
  fill(d, d + N, INF);
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

void reverse_dijkstra(int s) {
  // greater<P>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P> >  que;
  fill(d2, d2 + N, INF);
  d2[s] = 0;
  que.push(P(0, s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if (d2[v] < p.first) continue;
    for (int i = 0; i < G2[v].size(); i++) {
      edge e = G2[v][i];
      if (d2[e.to] > d2[v] + e.cost) {
        d2[e.to] = d2[v] + e.cost;
        que.push(P(d2[e.to], e.to));
      }
    }
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a, b;
  ll T, c;

  cin >> N >> M >> T;
  rep(i,N) cin >> A[i];
  rep(i, M){
    cin >> a >> b >> c;
    a--, b--;
    edge v = {b, c};
    edge v2 = {a, c};
    G[a].push_back(v);
    G2[b].push_back(v2);
  }

  ll max_money = 0ll;
  dijkstra(0);
  reverse_dijkstra(0);

  rep(i, N){
    if (d[i] == INF | d2[i] == INF) continue;
    max_money = max((T - d[i] - d2[i])*A[i], max_money);
  }
  cout << max_money << endl;
  return 0;
}
