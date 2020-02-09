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
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const ll INF = 1e18;
ll N;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  ll mn = INF;
  for (ll i=1; i*i<=N; i++) {
    if (N%i ==0) {
      mn = min(i+(N/i), mn);
    }
  }

  cout << mn - 2 << "\n";
  return 0;
}