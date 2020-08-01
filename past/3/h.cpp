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
const int INF = 2e9;
int N, L;
bool x[110000];
int t1,t2,t3;
int dp[110000]; // 地点iを越すまでの時刻

void act1(int i) {
  int b1 = x[i+1]?t3:0;
  dp[i+1] = min(dp[i+1], dp[i]+t1+b1);
}

void act2(int i) {
  int act2 = t1+t2;
  int b2 = x[i+2]?t3:0;
  dp[i+2] = min(dp[i+2], dp[i]+act2+b2);
  if (i==L-1) dp[i+1] = min(dp[i+1], dp[i]+act2/2);
}

void act3(int i) {
  int b4 = x[i+4]?t3:0;
  dp[i+4] = min(dp[i+4], dp[i]+t1+3*t2+b4);
  if (i>=L-3) dp[i+3] = min(dp[i+3], dp[i]+t1/2+(t2*5)/2);
  if (i>=L-2) dp[i+2] = min(dp[i+2], dp[i]+t1/2+(t2*3)/2);
  if (i>=L-1) dp[i+1] = min(dp[i+1], dp[i]+t1/2+t2/2);
}


int main() {
  INCANT;
  cin >> N >> L;
  int a;
  rep(i, N) {
    cin >> a;
    x[a]=true;
  }
  cin >> t1 >> t2 >> t3;
  fill(dp,dp+110000, INF);
  dp[0] = 0;
  rep(i, L+1) {
    act1(i);
    act2(i);
    act3(i);
  }
  cout << dp[L] << "\n";
  return 0;
}