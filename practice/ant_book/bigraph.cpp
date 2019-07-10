// P.93

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
vector<int> G[MAX_V];
int V;
int color[MAX_V];

bool dfs(int v, int c){
  color[v] = c; //頂点vをcで塗る
  rep(i, G[v].size()){
    //隣接している頂点が同じ色ならfalse
    if(color[G[v][i]]==c) return false;
    //隣接している頂点がまだ塗られていないのなら-cで塗る
    if(color[G[v][i]]==0 && !dfs(G[v][i], -c)) return false;
  }
  //全ての頂点が塗れたらtrue
  return true;
}

void solve(){
  rep(i, V){
    if(color[i]==0){
      //まだ頂点iが塗られていないなら1で塗る
      if (!dfs(i, 1)){
        cout << "No" << endl;
        return;
      }
    }
  }
  cout << "Yes" << endl;
}
