#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
int A1[101], A2[101], S1[101], S2[101];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> A1[i];
  rep(i, N) cin >> A2[i];

  rep(i, N){
    if (i==0){
      S1[i] = A1[i];
      continue;
    }
    S1[i] = S1[i-1]+A1[i];
  }

  rep_down(i, N){
    if (i==N-1){
      S2[i] = A2[i];
      continue;
    }
    S2[i] = S2[i+1]+A2[i];
  }
  int ans = 0;
  rep(i, N){
    ans = max(ans, S1[i]+S2[i]);
  }
  cout << ans << endl;
  return 0;
}