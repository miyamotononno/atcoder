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
int n, m;

int main() {
  INCANT;
  cin >> n >> m;
  if (n==1) {
    if (m==0) cout << 1 << ' ' << 2 << endl;
    else cout << -1 << endl;
    return 0;
  }
  if (m<0 || n-2<m) {
    cout << -1 << endl;
    return 0;
  }
  int initialEnd = 3*(m+2);
  rep(i, n) {
    if (i==0) {
      cout << 1 << ' ' << initialEnd << endl;
    } else {
      cout << i*3+1 << ' ' << i*3+2 << endl;
    }
  }
  return 0;
}