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
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
vector<int> G[202];
int color[200];
vector<int> F;

int dfs(int v, int c){
  color[v] = c; //頂点vをcで塗る
  int cnt = 0;
  rep(i, G[v].size()){
    if (!color[G[v][i]]){
      if(color[G[v][i]]==c) return -1;
      cnt++;
    }
    //隣接している頂点がまだ塗られていないのなら-cで塗る
    if(color[G[v][i]]==0 && !dfs(G[v][i], -c)) return -1;
  }
  //全ての頂点が塗れたらtrue
  return cnt;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  char a;
  rep(i, N){
    for(int j=i+1; j<N; j++){
      cin >> a;
      if (a == '1') G[i].push_back(j); // 有向グラフにする
    }
  }
  int ans = 0;
  rep(i, N){
    if(color[i]==0){
      int cnt = dfs(i, 1);
      if (cnt < 0){
        cout << -1 << endl;
        return 0;
      }
    }
  }

  cout << 2 << "\n";
  return 0;
}