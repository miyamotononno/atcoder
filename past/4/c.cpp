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
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int n, m;
char s[35][35];

int main() {
  cin >> n >> m;
  rep(i, n) {
    rep(j, m) {
      cin >> s[i+1][j+1];
    }
  }
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      int ret = 0;
      for (int x=i-1; x<=i+1; x++) {
        for (int y=j-1; y<=j+1; y++) {
          ret += s[x][y]=='#';
        } 
      }
      cout << ret;
    }
    cout << endl;
  }
  return 0;
}