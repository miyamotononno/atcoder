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
const ll INF = 2e18;
int n, m;
ll A[200005];
ll B[200005]; // それ以前の最小の金額
int X[200005], Y[200005];
vector<int> G[200005];
ll costs[200005]; // その町で買った時の最大金額

int main() {
  INCANT;
  cin >> n >> m;
  rep(i, n) cin >> A[i];
  rep(i, n) B[i] = INF;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    G[x-1].push_back(y-1);
  }
  rep(i, n) {
    for (auto ne: G[i]) {
      B[ne] = min(B[ne], B[i]); // すでに更新されているものと、今更新するもののどちらが低いか
      B[ne] = min(B[ne], A[i]); // 今の値と、前からきたものどちらが低いか
    }
  }

  ll ans = -INF;
  rep(i, n) {
    ans = max(ans, A[i]-B[i]);
  }

  cout << ans << "\n";
  return 0;
}