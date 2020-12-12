#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
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
int h, w;
int c[102][102];
int sum[102][102]; // ある行でのsumRow
int sumCol[102][102]; // ある列でのsumCol

int main() {
  INCANT;
  cin >> h >> w;
  rep(i,h) rep(j, w) cin >> c[i][j];

  rep(i,h) rep(j,w) {
    int d1 = j%2?-1:1;
    int d2 = i%2?-1:1;
    sum[i][j+1] = sum[i][j]+d1*d2*c[i][j];
  }
  int ans = 0;
  rep(lef,w) {
    for(int rig = lef+1; rig<=w; rig++) {
      rep(top, h) {
        int tl = sum[top][lef];
        int tr = sum[top][rig];
        int tmp = tr-tl;
        if (tmp==0) ans = max(ans, rig-lef);
        if (top==h-1) break;
        for (int bot = top+1; bot<h; bot++) {
          tmp+=sum[bot][rig]-sum[bot][lef];
          if (tmp==0) {
            ans = max(ans, (rig-lef)*(bot-top+1));
          }
        }
      }
    }
  }


  cout << ans << "\n";
  return 0;
}