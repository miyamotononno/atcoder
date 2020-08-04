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
ll N;

int dfs(ll s){
  if (s > N) return 0;
  bool flag_3 = false;
  bool flag_5 = false;
  bool flag_7 = false;
  ll z = s;
  while(z>0){
    int a = z%10;
    if (a==3) flag_3 = true;
    if (a==5) flag_5 = true;
    if (a==7) flag_7 = true;
    if (flag_3&&flag_5&&flag_7) break;
    z/=10;
  }
  int ret = flag_3&&flag_5&&flag_7?1:0;
  ret += dfs(s*10+3);
  ret += dfs(s*10+5);
  ret += dfs(s*10+7);
  return ret;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  cout << dfs(0ll) << "\n";
  return 0;
}
