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
const int MOD = 2019;
int N; // 2*10e5
string S;
ll dp[200005];
ll dp2[200005]; // keta


void init() {
  dp2[0] = 1ll;
  rep(i, N) {
    if (i==0) continue;
    dp2[i] = (dp2[i-1]*10)%MOD;
  }
} 
int main() {
  INCANT;
  cin >> S;
  N = S.size();
  init();
  dp[N-1] = S[N-1]-'0';
  for(int i=N-1; i>=0; i--) {
    if (i==N-1) continue;
    int d = S[i]-'0';
    int keta = N-1 - i;
    dp[i] = (dp2[keta]*d+dp[i+1])%MOD;
  }
  ll SUM=0ll;
  rep(i, 2019) {
    ll tmp=0ll;
    rep(j, N) if (dp[j]==i) tmp++;
    if (i==0) SUM+=tmp*(tmp+1)/2;
    else SUM+=tmp*(tmp-1)/2;
  }
  cout << SUM << endl;
  return 0;
}