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
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
ll T, t[200002];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> T;
  rep(i, N) cin >> t[i];
  ll ans = 0ll;
  rep(i, N){
    if (i==N-1){
      ans+=T;
      break;
    }
    if (t[i+1]-t[i]>T){
      ans+=T;
    }else{
      ans+=t[i+1]-t[i];
    }
  }

  cout << ans << "\n";
  return 0;
}