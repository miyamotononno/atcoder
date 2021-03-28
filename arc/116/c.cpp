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
const ll MOD = 998244353;
int n;
ll m;
ll A[200005]; // 1-mまでの残り個数を記録
ll dp[200005];

void calc() {
  rep(i, m+1) dp[i] = 1ll; 
  rep(i, n) {
    for (int j=1; j<=m; j++) {
      ll d=0ll; 
      for (int k=j; k<=m;k+=j) {
        d+=dp[k];
        d%=MOD;
      }
      dp[j]=d;
    }
  }
  cout << endl;
}

int main() {
  INCANT;
  cin >> n >> m;
  if (n==1) {
    cout << m << endl;
    return 0;
  }
  if (m==1) {
    cout << 1 << endl;
    return 0;
  }
  calc();
  cout << dp[1] << endl;

  
  return 0;
}