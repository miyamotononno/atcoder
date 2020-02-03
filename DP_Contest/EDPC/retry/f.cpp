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
int N;
string s, t; 
int DP[3002][3002]; // sのi文字目までとtのj文字目まで探索し、その最大共通個数

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s >> t;
  rep(i, s.size()) {
    rep(j, t.size()) {
      if (s[i] == t[j]) {
        DP[i+1][j+1] = max(DP[i][j]+1, DP[i+1][j+1]);
      }
      DP[i+1][j+1] = max(DP[i+1][j+1], DP[i][j+1]);
      DP[i+1][j+1] = max(DP[i+1][j+1], DP[i+1][j]);
    }
  }

  string ans = "";
  int s_idx = (int)s.size();
  int t_idx = (int)t.size();
  while (s_idx > 0 && t_idx > 0) {
    if (DP[s_idx][t_idx] == DP[s_idx-1][t_idx]) s_idx--;
    else if (DP[s_idx][t_idx] == DP[s_idx][t_idx-1]) t_idx--;
    else {
      ans = s[s_idx-1]+ans;
      s_idx--;
      t_idx--;
    }
  }
  cout << ans << "\n";
  return 0;
}