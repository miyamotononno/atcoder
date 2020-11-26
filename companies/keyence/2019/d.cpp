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
int h, w;
int A[1001],B[1001];

int main() {
  INCANT;
  cin >> h >> w;
  rep(i, h) cin >> A[i]; 
  rep(i, w) cin >> B[i];

  sort(A, A+h, greater<int>());
  sort(B, B+w, greater<int>());
  int rowIdx = 0;
  int colIdx = 0;
  ll ans = 1ll;
  for (int cur=h*w; cur>=1; cur--) {
    if (A[rowIdx] == cur && B[colIdx] == cur) {
      rowIdx++;
      colIdx++;
      continue;
    }
    if (A[rowIdx] == cur) {
      ans*=(ll)colIdx;
      ans%=MOD;
      rowIdx++;
      continue;
    }
    if (B[colIdx] == cur) {
      ans*=(ll)rowIdx;
      ans%=MOD;
      colIdx++;
      continue;
    }
    ll rest = colIdx * rowIdx - (h*w-cur);
    if (rest <= 0ll) {
      cout << 0 << endl;
      return 0;
    }
    ans*=rest;
    ans%=MOD;
  }

  cout << ans << "\n";
  return 0;
}