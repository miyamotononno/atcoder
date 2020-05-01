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
int N;
int A[3001];
int dp[3001][3]; //idx番目でup/down時の残りの個数

int dfs(int idx, int prev, int status) {
  if (idx==N) return 0;
  if (dp[idx][status]>=0) return dp[idx][status];
  int res = 0;
  res = dfs(idx+1, prev, status); // この回をカウントしない
  if (!status) {
    res = max(res, dfs(idx+1, A[idx], 2)+1);
    res = max(res, dfs(idx+1, A[idx], 1)+1);
  } else {
    if ((status == 2 && prev > A[idx]) || (status == 1 && prev < A[idx])){
      res = max(res, dfs(idx+1, A[idx], status==1?2:1)+1);
    }
  }
  dp[idx][status] = res;
  return res;
}

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >>  A[i];
  rep(i, N) {
    rep(j, 3) dp[i][j] = -1;
  }

  ll res = dfs(0, 0, 0);
  if (res<3) {
    cout << 0 << "\n";
    return 0;
  }
  cout << res << "\n";
  return 0;
}