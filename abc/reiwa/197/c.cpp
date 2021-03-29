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
int n;
int A[21];

int main() {
  INCANT;
  cin >> n;
  rep(i, n) cin >> A[i];
  if (n==1) {
    cout << A[0] << endl;
    return 0;
  }
  int ans = INF;
  rep(i, (1<<(n-1))) {
    int orElm=A[0];
    int xorElm=0;
    rep(bit, n-1) {
      if ((1<<bit) & i) { // 敷居がある
        xorElm ^= orElm;
        orElm=0;
      }
      orElm |= A[bit+1];
    }
    xorElm ^= orElm;
    ans = min(ans, xorElm);
  }

  cout << ans << "\n";
  return 0;
}