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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
string S;
int DP[10];

int dfs(int idx, bool flag_3, bool flag_5, bool flag_7, bool giri){
  if (idx==S.size()){
    if (flag_3 && flag_5 && flag_7) return 1;
    else return 0;
  }
  int ans = 0;
  int a = S[idx]-'0';
  if (!giri){
    if (DP[idx]>0) return DP[idx];
    ans += dfs(idx+1, true, flag_5, flag_7, false);
    ans += dfs(idx+1, flag_3, true, flag_7, false);
    ans += dfs(idx+1, flag_3, flag_5, true, false);
    DP[idx] = ans;
    return ans;
  }
  rep(i, a+1){
    if (i==3) ans += dfs(idx+1, true, flag_5, flag_7, i==a?true:false);
    else if (i==5) ans += dfs(idx+1, flag_3, true, flag_7, i==a?true:false);
    else if (i==7) ans += dfs(idx+1, flag_3, flag_5, true, i==a?true:false);
  }
  return ans;
} 

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  int ans = dfs(0, false, false, false, true);

  cout << ans << "\n";
  return 0;
}