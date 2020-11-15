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
int n, m, k;
char s[31][31];

bool calc(int& edge, int& y, int& x) {
  unordered_map<char, int> Cnts;
  for (int i=y; i<=y+edge-1; i++) {
    for (int j=x; j<=x+edge-1; j++) {
      Cnts[s[i][j]]++;
    }
  }
  for (auto p: Cnts) {
    if (p.second+k>=edge*edge) return true;
  }
  return false;
}

int main() {
  INCANT;
  cin >> n >> m >> k;
  rep(i, n) rep(j, m) cin >> s[i][j];
  int MAX_EDGE = min(n,m);
  if (MAX_EDGE==1) {
    cout << 1 << endl;
    return 0;
  }
  for (int edge=MAX_EDGE; edge>=2; edge--) {
    rep(i, n-edge+1) {
      rep(j, m-edge+1) {
        if (calc(edge, i, j)) {
          cout << edge << endl;
          return 0;
        }
      }
    }
  }
  cout << 1 << endl;
  return 0;
}