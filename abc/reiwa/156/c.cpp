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
#define rep_itr(it, M) for (auto it = M.begin(); it != M.end(); ++it)
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, X[101];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> X[i];

  // 0-index
  int minx = INF;
  rep(i, 100) {
    int ans = 0;
    rep(j, N) {
      ans += pow(X[j]-i-1, 2);
    }
    minx =min(minx, ans);
  }
  cout << minx << "\n";
  return 0;
}