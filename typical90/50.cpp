#include <iostream>
#include <vector>

using namespace std;
int N, L;
typedef long long ll;
const ll MOD = 1e9+7;

ll dp[100003];

int main() {
  cin >> N >> L;
  dp[0] = 1ll;
  for (int i=1; i<=N; i++) {
    dp[i] += dp[i-1];
    if (i-L>=0) dp[i] += dp[i-L];
    dp[i] %= MOD; 
  }
  cout << dp[N] << endl;
}