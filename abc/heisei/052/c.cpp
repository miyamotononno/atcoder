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
const ll MOD = 1000000007ll;
int N;
map< int, ll > factors;

void prime_factor(int n) {
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      factors[i]++;
      n /= i;
    }
  }
  if(n != 1) factors[n] += 1ll;
}

// 検証例

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep_down(i, N+1){
    if (i==0) continue;
    prime_factor(i);
  }
  ll ans = 1ll;
  for(auto p: factors){
    ans *= (p.second +1);
    ans%=MOD;
  }
  cout << ans << endl;
  return 0;
}