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
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
ll N, K;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  ll ans = 0;
  if (K==0){
    cout << N*N << "\n";
    return 0;
  }
  for (ll b=K+1; b<=N; b++){
    ll cnt = N/b*(b-K);
    cnt+=max(0ll, N%b-K+1);
    ans+=cnt;
  }

  cout << ans << "\n";
  return 0;
}