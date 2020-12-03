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
int A[3][3];
bool seen[3][3];
int n;

int main() {
  INCANT;
  rep(i, 3) rep(j, 3) cin >> A[i][j];
  cin >> n;
  int a;
  rep(i, n) {
    cin >> a;
    rep(j, 3) rep(k, 3) {
      if (A[j][k] == a) {
        seen[j][k]=true;
      }
    }
  }

  bool ok;
  rep(i, 3) {
    ok = true;
    rep(j, 3) {
      if (!seen[i][j]) ok = false;
    }
    if (ok) {
      cout << "Yes" << "\n";
      return 0;
    }
  }

  rep(i, 3) {
    ok = true;
    rep(j, 3) {
      if (!seen[j][i]) ok = false;
    }
    if (ok) {
      cout << "Yes" << "\n";
      return 0;
    }
  }

  ok = true;
  rep(i, 3) {
    if (!seen[i][i]) ok = false;
  }
  if (ok) {
    cout << "Yes" << "\n";
    return 0;
  }

  ok = true;
  rep(i, 3) {
    if (!seen[2-i][i]) ok = false;
  }
  if (ok) {
    cout << "Yes" << "\n";
    return 0;
  }

  cout << "No" << "\n";
  return 0;
}