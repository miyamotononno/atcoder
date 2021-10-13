#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, m;
typedef long long ll;
vector<int> G[100004], revG[100004];
typedef pair<int, int> P;


// 強連結成分分解(SOC)
// 完全グラフごとに分解できる
void dfs1(int s, int& idx, vector<int>& record, vector<bool>& visited) {
  if (record[s]>=0) return;
  if (visited[s]) {
    record[s] = idx;
    return;
  }
  visited[s] = true;
  for (int node: G[s]) {
    dfs1(node, idx, record, visited);
  }
  record[s] = idx;
  idx++;
}


ll dfs2(int s, vector<bool>& visited) {
  if (visited[s]) return 0;
  visited[s] = true;
  ll ret = 0ll;
  for (int node: revG[s]) {
    ret += dfs2(node, visited);
  }
  return ret + 1; // 自分自身を含む
}

int main() {
  cin >> n >> m;
  int a, b;
  for (int i=0; i<m; i++) {
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    revG[b].push_back(a);
  }

  // 帰りがけ順に記録
  vector<int> record(n, -1);
  vector<bool> visited(n, false);
  int idx = 0;
  for (int i=0; i<n; i++) {
    if (visited[i]) continue;
    dfs1(i, idx, record, visited);
  }
  vector<P> A;
  for (int i=0; i<n; i++) {
    A.push_back(P(record[i], i));
  }
  sort(A.begin(), A.end(), greater<P>());
  vector<bool> visited2(n, false);
  ll ret = 0ll;
  for (auto p: A) {
    int node = p.second;
    if (visited2[node]) continue;
    ll cnt = dfs2(node, visited2);
    ret += cnt*(cnt-1) / 2;
  }
  cout << ret << endl;

}