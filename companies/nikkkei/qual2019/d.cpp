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
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n, m;
vector<int> G[100005];
int indegree[100005];
typedef pair<int, int> P;
int degrees[100005];

vector<int> topological_sort(int V) {
    vector<int> sorted_vertices;
    queue<int> que;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }
    while (que.empty() == false) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) que.push(u);
        }
        sorted_vertices.push_back(v);
    }
    return sorted_vertices;
}

void dfs(int cur, int par, vector<int>& record) {
  if (record[cur]>=-1) return;
  record[cur] = par;
  priority_queue<P, vector<P>, greater<P> > que;
  for (auto n: G[cur]) que.push(P(degrees[n], n));
  while(!que.empty()) {
    P p = que.top(); que.pop();
    dfs(p.second, cur, record);
  }
}

int main() {
  INCANT;
  cin >> n >> m;
  int a, b;
  rep(i, n+m-1) {
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    indegree[b]++;
  }

  vector<int> sorted_vertices = topological_sort(n);
  rep(i, n) {
    degrees[sorted_vertices[i]] = i;
  }
  int root = sorted_vertices[0];
  vector<int> record(n, -2);
  dfs(root, -1, record);
  rep(i, n) {
    cout << record[i]+1 << endl;
  }
  return 0;
}