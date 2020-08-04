#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
int N;
vector<int> G[100005];
int color[100005];
unordered_map<string, int> M;
int color_count;

void bfs() {
  queue<P> que;
  que.push(make_pair(0,0));
  while(!que.empty()) {
    P p = que.front(); que.pop();
    int now = p.first;
    int c = p.second;
    int color_idx = 0;
    rep(j, G[now].size()) {
      int next = G[now][j];
      int a = now, b =next;
      if (now > next) swap(a, b);
      string t = to_string(a)+'-'+to_string(b);
      int idx = M[t];
      if (color[idx] >= 0) continue;
      if (color_idx==c) color_idx++;
      if (color_idx>=color_count) color_idx=0;
      color[idx] = color_idx;
      que.push(make_pair(next, color_idx));
      color_idx++;
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  int a,b;
  rep(i, N-1) {
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
    string t = to_string(a)+'-'+to_string(b);
    M[t]=i;
  }

  rep(i, N) {
    int d = G[i].size();
    color_count = max(color_count, d);
  }
  fill(color, color+N, -1);
  bfs();
  cout << color_count << "\n";
  rep(i, N-1) cout << color[i]+1 << "\n";
  return 0;
}
