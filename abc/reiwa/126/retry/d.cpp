#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;
typedef pair<int, int> P;
vector<P> G[100005];
int C[100005];

void dfs(int idx, int color) {
  if (C[idx]>=0) return;
  C[idx]=color;
  for (auto p: G[idx]) {
    dfs(p.first, (color+p.second)%2);
  }
}

int main() {
  INCANT;
  cin >> N;
  int u,v,w;
  rep(i, N-1) {
    cin >> u >> v >> w;
    u--; v--;
    G[u].push_back(P(v, w%2));
    G[v].push_back(P(u, w%2));
  }
  fill(C, C+N, -1);
  dfs(0, 0);
  rep(i, N) cout << C[i] << "\n";
  return 0;
}