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
int N;
vector<int> G[100005];
int color[100005];
unordered_map<string, int> M;
int color_count;

void dfs(int now, int c)  {
  int n_color = 0;
  rep(j, G[now].size()) {
    int next = G[now][j];
    int a = now, b =next;
    if (now > next) swap(a, b);
    string t = to_string(a)+'-'+to_string(b);
    int idx = M[t];
    if (color[idx] >= 0) continue;
    if (n_color==c) n_color++;
    if (n_color>=color_count) n_color=0;
    color[idx] =n_color;
    dfs(next, n_color);
    n_color++;
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
  dfs(0, 0);
  cout << color_count << "\n";
  rep(i, N-1) cout << color[i]+1 << "\n";
  return 0;
}
