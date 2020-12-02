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
int x[101];

int main() {
  INCANT;
  cin >> n;
  rep(i, n) cin >> x[i];
  
  int ans = INF;
  for (int i=1; i<=100; i++) {
    int tmp = 0;
    rep(j, n) {
      tmp+=(x[j]-i)*(x[j]-i);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}