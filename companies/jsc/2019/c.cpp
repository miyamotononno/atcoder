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
int N;
string S;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  cin >> S;
  ll K=0;
  ll ans = 1ll;
  // Wは偶数回、Bは奇数回ひっくり返さないといけない。
  // もし自分が左側としてひっくり返すなら自分はK+1回ひっくり返される.
  // 逆に右側としてひっくり返すなら自分はK回ひっくり返される.
  rep(i, 2*N){
    if ((S[i]=='W')==(K%2==0)){
      ans*=K;
      ans%=MOD;
      K--;
      if (K<0) break;
    } else K++;
  }

  if (K !=0) {
    cout << 0 << "\n";
    return 0;
  }

  for(ll i=1; i<=N; i++){
    ans*=i;
    ans%=MOD;
  }

  cout << ans << "\n";
  return 0;
}