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
int n, a[1002];

int main() {
  INCANT;
  cin >> n;
  rep(i, n) cin >> a[i];
  int ans = 0;
  int MAX=0;
  for (int k=2; k<=1000; k++) {
    int cnt= 0;
    rep(i, n) cnt+=(a[i]%k==0);
    if (cnt>MAX) {
      MAX=cnt;
      ans=k;
    }
  }
  
  cout << ans << "\n";
  return 0;
}