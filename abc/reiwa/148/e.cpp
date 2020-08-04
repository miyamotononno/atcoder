#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
ll N;
ll a2, a5;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  if (N%2!=0) {
    cout << 0 << "\n";
    return 0;
  }
  ll wari = 10ll;
  ll ans = 0ll;
  while(wari <= N) {
    ans+=N/wari;
    wari*=5ll;
  }
  cout << ans << "\n";
  return 0;
}