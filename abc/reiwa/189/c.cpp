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
int A[10004];
int X[10001][10001];

int main() {
  INCANT;
  cin >> n;
  rep(i, n) {
    cin >> A[i];
  }
  for (int i=n-1; i>=0; i--) {
    int d = A[i];
    for (int j=i; j>=0; j--) {
      d = min(d, A[j]);
      X[i][j] = d;
    }
  }
  int ans = 0;
  for (int i=n-1; i>=0; i--) {
    for (int j=i; j>=0; j--) {
      ans = max(ans, X[i][j]*(i-j+1));
    }
  }
  cout << ans << endl;
  return 0;
}