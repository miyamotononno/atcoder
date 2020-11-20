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
typedef long long ll;
using namespace std;
int n, m;

// グラフ、頂点の入次数、頂点数を受け取り、そのトポロジカルソートを記録した配列を返す関数
vector<int> topological_sort(vector<vector<int>> &G, vector<int> &indegree, int n) {
    // トポロジカルソートを記録する配列
    vector<int> sorted_vertices;

    // 入次数が0の頂点を発見したら、処理待ち頂点としてキューに追加する
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        int v = que.front();que.pop();
        // その頂点と隣接している頂点の入次数を減らし、0になればキューに追加
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) que.push(u);
        }
        // 頂点vを配列の末尾に追加する 
        sorted_vertices.push_back(v);
    }

    return sorted_vertices;
}


int main() {
  INCANT;
  cin >> n >> m;
  int a, b;
  vector<vector<int>> G;
  vector<int> indegree;
  rep(i, n+m-1) {
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    indegree[b]++;
  }
  vector<int> ret = topological_sort(G, indegree, 0);
  rep(i, n) cout << ret[i] << "\n";
  return 0;
}