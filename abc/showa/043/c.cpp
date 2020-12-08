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
const int INF = 2e9;
int n;
int a[102];

int main() {
  INCANT;
  cin >> n;
  int mn=100;
  int mx=-100;
  rep(i,n) {
    cin >> a[i];
    mn=min(mn, a[i]);
    mx=max(mx, a[i]);
  }
  int ans = INF;
  for (int i=mn; i<=mx; i++) {
    int tmp=0;
    rep(j, n) tmp += (i-a[j])*(i-a[j]);
    ans = min(ans, tmp);
  }
  cout << ans << "\n";
  return 0;
}