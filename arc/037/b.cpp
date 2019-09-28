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
int N, M;
vector<int> G[103];
vector<int> visited(103);

bool dfs(int now, int pre){
  visited[now] = true;
  vector<int> Nt = G[now];
  rep(i, Nt.size()){
    int nxt = Nt[i];
    if (nxt==pre) continue;
    if (visited[nxt]) return false;
    bool flag = dfs(nxt, now);
    if (!flag) return false; 
  }
  return true;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int u, v;
  rep(i, M){
    cin >> u>> v;
    u--; v --;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int cnt=0;
  rep(i, N){
    if (visited[i]) continue;
    bool flag = dfs(i, -1);
    if (flag) cnt++; 
  }

  cout << cnt << "\n";
  return 0;
}