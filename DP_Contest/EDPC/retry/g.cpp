#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
using namespace std;
int N, M; 
int DP[100003];
vector<int> Graph[100003];

int dfs(int idx) {
  if (DP[idx] > 0) return DP[idx];
  vector<int> a = Graph[idx];
  int ret = 0;
  rep(i, a.size()) {
    ret = max(dfs(a[i])+1, ret);
  }
  DP[idx] = ret;
  return ret;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  rep(i, N) DP[i] = -1;
  int x,y;
  rep(i, M) {
    cin >> x >> y;
    x--;y--;
    Graph[x].push_back(y); 
  }
  int idx = 0;
  int ans = 0; 
  while(idx<N) {
    if (DP[idx] > 0) {
      idx++;
      continue;
    }
    ans = max(ans, dfs(idx));
    idx++;
  }

  cout << ans << "\n";
  return 0;
}