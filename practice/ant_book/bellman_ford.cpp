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
using namespace std;
const int MAX_E = 1000005;
const int MAX_V = 1000005;
const int INF = numeric_limits<int>::max();
struct edge {int from, to, cost;};
edge es[MAX_E];
int d[MAX_V];
int N,E;

void shortest_path(int s){
  rep(i, N) d[i] = INF;
  d[s] = 0;
  while(true){
    bool update = false;
    rep(i, E){
      edge e = es[i];
      if(d[e.from] != INF && d[e.to] > d[e.from]+e.cost){
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
    }
    if (!update) break;
  }
}

bool find_negative_loop(){
  memset(d, 0, sizeof(d));
  rep(i, N){
    rep(j, E){
      edge e =es[j];
      if (d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        // n回目にも更新があるなら負の経路が存在する
        if (i == N-1) return true;
      }
    }
  }
  return false;
}

// 目的地までいくのに、閉路が存在する場合は以下。
bool Negative[1005];
void find_negative_loop2(){
  memset(Negative, false, sizeof(Negative));
  rep(i, N){
    rep(j, E){
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