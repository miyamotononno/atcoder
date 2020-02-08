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
const int INF = 1000000007;
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for (int i=0; i<n;++i)
struct edge {int to, cost; };
typedef pair<int, int> P; //firstは最短距離、secondは頂点の番号
int N;
vector<edge> G[1000000]; //MAX_N
int d[1000000];
int prevy[1000000]; //MAX_N

void dijkstra(int s) {
  // greater<P>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + N, INF);
  fill(prevy, prevy + N, -1);
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    rep(i, G[v].size()) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        prevy[e.to] = v;
        que.push(P(d[e.to], e.to));
      } 
    }
  }
}

vector<int> get_path(int t) { // 始点と終点含む
  vector<int> path;
  for (; t != -1; t = prevy[t]) path.push_back(t); // tがsになるまでprev[t]を辿っていく
  reverse(ALL(path));
  return path;
}

int main() { // 確認用
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int M;
  cin >> N >> M;
  int s,t, x;
  rep(i, M) {
    cin >> s >> t >> x;
    edge edge1 = {s, x};
    edge edge2 = {t, x};
    G[t].push_back(edge1);
    G[s].push_back(edge2);
  }
  dijkstra(0);
  vector<int> paths = get_path(N-1);
  rep(i, paths.size()) {
    cout << paths[i] << "\n";
  }
  return 0;
}
