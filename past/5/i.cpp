#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n, m, k;
int h[200005], C[200005];
int costs[200005];
vector<int> G[200005];
typedef pair<int, int> P; // 点, cost

int main() {
  INCANT;
  cin >> n >> m >> k;
  rep(i, n) cin >> h[i];
  rep(i, k) {
    cin >> C[i];
    C[i]--;
  }
  
  int a,b;
  rep(i, m) {
    cin >> a >> b;
    a--;b--;
    if (h[a]<h[b]) { // 逆戻りで考える
      G[a].push_back(b);
    } else {
      G[b].push_back(a);
    }
  }
  rep(i, n) costs[i]=-1;
  queue<P> que;
  rep(i, k) {
    que.push(P(C[i], 0));
  }
  while(!que.empty()) {
    P p = que.front(); que.pop();
    int node = p.first;
    int cost = p.second;
    if (costs[node]>=0 && costs[node]<cost) continue;
    costs[node] = cost;
    for (auto ne: G[node]) {
      if (costs[ne]<0 || costs[ne]>cost+1) {
        que.push(P(ne, cost+1));
        costs[ne] = cost+1;
      }
    }
  }

  rep(i, n) {
    cout << costs[i] << endl;
  }

  return 0;
}