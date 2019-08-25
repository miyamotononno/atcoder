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
ll N, K;
ll A[2001];
ll B[2001];
ll C[2001];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  rep(i, N) cin >> A[i];

  rep(i, N-1){
    for (int j=i+1; j<N;j++){
      if (A[i] > A[j]) B[i]++;
    }
  }
  for (int i=1; i<N;i++){
    rep(j, i){
      if (A[i] > A[j]) C[i]++;
    }
  }

  ll q = ((K+1)*K)/2ll;
  ll q2 = ((K-1)*K)/2ll;
  q%=MOD;
  q2%=MOD;
  ll ans = 0ll;
  rep(i, N){
    B[i]=q*B[i];
    C[i]=q2*C[i];
    ans+=B[i]+C[i];
    ans%=MOD;
  }
  cout << ans << "\n";
  return 0;
}
