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
int n;
char s[52];

bool calc(int x, int y) {
  char tmp[n];
  rep(i, n) tmp[i] = s[i];
  rep(i, x) {
    rep(j, n) {
      if (j>0) {
        if (tmp[j]=='#') tmp[j-1] = '#';
      }
    }
  }
  rep(j, y) {
    for (int i=n-2; i>=0; i--) {
      if (tmp[i]=='#') tmp[i+1] = '#';
    }
  }
  rep(i, n) {
    if (tmp[i]=='.') return false;
  }
  return true;
}

int main() {
  cin >> n;
  rep(i, n) cin >> s[i];
  rep(sumCount, n+1) {
    rep(x, sumCount+1) {
      int y = sumCount-x;
      if (calc(x, y)) {
        cout << x << ' ' << y << endl;
        return 0;
      }
    }
  }
}