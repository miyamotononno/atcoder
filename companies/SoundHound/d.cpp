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
using namespace std;
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
const ll init = pow(10, 15);
struct edge {int to; ll yen, snuke; };
typedef pair<int, int> P; //firstは最短距離、secondは頂点の番号
typedef pair<ll, int> P2; //firstは最短コスト、secondは頂点の番号(index)
int n; //頂点数
vector<edge> G[100005];
ll d_yen[100005], d_snuke[100005];

//始点sから各頂点への最短経路を求める(yen)
void dijkstra_yen(int s) {
  // greater<P>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P> >  que;
  fill(d_yen, d_yen + n, init);
  d_yen[s] = 0;
  que.push(P(0, s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if (d_yen[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d_yen[e.to] > d_yen[v] + e.yen) {
        d_yen[e.to] = d_yen[v] + e.yen;
        que.push(P(d_yen[e.to], e.to));
      }
    }
  }
}

//始点sから各頂点への最短経路を求める(snuke)
void dijkstra_snuke(int s) {
  // greater<P>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P> >  que;
  fill(d_snuke, d_snuke + n, init);
  d_snuke[s] = 0;
  que.push(P(0, s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if (d_snuke[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d_snuke[e.to] > d_snuke[v] + e.snuke) {
        d_snuke[e.to] = d_snuke[v] + e.snuke;
        que.push(P(d_snuke[e.to], e.to));
      }
    }
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int m,s,t,u,v;
  cin >> n >> m >> s >> t;
  s--, t--;
  ll a,b;
  rep(i, m){
    cin >> u >> v >> a >> b;
    u--,v--;
    edge edge1 = {v, a, b};
    edge edge2 = {u, a, b};
    G[u].push_back(edge1);
    G[v].push_back(edge2); 
  }
  dijkstra_yen(s);
  dijkstra_snuke(t);

  priority_queue<P2, vector<P2>, greater<P2> > que2;
  rep(i, n) que2.push(P2(d_yen[i]+d_snuke[i], i));
  
  rep(i,n){
    P2 ans = que2.top();
    while(i > ans.second){
      que2.pop();
      ans = que2.top();
    }
    cout << init - ans.first << endl;
  }

  return 0;
}