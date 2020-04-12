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
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, A[100004];
int DP[100004];

ll dfs(int idx, int r, int b, int g) {
  if (idx==N) return 1;
  if (DP[idx]>=0) return DP[idx];
  ll ret=0ll;
  if (r==A[idx]) {
    ret += dfs(idx+1, r+1, b, g);
  }
  if (b==A[idx]) {
    ret += dfs(idx+1, r, b+1, g);
  }
  if (g==A[idx]) {
    ret += dfs(idx+1, r, b, g+1);
  }
  ret%=MOD;
  DP[idx] = ret;
  return ret;
}

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> A[i];
  rep(i, N) DP[i] = -1;
  cout << dfs(0, 0, 0, 0) << "\n";
  return 0;
}