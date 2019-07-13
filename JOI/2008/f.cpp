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
typedef pair<ll, int> P; //firstは最短距離、secondは頂点の番号

const ll INF = numeric_limits<ll>::max();

int n, k;
vector<edge> G[105]; //MAX_V
ll d[105]; //MAX_V

void dijkstra(int s) {
  // greater<P>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P> >  que;
  fill(d, d + n, INF);
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


int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  int x;
  rep(i, k){
    cin >> x;
    if (x==0){
      int a,b;
      cin >> a >>b;
      a--, b--;
      dijkstra(a);
      ll ans = d[b];
      if (ans < INF) cout << d[b] << endl;
      else cout << -1 << endl;
      continue;
    }

    int c,d;
    ll e;
    cin >> c >> d >> e;
    c--, d--;
    bool flag = false;
    rep(i, G[c].size()){
      if(G[c][i].to == d){
        if(G[c][i].cost > e){
          flag = false;
          G[c][i].cost = e;
          break;
        }else{
          flag = true;
          break;
        }
      }
    }
    if(flag) continue;
    rep(i, G[d].size()){
      if(G[d][i].to == d){
        flag = true;
        G[d][i].cost = e;
        break;
      }
    }
    if(flag) continue;
    edge edge1 = {d, e};
    edge edge2 = {c, e};
    G[c].push_back(edge1);
    G[d].push_back(edge2); 
  }
}
