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
int H,W,K;
char c[10][10];

int main() {
  INCANT;
  cin >> H >> W >> K;
  rep(i, H) rep(j, W) cin >> c[i][j];
  int ans=0;
  rep(i, 1<<H) {
    rep(j, 1<<W) {
      int cnt=0;
      rep(k, H) {
        int maskh = 1 << k;
        if (maskh & i) continue;
        rep (l, W) {
          int maskw = 1 << l;
          if (maskw & j) continue;
          if (c[k][l]=='#') cnt++;
        }
      }
      if (cnt==K) ans++;
    }
  } 
  cout << ans << endl;
  return 0;
}