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
struct edge {int to, cost; };
typedef pair<int, int> P; //firstは最短距離、secondは頂点の番号
 
int V;
vector<edge> G[1000000]; //MAX_V
int d[1000000], prev[1000000]; //MAX_V

void dijkstra(int s) {
  // greater<P>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P> >  que;
  fill(d, d + V, INF);
  fill(prev, prev + V, -1);
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
        prev[e.to] = v;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

vector<int> get_path(int t) {
  vector<int> path;
  for (; t != -1; t = prev[t]) path.push_back(t); // tがsになるまでprev[t]を辿っていく
  reverse(ALL(path));
  return path;
}
