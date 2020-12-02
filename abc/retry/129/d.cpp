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
int H,W;
char S[2001][2001];
queue<int> rows[2001], cols[2001];
int rowCnt[2001][2001], colCnt[2001][2001];

int main() {
  INCANT;
  cin >> H >> W;
  rep(i, H) {
    rep(j, W) {
      cin >> S[i][j];
      if (S[i][j]=='#') {
        rows[i].push(j);
        cols[j].push(i);
      }
    }
  }
  
  rep(i, H) {
    queue<int> R = rows[i];
    int pre = -1;
    rep(j, W) {
      if (S[i][j]=='#') {
        pre = R.front();
        R.pop();
        continue;
      }
      if (R.empty()) {
        rowCnt[i][j] = W-1-pre;
      } else {
        rowCnt[i][j] = R.front()-pre-1;
      }
    }
  }
  rep(j, W) {
    queue<int> R = cols[j];
    int pre = -1;
    rep(i, H) {
      if (S[i][j]=='#') {
        pre = R.front();
        R.pop();
        continue;
      }
      if (R.empty()) {
        colCnt[i][j] = H-1-pre;
      } else {
        colCnt[i][j] = R.front()-pre-1;
      }
    }
  }

  int ans = 0;
  rep(i, H) {
    rep(j, W) {
      if (S[i][j]=='#') continue;
      ans = max(ans, rowCnt[i][j]+colCnt[i][j]-1);
    }
  }
  cout << ans << "\n";
  return 0;
}