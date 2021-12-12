#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, dist;
};

bool dfs(int cur, int rest, bool seen[], vector<edge> T[]) {
  if (rest==0) return true;
  seen[cur] = true;
  for (edge e: T[cur]) {
    if (rest-e.dist>=0 && !seen[e.to]) {
      bool ret = dfs(e.to, rest-e.dist, seen, T);
      if (ret) return true;
    }
  }
  return false;
}

bool solve(const int& N, const int& X, vector<edge> T[]) {
  for (int s=0; s<N; s++) {
    bool seen[N];
    generate(seen, seen+N, [](){return false;});
    bool ret = dfs(s, X, seen, T);
    if (ret) return true;
  }
  return false;
}

int main() {
  int N, X;
  cin >> N >> X;
  vector<edge> T[N];
  for (int i=0; i<N-1; i++) {
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    T[a].push_back(edge{b,c});
    T[b].push_back(edge{a,c});
  }
  bool flag = solve(N,X,T);
  cout << (flag?"Yes":"No") << endl;
}