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
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
const ll INF = 1LL << 50;
struct edge {int from, to, cost;};
edge es[5005];
ll d[2502];
int N,M,P;
bool negative[2502]; 

void shortest_path(int s){
  rep(i, N) d[i] = INF;
  d[s] = 0;
  rep(loop, N-1){
    rep(i, M){
      edge e = es[i];
      if (d[e.from] == INF) continue;
      if(d[e.from] != INF && d[e.to] > d[e.from]+e.cost) d[e.to] = d[e.from] + e.cost;
    }
  }
}

void find_negative_loop(){
  rep(i, N){
    rep(j, M){
      edge e =es[j];
      if (d[e.from] == INF) continue;
      if (d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        // n回目にも更新があるなら負の経路が存在する
        negative[e.from] = true;
      }
      if(negative[e.from]) negative[e.to] = true;
    }
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> P;
  int a,b,c;
  rep(i, M){
    cin >> a >> b >> c;
    a--, b--;
    edge e = {a, b, -c+P};
    es[i] = e;
  }
  shortest_path(0);
  find_negative_loop();
  int ans = - d[N-1];
  if (negative[N-1]) cout << -1 << endl;
  else cout << max(ans, 0) << endl;
}