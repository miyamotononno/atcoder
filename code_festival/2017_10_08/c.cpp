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
typedef long long ll;
ll N, M;
vector<int> G[100005];
int color[100005];

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

bool is_bigraph(){
  rep(i, N){
    if(color[i]==0){
      //まだ頂点iが塗られていないなら1で塗る
      if (!dfs(i, 1)){
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int a, b;
  rep(i, M){
    cin >> a >> b;
    G[a-1].push_back(b-1); //indexのため-1
    G[b-1].push_back(a-1); //同様
  };
  ll ans;
  if(!is_bigraph()){
    ans = (N*(N-1))/2 - M;
    cout << ans << endl;
    return 0;
  }

  ll b_cnt=0;
  ll w_cnt=0;
  rep(i, N){
    if (color[i]>0) b_cnt++;
    else w_cnt++;
  }
  ans = b_cnt*w_cnt - M;
  cout << ans << endl;
  
  return 0;
}