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
int n, k;
int T[10][10];

int main() {
  INCANT;
  cin >> n >> k;
  rep(i, n) rep(j, n) cin >> T[i][j];
  int a[n];
  rep(i, n-1) a[i]=i+1;
  int ret=0;
  do {
    int cur = 0;
    int tm = 0;
    rep(i, n-1) {
      tm+=T[cur][a[i]];
      cur=a[i];
    }
    tm+=T[cur][0];
    if (tm==k) ret++;
  } while(next_permutation(a, a + n-1));
  cout << ret << "\n";
  return 0;
}