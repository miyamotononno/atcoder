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
int V,E;

void shortest_path(int s){
  rep(i, V) d[i] = INF;
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
  rep(i, V){
    rep(j, E){
      edge e =es[j];
      if (d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        // n回目にも更新があるなら負の経路が存在する
        if (i == V-1) return true;
      }
    }
  }
  return false;
}