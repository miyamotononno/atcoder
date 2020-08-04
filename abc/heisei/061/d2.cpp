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
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll INF = 1e18;
int N, M;
ll d[1005];
bool Negative[1005];
struct edge {int from, to; ll cost;};
edge es[2005];

void shortest_path(int s){
  rep(i, N) d[i] = INF;
  d[s] = 0ll;
  rep(j, N-1) {
    rep(i, M) {
      edge e = es[i];
      if(d[e.from] != INF && d[e.to] > d[e.from]+e.cost){
        d[e.to] = d[e.from] + e.cost;
      }
    }
  }
}

void find_negative_loop(){
  memset(Negative, false, sizeof(Negative));
  rep(i, N){
    rep(j, M){
      edge e =es[j];
      if (d[e.from] == INF) continue;
      if (d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        Negative[e.to] = true;
      }
      if (Negative[e.from]) Negative[e.to] = true;
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int a,b; ll c;
  rep(i,M) {
    cin >> a >> b >> c;
    a--;b--;
    edge e = {a,b,-c};
    es[i] = e;
  }
  shortest_path(0);
  find_negative_loop();
  if (Negative[N-1]) {
    cout << "inf" << "\n";
    return 0;
  }
  cout << -d[N-1] << "\n";
  return 0;
}