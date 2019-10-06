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
const int INF = 1000000007;
int N;
vector<int> G[202];
int color[200];
int L[201];
int d[201][201];

bool dfs(int v, int c){
  color[v] = c;
  rep(i, G[v].size()){
    if(color[G[v][i]]==c) return false;
    if(color[G[v][i]]==0 && !dfs(G[v][i], -c)) return false;
  }
  return true;
}

void warshall_floyd() {
  rep(k, N){
    rep(i, N){
      rep(j, N) d[i][j] =min(d[i][j], d[i][k]+d[k][j]);
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  char a;
  rep(i, N){
    rep(j, N){
      cin >> a;
      if (a == '1'){
        G[i].push_back(j);
        d[i][j] = 1;
      } else {
        d[i][j] = INF;
      }
    }
  }

  if (!dfs(0, 1)){
    cout << -1 << endl;
    return 0;
  }

  warshall_floyd();
  int ans = 0;
  rep(i, N){
    rep(j, N) {
      if (i==j) continue;
      ans = max(ans, d[i][j]);
    }
  }

  cout << ans+1 << "\n";
  return 0;
}
