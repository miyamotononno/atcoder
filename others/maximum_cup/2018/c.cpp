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
const ll MOD = 1000000007LL;
int N;
int G[100005], color[100005];

bool dfs(int v, int c){
  color[v] = c; //頂点vをcで塗る
  if(color[G[v]]==c) return false;
  //隣接している頂点がまだ塗られていないのなら-cで塗る
  if(color[G[v]]==0 && !dfs(G[v], -c)) return false;
  //全ての頂点が塗れたらtrue
  return true;
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a;
  rep(i, N){
    cin >> a;
    a--;
    G[i] = a;
  }
  rep(i, N){
    if(color[i]==0){
      //まだ頂点iが塗られていないなら1で塗る
      if (!dfs(i, 1)){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << N/2 << endl;
  return 0;
}