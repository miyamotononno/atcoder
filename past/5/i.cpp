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

// グラフ、頂点の入次数、頂点数を受け取り、そのトポロジカルソートを記録した配列を返す関数
vector<int> topological_sort(vector<vector<int> > &G, vector<int> &indegree) {
    vector<int> sorted_vertices;
    queue<int> que;
    rep(i, n) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        int v = que.front();que.pop();
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            indegree[u]--;
            if (indegree[u] == 0) que.push(u);
        }
        sorted_vertices.push_back(v);
    }

    return sorted_vertices;
}


int main() {
  INCANT;
  cin >> n >> m >> k;
  rep(i, n) cin >> h[i];
  rep(i, k) cin >> C[i];
  vector<vector<int> > G;
  vector<int> indegree;
  rep(i, m) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    if (h[a]<h[b]) { // 逆戻りで考える
      G[a].push_back(b);
      indegree[b]++;
    } else {
      G[b].push_back(a);
      indegree[a]++;
    }
  }
  // vector<int> ret = topological_sort(G, indegree);
  // rep(i, n) cout << ret[i] << endl;
  return 0;
}