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
string S;

int lcs(string &s, string &t, int dp[100][100], int idx1, int idx2) {
  if (dp[idx1][idx2]>=0) return dp[idx1][idx2];
  if (idx1==s.size() || idx2==t.size()) return 0;
  int res =0;
  if (s[idx1]==t[idx2]) res=lcs(s,t, dp, idx1+1, idx2+1)+1;
  else {
    res = lcs(s, t, dp, idx1+1, idx2);
    res = max(res, lcs(s,t, dp, idx1, idx2+1));
    res = max(res, lcs(s,t, dp, idx1+1, idx2+1));
  }
  dp[idx1][idx2] = res;
  return res;
}

int calc(string &s, string &t) {
  int dp[100][100];
  rep(i, 100) rep(j, 100) dp[i][j] = -1;
  int ret = lcs(s, t, dp, 0,0);
  return N-ret*2;
}

int main() {
  INCANT;
  cin >> N;
  cin >> S;
  int MIN=N;
  for(int i=1; i<N; i++) {
    string s = S.substr(0, i);
    string t = S.substr(i);
    MIN=min(MIN, calc(s,t));
  }

  cout << MIN << "\n";
  return 0;
}