#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

void calc(vector<P> G[], const vector<int>& X, const int& n) {
  vector<bool> Visited(n, false);
  Visited[0] = true;
  int ans = 1;
  priority_queue<P, vector<P>, greater<P>> pque;
  for (P p: G[0]) pque.push(p);
  for (int x: X) {
    vector<P> vec;
    while(!pque.empty()) {
      P p = pque.top();
      if (p.first > x) break;
      pque.pop();
      int node = p.second;
      if (Visited[node]) continue;
      Visited[node]=true;
      ans++;
      for (P nextVec: G[node]) {
        vec.push_back(nextVec);
      }
    }
    for (P v: vec) {
      pque.push(v);
    }

    cout << ans << endl;
  }
}


int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<P> G[n];
  int a, b, c;
  for (int i=0; i<m; i++) {
    cin >> a >> b >> c;
    a--;b--;
    G[a].push_back(P(c,b));
    G[b].push_back(P(c,a));
  }
  vector<int> X(q);
  for (int i=0; i<q; i++) {
    cin >> X[i];
  }
  calc(G,X, n);
}