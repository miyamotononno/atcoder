#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
int K;

const int maxK = 100003;
const ll MOD = 1e9+7;
ll dp[maxK];

ll calc(int rest) {
  if (rest==0) return 1ll;
  if (dp[rest]>=1) return dp[rest];
  ll ret = 0ll; 
  for (int i=1; i<=min(rest, 9); i++) { // 一個上の桁にi足す操作
    ret += calc(rest-i);
    ret %= MOD; 
  }
  dp[rest] = ret;
  return ret;
}

int main() {
  cin >> K;
  if (K%9!=0) {
    cout << 0 << endl;
    return 0;
  }

  cout << calc(K) << endl;

}