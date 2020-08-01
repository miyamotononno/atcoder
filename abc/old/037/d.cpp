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
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int H, W;
int a[1002][1002];
ll b[10002][1002];

ll dfs(int h, int w) {
  if (b[h][w]>0) return b[h][w];
  b[h][w] = 1ll; // そこに留まる
  if (h!=H-1 && a[h][w]<a[h+1][w]) b[h][w] += dfs(h+1, w)%MOD;
  if (h!=0 && a[h][w]<a[h-1][w] ) b[h][w] += dfs(h-1, w)%MOD;
  if (w!=W-1 && a[h][w]<a[h][w+1]) b[h][w] += dfs(h, w+1)%MOD;
  if (w!=0 && a[h][w]<a[h][w-1]) b[h][w] += dfs(h, w-1)%MOD;
  b[h][w]%=MOD;
  return b[h][w];
}

int main() {
  INCANT;
  cin >> H >> W;
  rep(i, H) rep(j, W) cin >> a[i][j];
  ll ans = 0ll;
  rep(i, H) {
    rep(j, W) {
      ans+=dfs(i,j);
      ans%=MOD;
    }
  } 
  
  cout << ans << "\n";
  return 0;
}