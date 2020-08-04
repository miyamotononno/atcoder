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
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
ll H;
ll DP[100005]; // 0番目はN, 1番目は[N/2], 2番目は[N/2]/2...

ll dfs(ll h, int idx) {
  if (h==1) return 1;
  if (DP[idx]>0) return DP[h];
  ll ret = 2*dfs(h/2, idx+1);
  DP[idx] = ret; 
  return ret;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H;
  cout << 2*dfs(H, 0)-1 << "\n";
  return 0;
}