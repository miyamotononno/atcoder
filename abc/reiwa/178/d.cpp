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
int S;
ll DP[2001]; // i番目までで総和j使ったときの順列数

ll dfs(ll rest) {
  if (rest==0) return 1ll;
  if (rest<3) return 0ll;
  if (DP[rest]>=0) return DP[rest]; 
  ll ret=0ll;
  for (int r=3; r<=S; r++) {
    ret+=dfs(rest-r);
    ret%=MOD;
  }
  DP[rest] = ret;
  return ret;
}

int main() {
  INCANT;
  cin >> S;
  rep(j, 2001) DP[j] = -1;
  DP[0]=0;DP[1]=0;DP[2]=0;
  cout << dfs(S) << "\n";
  return 0;
}