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
int n,m,k;
int A[101], B[101], X[101][2];

int calc(unordered_map<int, bool> U) {
  int cnt=0;
  rep(i, m) {
    if (U[A[i]] && U[B[i]]) cnt++;
  }
  return cnt;
}

int main() {
  INCANT;
  cin >> n >> m;
  rep(i, m) {
    cin >> A[i] >> B[i];
    A[i]--;B[i]--;
  }
  cin >> k;
  rep(i, k) {
    cin >> X[i][0] >> X[i][1];
    X[i][0]--;X[i][1]--;
  }

  int ans = 0;
  rep(i, (1<<k)) {
    unordered_map<int, bool> U;
    rep(bit, k) {
      if (i & (1<<bit)) U[X[bit][0]]=true;
      else U[X[bit][1]]=true;
    }
    ans = max(ans, calc(U));
  } 

  cout << ans << endl;

  return 0;
}