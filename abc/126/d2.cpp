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
typedef pair<int, int> P;
const ll MOD = 1e9+7LL;
const int INF = 1e9+7;
int N;
vector<P> T[100005];
int color[100005]; // 0は未彩色　-1or1

void dfs(int v, int c){
  if (color[v] != 0) return;
  color[v] = c;
  rep(i, T[v].size()) {
    P p = T[v][i];
    int nc = p.second?-c:c;
    dfs(p.first, nc);
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int u,v,w;
  rep(i, N-1) {
    cin >> u >> v >> w;
    u--; v--;
    w%=2;
    T[u].push_back(P(v,w));
    T[v].push_back(P(u,w));
  }

  dfs(0,1);
  rep(i, N) {
    int c = color[i]>0?1:0;
    cout << c << "\n";
  }
  return 0;
}